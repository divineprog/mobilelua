--[[
 * Copyright (c) 2013 MoSync AB
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
--]]

function CreateGame()

	-- These variables are totally private.
	local self = {}
	local spriteTable = {}
	local imageTable = {}
	local backgroundColor = 0xFFFFFF
	local pointerX = 0
	local pointerY = 0
	local screenWidth = mosync.Screen:Width()
	local screenHeight = mosync.Screen:Height()
	local virtualScreenWidth = 0
	local virtualScreenHeight = 0
  local mainSprite
	
	local function processSprites()
		for i,sprite in ipairs(spriteTable) do 
			sprite.onClockTick(
				pointerX, 
				pointerY, 
				screenWidth, 
				screenHeight)
		end
		return self
	end
	
	self.addSprite = function(sprite)
		table.insert(spriteTable, sprite)
		return self
	end
	
	self.setVirtualScreenSize = function(w, h)
		virtualScreenWidth = w
		virtualScreenHeight = h
	end
	
	self.transformPoint = function(x, y)
		if 0 ~= virtualScreenWidth and 0 ~= virtualScreenHeight then
			return 
				((screenWidth / virtualScreenWidth) * x),
				((screenHeight / virtualScreenHeight) * y)
		else
			return x, y
		end
	end
	
	self.onClockTick = function()
		processSprites()
		self.draw()
		return self
	end
	
	self.onTouchDown = function(x, y)
		pointerX = x
		pointerY = y
		return self
	end
	
	self.onTouchDrag = function(x, y)
		pointerX = x
		pointerY = y
		return self
	end
	
	self.processCollisionsForSprite = function(sprite)
		-- TODO: Write code.
		return self
	end
	
	self.draw = function()
		self.drawBackground()
		self.drawSprites()
		mosync.maUpdateScreen()
		return self
	end
	
	self.drawSprites = function()
		for i,sprite in ipairs(spriteTable) do 
			sprite.draw()
		end
		return self
	end
	
	self.setBackgroundColor = function(red, green, blue)
		backgroundColor = (blue) + (green * 256) + (red * 65536)
		return self
	end
	
	self.drawBackground = function()
		mosync.maSetColor(backgroundColor)
		mosync.maFillRect(0, 0, screenWidth, screenHeight)
		return self
	end
	
	self.createSprite = function()
		local sprite = CreateSprite(self)
		self.addSprite(sprite)
		return sprite
	end
  
  self.setMainSprite = function(sprite)
    mainSprite = sprite
  end
  
  local delta = 20
  
  self.moveMainSpriteLeft = function()
    mainSprite.setLeft(mainSprite.getLeft() - delta)
	end
  
  self.moveMainSpriteRight = function()
    mainSprite.setLeft(mainSprite.getLeft() + delta)
	end
  
  self.moveMainSpriteUp = function()
    mainSprite.setTop(mainSprite.getTop() - delta)
	end
  
  self.moveMainSpriteDown = function()
    mainSprite.setTop(mainSprite.getTop() + delta)
	end

	---[[
	self.downloadImage = function(url, fun)
		DownloadImage(
			url,
			function(theImage)
				fun(theImage)
			end)
		return self
	end
	--]]
	
	--[[
	self.downloadImage = function(url, fun)
		-- Is the image in the cache?
		local image = imageTable[url]
		if nil ~= image then
			-- Yes, call callback function with image.
			fun(image)
		else
			-- No, cache if not nil and then call callback 
			-- function with image.
			DownloadImage(
				url,
				function(theImage)
					if (nil ~= theImage) then
						imageTable[url] = theImage
					end
					fun(theImage)
				end)
		end
		
		return self
	end
	--]]
	
	return self
end

function CreateSprite(game)

	-- These variables are totally private.
	local self = {}
	local image = nil
	local left = 0
	local top = 0
	local width = 0
	local height = 0
	local shouldScale = false
	local shouldFollowPointerX = false
	local shouldFollowPointerY = false
	local speedX = 0
	local speedY = 0
	local oldPointerX = 0
	local oldPointerY = 0
	local spriteType = ""
	local eatTable = {}
	local color = { 255, 200, 200 }
	
	-- Scale my image to my width and height.
	-- This function is totally private.
	local function scaleImage()
		local scaledImage = mosync.maCreatePlaceholder()
		local success = mosync.maImageScale(
			image, 
			nil, 
			scaledImage, 
			width, 
			height, 
			mosync.SCALETYPE_BILINEAR)
		if 1 == success then
			mosync.maDestroyObject(image)
			image = scaledImage
		end
	end
	
	local function handleFollowPointer(pointerX, pointerY)
		-- Here I only move if the pointer has moved,
		-- to allow me to also move by me speed.
		if shouldFollowPointerX then
			if pointerX ~= oldPointerX then
				self.setCenterX(pointerX)
				oldPointerX = pointerX
			end
		end
		if shouldFollowPointerY then
			if pointerY ~= oldPointerY then
				self.setCenterY(pointerY)
				oldPointerY = pointerY
			end
		end
	end
	
	local function handleMotion(screenWidth, screenHeight)
		-- Move me.
		if nil ~= speedX then
			left = left + speedX
		end
		if nil ~= speedY then
			top = top + speedY
		end
		
		-- Wrap around at edges.
		if left + width < 0 then
			left = screenWidth
		elseif left > screenWidth then
			left = -width
		end
		if top + height < 0 then
			top = screenHeight
		elseif top > screenHeight then
			top = -height
		end
	end
	
	self.setImage = function(imageHandle)
		image = imageHandle 
		width = mosync.EXTENT_X(mosync.maGetImageSize(image))
		height = mosync.EXTENT_Y(mosync.maGetImageSize(image))
		return self
	end
	
	self.setImageURL = function(theUrl)
		game.downloadImage(
			theUrl, 
			function(theImage)
				-- Set my image.
				image = theImage 
				if nil == image then
					Log("Image download failed")
				else
					if shouldScale and width ~= 0 and height ~= 0 then
						-- Scale me if width and height are different from zero.
						scaleImage()
					else
						-- Set my width and height if I should not scale.
						width = mosync.EXTENT_X(mosync.maGetImageSize(image))
						height = mosync.EXTENT_Y(mosync.maGetImageSize(image))
					end
				end
			end)
		return self
	end
	
	self.setSize = function(theWidth, theHeight)
		-- Set my width and height.
		width = theWidth
		height = theHeight
		
		--  I will now scale to this size.
		shouldScale = true
		
		-- If my image is downloaded, then I scale it.
		if nil ~= image then
			scaleImage()
		end
		
		return self
	end
	
	self.setPosition = function(theLeft, theTop)
		local x, y = Game.transformPoint(theLeft, theTop)
		self.setLeft(x)
		self.setTop(y)
		return self
	end
	
	self.setCenter = function(theCenterX, theCenterY)
		self.setCenterX(theCenterX)
		self.setCenterY(theCenterY)
		return self
	end
	
	self.setLeft = function(theLeft)
		left = theLeft
		return self
	end
	
	self.setTop = function(theTop)
		top = theTop
		return self
	end
	
	self.setCenterX = function(theCenterX)
		left = theCenterX - (width / 2)
		return self
	end
	
	self.setCenterY = function(theCenterY)
		top = theCenterY - (height / 2)
		return self
	end
	
	self.setSpeed = function(theSpeedX, theSpeedY)
		speedX = theSpeedX
		speedY = theSpeedY
		return self
	end
	
	self.setSpeedX = function(theSpeedX)
		speedX = theSpeedX
		return self
	end
	
	self.setSpeedY = function(theSpeedY)
		speedY = theSpeedY
		return self
	end
	
	self.getLeft = function()
		return left
	end
	
	self.getRight = function()
		return left + width
	end
	
	self.getTop = function()
		return top
	end
	
	self.getBottom = function()
		return top + height
	end
	
	self.getWidth = function()
		return width
	end
	
	self.getHeight = function()
		return height
	end
	
	self.intersects = function(other)
		if self.getLeft() >= other.getRight() then return false end
		if self.getRight() <= other.getLeft() then return false end
		if self.getTop() >= other.getBottom() then return false end
		if self.getBottom() <= other.getTop() then return false end
		return true
	end
	
	self.contains = function(x, y)
		if self.getLeft() >= x then return false end
		if self.getRight() <= x then return false end
		if self.getTop() >= y then return false end
		if self.getBottom() <= y then return false end
		return true
	end
	
	self.draw = function()
		if nil ~= image then
			mosync.maDrawImage(image, left, top)
		else
			SetColor(color[1], color[2], color[3])
			FillRect(left, top, width, height)
		end
		return self
	end
	
	self.followPointerX = function()
		shouldFollowPointerX = true
		return self
	end
	
	self.followPointerY = function()
		shouldFollowPointerY = true
		return self
	end
	
	self.eatOthers = function()
		shouldEatOthers = true
	end
	
	self.eat = function(theSpriteType)
		eatTable[theSpriteType] = true
	end
	
	self.dontEat = function(theSpriteType)
		eatTable[theSpriteType] = false
	end
	
	self.setKeyDownFunction = function(theFunction)
		keyDownFunction = theFunction
		return self
	end
	
	self.setKeyUpFunction = function(theFunction)
		keyUpFunction = theFunction
		return self
	end
	
	self.setTouchDownFunction = function(theFunction)
		touchDownFunction = theFunction
		return self
	end
	
	self.setTouchUpFunction = function(theFunction)
		touchUpFunction = theFunction
		return self
	end
	
	self.onClockTick = function(pointerX, pointerY, screenWidth, screenHeight)
		handleFollowPointer(pointerX, pointerY)
		handleMotion(screenWidth, screenHeight)
		return self
	end
	
	return self
end

function OnClockTick()
	Game.onClockTick()
end 

function OnKeyDown(key)
  log("OnKeyDown " .. key)
	if mosync.MAK_BACK == key or mosync.MAK_0 == key then
		mosync.maExit(0)
	elseif mosync.MAK_4 == key then
    Game.moveMainSpriteLeft()
	elseif mosync.MAK_6 == key then
    Game.moveMainSpriteRight()
	elseif mosync.MAK_2 == key then
    Game.moveMainSpriteUp()
	elseif mosync.MAK_8 == key then
    Game.moveMainSpriteDown()
  end
end

function OnTouchDown(x, y)
	Game.onTouchDown(x, y)
end

function OnTouchDrag(x, y)
	Game.onTouchDrag(x, y)
end

function Main()
	-- Global instance of the game object.
	Game = CreateGame()
    
  -- Create game objects
	OnInitGame()
  
  -- Create event handlers.
  mosync.EventMonitor:OnTouchDown(OnTouchDown)
  mosync.EventMonitor:OnTouchDrag(OnTouchDrag)
  mosync.EventMonitor:OnKeyDown(OnKeyDown)
    
  -- Start timer
  mosync.EventMonitor:SetTimerFun(50, OnClockTick) 
end

-- Call Main to start program.
Main()

--[[
function OnInitGameNetworkTest1()
	Game.setBackgroundColor(34, 136, 255)
	local sprite = Game.createSprite()
	--sprite.setImageURL("http://comikit.se/MagicWords/Actors/SpriteFaewynBalloons.png")
	sprite.setImage(4)
	sprite.setPosition(20,50)
	sprite.followPointerX()
	sprite.followPointerY()
end

function OnInitGameNetworkTest2()
	Game.setBackgroundColor(34, 136, 255)
	Game.createSprite()
		.setImageURL("http://comikit.se/MagicWords/Actors/SpriteRubyHeart.png")
		.setPosition(90,70)
	Game.createSprite()
		.setImageURL("http://comikit.se/MagicWords/Actors/SpriteRubyHeart.png")
		.setPosition(40,300)
	Game.createSprite()
		.setImageURL("http://comikit.se/MagicWords/Actors/SpriteRubyHeart.png")
		.setPosition(200,250)
	Game.createSprite()
		.setImageURL("http://comikit.se/MagicWords/Actors/SpriteRubyHeart.png")
		.setPosition(500,400)
	Game.createSprite()
		.setImageURL("http://comikit.se/MagicWords/Actors/SpriteGhost.png")
		.setPosition(300,100)
		.setSpeed(3,0)
		.followPointerX()
	Game.createSprite()
		.setImageURL("http://comikit.se/MagicWords/Actors/SpriteBat.png")
		.setPosition(0,250)
		.setSpeed(5,-1)
	Game.createSprite()
		.setImageURL("http://comikit.se/MagicWords/Actors/SpriteFaewynBalloons.png")
		.setPosition(100,100)
		.setSize(411, 310)
		.followPointerX()
		.followPointerY()
	Game.createSprite()
		.setImageURL("http://comikit.se/MagicWords/Actors/SpriteBat.png")
		.setPosition(0,100)
		.setSpeed(7,0)
end

function OnInitGame()
  -- Resource ids for images.
	local HEART = 1
	local GHOST = 2
	local BAT = 3
	local FAEWYN = 4
  
  -- Set virtual screen size and background color.
	Game.setVirtualScreenSize(240,320)
	Game.setBackgroundColor(34, 136, 255)
  
  -- Create sprites.
	Game.createSprite()
    .setImage(HEART)
    .setPosition(90,20)
	Game.createSprite()
    .setImage(HEART)
    .setPosition(20,230)
	Game.createSprite()
    .setImage(HEART)
    .setPosition(180,250)
	Game.createSprite()
    .setImage(HEART)
    .setPosition(120,140)
	Game.createSprite()
    .setImage(GHOST)
    .setPosition(0,100)
		.setSpeed(3,0)
    .followPointerX()
	Game.createSprite()
    .setImage(BAT)
    .setPosition(0,250)
		.setSpeed(5,-1)
	local sprite = Game.createSprite()
    .setImage(FAEWYN)
    .setPosition(50,100)
		.followPointerX()
    .followPointerY()
  Game.setMainSprite(sprite)
	Game.createSprite()
    .setImage(BAT)
    .setPosition(0,70)
		.setSpeed(7,0)
end
--]]
