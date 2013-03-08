-- Experimental slide show program with a sketch of a widget system.

-- System objects
Color = {}
Rect = {}
Screen = {}
Widget = {}
Widget.Stack = {}
Widget.Card = {}
Widget.Image = {}

-- Color constructor.
Color.rgb = function(red, green, blue)
  local self = {}
  local _red = red
  local _green = green
  local _blue = blue

  self.getRed = function()
    return _red
  end

  self.getGreen = function()
    return _green
  end

  self.getBlue = function()
    return _blue
  end

  self.getColorValue = function()
    return (_blue) + (_green * 256) + (_red * 65536)
  end

  self.useMeForDrawing = function()
    --maSetColor(self.getColorValue())
    mosync.maSetColorRGB(_red, _green, _blue)
    return self
  end

  return self
end

-- Create some standard colors.
Color.white = Color.rgb(255, 255, 255)
Color.black = Color.rgb(0, 0, 0)
Color.red = Color.rgb(255, 0, 0)
Color.green = Color.rgb(0, 255, 0)
Color.blue = Color.rgb(0, 0, 255)
Color.yellow = Color.rgb(255, 255, 0)

Rect.create = function()

  local self = {}
  local _left = 0
  local _top = 0
  local _width = 0
  local _height = 0

  self.setLeft = function(left)
    _left = left
    return self
  end

  self.setTop = function(top)
    _top = top
    return self
  end

  self.setWidth = function(width)
    _width = width
    return self
  end

  self.setHeight = function(height)
    _height = height
    return self
  end

  self.setRight = function(right)
    self.setWidth(right - self.getLeft())
    return self
  end

  self.setBottom = function(bottom)
    self.setHeight(bottom - self.getTop())
    return self
  end

  self.setBounds = function(left, top, width, height)
    self.setLeft(left)
    self.setTop(top)
    self.setWidth(width)
    self.setHeight(height)
    return self
  end

  self.setCenterX = function(centerX)
    self.setLeft(centerX - (self.getWidth() / 2))
    return self
  end

  self.setCenterY = function(centerY)
    self.setTop(centerY - (self.getHeight() / 2))
    return self
  end

  self.getLeft = function()
    return _left
  end

  self.getTop = function()
    return _top
  end

  self.getWidth = function()
    return _width
  end

  self.getHeight = function()
    return _height
  end

  self.getRight = function()
    return self.getLeft() + self.getWidth()
  end

  self.getBottom = function()
    return self.getTop() + self.getHeight()
  end

  self.getCenterX = function()
    return (self.getLeft() + self.getWidth()) / 2
  end

  self.getCenterY = function()
    return (self.getTop() + self.getHeight()) / 2
  end

  self.copy = function()
    local theCopy = Rect.create()
    theCopy.setLeft(self.getLeft())
    theCopy.setTop(self.getTop())
    theCopy.setWidth(self.getWidth())
    theCopy.setHeight(self.getHeight())
    return theCopy
  end

  return self
end

-- Constructor that takes rectangle bounds parameters.
Rect.bounds = function(left, top, width, height)
  local self = Rect.create()
  self.setLeft(left)
  self.setTop(top)
  self.setWidth(width)
  self.setHeight(height)
  return self
end

-- Here we create the Screen object.
(function(self)

  local _screenRect
  local _mainWidget
  
  self.getWidth = function()
    return mosync.EXTENT_X(mosync.maGetScrSize())
  end
  
  self.getHeight = function()
    return mosync.EXTENT_Y(mosync.maGetScrSize())
  end

  self.setMainWidget = function(widget)
    _mainWidget = widget
  end

  self.redraw = function()
    _mainWidget.layoutAll(_screenRect)
    _mainWidget.drawAll()
    mosync.maUpdateScreen()
  end

  self.handleKeyEvent = function(funName, key)
    Widget.dispatchKeyEvent(_mainWidget, funName, key)
  end

  self.handleTouchEvent = function(funName, x, y)
    Widget.dispatchTouchEvent(_mainWidget, funName, x, y)
  end

  self.getRect = function()
    return _screenRect
  end

  -- Create the screen rectangle.
  _screenRect = Rect.bounds(
    0,
    0,
    self.getWidth(),
    self.getHeight())

  log("Screen object:")
  log("  left: " .. _screenRect.getLeft())
  log("  top: " .. _screenRect.getTop())
  log("  width: " .. _screenRect.getWidth())
  log("  height: " .. _screenRect.getHeight())
  
  return self
end)(Screen)

-- Common draw method for widgets.
Widget.draw = function(self)
  if nil ~= self.getImage() then
    mosync.maDrawImage(
      self.getImage(),
      self.getLeft(),
      self.getTop())
  else
    self.getColor().useMeForDrawing()
    mosync.maFillRect(
      self.getLeft(),
      self.getTop(),
      self.getWidth(),
      self.getHeight())
  end
  return self
end

Widget.intersects = function(self, other)
  if self.getLeft() >= other.getRight() then return false end
  if self.getRight() <= other.getLeft() then return false end
  if self.getTop() >= other.getBottom() then return false end
  if self.getBottom() <= other.getTop() then return false end
  return true
end

Widget.containsXY = function(self, x, y)
  if self.getLeft() >= x then return false end
  if self.getRight() <= x then return false end
  if self.getTop() >= y then return false end
  if self.getBottom() <= y then return false end
  return true
end

Widget.childrenDoFrontToBack = function(self, fun)
  for i,widget in ipairs(self.getChildren()) do
    fun(widget)
  end
  return self
end

Widget.childrenDoBackToFront = function(self, fun)
  local children = self.getChildren()
  -- Initialise i to the length of children, which is
  -- the index of the last element. Lua indexes
  -- start at one.
  local i = #children
  while i > 0 do
    fun(children[i])
    i = i - 1
  end
  return self
end

-- Let all widgets that have an event handler
-- handle the keypad event.
-- TODO: We have no focus handling, redesign this?
-- The funName param is a string.
Widget.dispatchKeyEvent = function(self, funName, key)
  -- Do I have an event handler?
  -- If so I handle the event.
  if self[funName] then
    self[funName](self, key)
  end

  -- Let my children also handle the event.
  for i,child in ipairs(self.getChildren()) do
    Widget.dispatchKeyEvent(child, funName, key)
  end
end

-- The innermost (deepest) widget that contains x,y and has
-- an event function will handle the event.
-- The funName param is a string.
Widget.dispatchTouchEvent = function(self, funName, x, y)
  -- Do I contain x, y?
  if Widget.containsXY(self, x, y) then
    -- First, allow children to handle the event.
    for i,child in ipairs(self.getChildren()) do
      if Widget.containsXY(child, x, y) then
        local eventHandled = Widget.dispatchTouchEvent(
          child,
          funName,
          x,
          y)
        if eventHandled then
          return true
        end
      end
    end
    -- No child handled the event. Now it is my turn.
    -- Do I have an event handler?
    if self[funName] then
      self[funName](self, x, y)
      return true
    end
  else
    return false
  end
end

-- Scale image to widget width and height.
-- Replaces original image with scaled image.
Widget.scaleImageToWidgetSize = function(self)
  Widget.scaleImage(
  self,
  self.getWidth(),
  self.getHeight())
end

-- Scale image. Replaces original image with scaled image.
Widget.scaleImage = function(self, width, height)
  local image = self.getImage()
  local scaledImage = mosync.maCreatePlaceholder()
  local success = mosync.SysImageScale(
    image,
    nil,
    scaledImage,
    width,
    height,
    mosync.SCALETYPE_BILINEAR)
    --mosync.SCALETYPE_NEAREST_NEIGHBOUR)
  if 1 == success then
    self.setImage(scaledImage)
    mosync.maDestroyPlaceholder(image)
  end
end

-- Widget constructor.
Widget.create = function()

  -- These variables are totally private.
  local self = {}
  local _prototype = Widget
  local _parent = nil
  local _children = {}
  local _color = Color.white
  local _image = nil
  local _rect = Rect.create()

  -- Destructor. Must call explicitly to release image.
  -- We need to release the image since it is allocated
  -- on the C side.
  self.destroy = function()
    if self.getImage() then
      mosync.maDestroyPlaceholder(self.getImage())
      self.setImage(nil)
    end
  end

  self.setParent = function(parent)
    _parent = parent
    return self
  end

  self.getParent = function()
    return _parent
  end

  self.getChildren = function()
    return _children
  end

  self.addChild = function(child)
    child.setParent(self)
    table.insert(_children, child)
    return self
  end

  self.removeChild = function(child)
    local indexToRemove = 0
    local children = self.getChildren()
    -- Find index of child widget.
    for i,widget in ipairs(children) do
      if widget == child then
        indexToRemove = i
        break
      end
    end
    if 0 ~= indexToRemove then
      table.remove(children, indexToRemove)
    end
    return self
  end

  self.setColor = function(color)
    _color = color
    return self
  end

  self.setImage = function(image)
    _image = image
    return self
  end

  self.scaleImage = function()
    _prototype.scaleImage(self)
    return self
  end

  self.setRect = function(rect)
    _rect = rect
    return self
  end

  self.setLeft = function(left)
    _rect.setLeft(left)
    return self
  end

  self.setTop = function(top)
    _rect.setTop(top)
    return self
  end

  self.setWidth = function(width)
    _rect.setWidth(width)
    return self
  end

  self.setHeight = function(height)
    _rect.setHeight(height)
    return self
  end

  self.setRight = function(right)
    _rect.setRight(right)
    return self
  end

  self.setBottom = function(bottom)
    _rect.setBottom(bottom)
    return self
  end

  self.setBounds = function(left, top, width, height)
    _rect.setBounds(left, top, width, height)
    return self
  end

  self.setCenterX = function(centerX)
    _rect.setCenterX(centerX)
    return self
  end

  self.setCenterY = function(centerY)
    _rect.setCenterY(centerY)
    return self
  end

  self.getColor = function()
    return _color
  end

  self.getImage = function()
    return _image
  end

  self.getRect = function(rect)
    return _rect
  end

  self.getLeft = function()
    return _rect.getLeft()
  end

  self.getTop = function()
    return _rect.getTop()
  end

  self.getWidth = function()
    return _rect.getWidth()
  end

  self.getHeight = function()
    return _rect.getHeight()
  end

  self.getRight = function()
    return _rect.getRight()
  end

  self.getBottom = function()
    return _rect.getBottom()
  end

  self.getCenterX = function()
    return _rect.getCenterX()
  end

  self.getCenterY = function()
    return _rect.getCenterY()
  end

  self.intersects = function(other)
    return _prototype.intersects(self, other)
  end

  self.containsXY = function(x, y)
    return _prototype.containsXY(self, other)
  end

  self.redraw = function(rect)
    self.layoutAll(rect)
    self.drawAll()
  end

  self.layoutAll = function(rect)
    self.layout(rect)
    self.layoutChildren(rect)
  end

  -- TODO: Fix layout so that rect
  -- is calculated in a useful way.
  -- Now rect is always the whole screen.
  self.layoutChildren = function(rect)
    _prototype.childrenDoFrontToBack(
      self,
      function(child)
        child.layoutAll(rect)
      end)
  end

  self.drawAll = function()
    self.draw()
    self.drawChildren()
  end

  self.drawChildren = function()
    _prototype.childrenDoBackToFront(
      self,
      function(child)
        child.drawAll()
      end)
  end

  self.layout = function(rect)
    if self.layoutFun then
      self.layoutFun(self, rect)
    end
    return self
  end

  self.draw = function()
    if self.drawFun then
      self.drawFun(self)
    end
    return self
  end

  self.onLayout = function(fun)
    self.layoutFun = fun
    return self
  end

  self.onDraw = function(fun)
    self.drawFun = fun
    return self
  end

  self.onKeyDown = function(fun)
    self.keyDownFun = fun
    return self
  end

  self.onKeyUp = function(fun)
    self.keyUpFun = fun
    return self
  end

  self.onTouchDown = function(fun)
    self.touchDownFun = fun
    return self
  end

  self.onTouchUp = function(fun)
    self.touchUpFun = fun
    return self
  end

  self.onTouchDrag = function(fun)
    self.touchDragFun = fun
    return self
  end

  -- Set standard draw and layout functions.
  self.onDraw(Widget.draw)
  self.onLayout(Widget.layout)

  return self
end

Widget.Stack.create = function()

  local self = Widget.create()
  local _currentCardIndex = 1

  self.addCard = function(card)
    card.setRect(self.getRect().copy())
    self.addChild(card)
    return self
  end

  self.showNextCard = function()
    self.hideCurrentCard()
    local cards = self.getChildren()
    _currentCardIndex = _currentCardIndex + 1
    if _currentCardIndex > #cards then
      _currentCardIndex = 1
    end
    Screen.redraw()
    return self
  end

  self.showPreviousCard = function()
    self.hideCurrentCard()
    local cards = self.getChildren()
    _currentCardIndex = _currentCardIndex - 1
    if _currentCardIndex < 1 then
      _currentCardIndex = #cards
    end
    Screen.redraw()
    return self
  end

  -- Index starts at 1
  self.showCard = function(cardIndex)
    self.hideCurrentCard()
    _currentCardIndex = cardIndex
    Screen.redraw()
    return self
  end

  self.hideCurrentCard = function()
    local cards = self.getChildren()
    local card = cards[_currentCardIndex]
    if nil ~= card then
      card.hide()
    end
    return self
  end

  -- Draw visible card.
  self.draw = function()
    local cards = self.getChildren()
    local card = cards[_currentCardIndex]
    if nil ~= card then
      card.draw()
    end
    return self
  end

  -- Block drawing of children.
  self.drawAll = function()
    self.draw()
  end

  -- Flip left/right depending on which
  -- side of the card you click.
  self.onTouchDown(function(self, x, y)
    if x < self.getCenterX() then
      self.showPreviousCard()
    else
      self.showNextCard()
    end
  end)

  -- TODO: Add layout method on Stack to make children
  -- same size as parents.

  return self
end

Widget.Card.create = function()

  local self = Widget.create()

  local _imageResourceId = 0

  self.setImageResourceId = function(id)
    _imageResourceId = id
  end

  -- Deallocate image.
  self.hide = function()
    if self.getImage() then
      mosync.maDestroyPlaceholder(self.getImage())
      self.setImage(nil)
    end
  end

  -- Save 'superclass' draw method.
  self.superDraw = self.draw

  self.draw = function()
    if nil == self.getImage() then
      local image = LoadImageFromBinaryResource(_imageResourceId)
      if image then
        self.setImage(image)
        -- Do we need to shrink the image?
        -- If image is smaller than the screen, we scale the image.
        local width = mosync.EXTENT_X(mosync.maGetImageSize(image))
        local height = mosync.EXTENT_Y(mosync.maGetImageSize(image))
        local screenWidth = mosync.EXTENT_X(mosync.maGetScrSize())
        local screenHeight = mosync.EXTENT_Y(mosync.maGetScrSize())
        if width > screenWidth or height > screenHeight then
          local scaledWidth
          local scaledHeight
          local scaleFactorW = screenWidth / width
          local scaleFactorH = screenHeight / height
          if scaleFactorW < scaleFactorH then
            -- Use width ratio as scale factor.
            scaledWidth = width * scaleFactorW
            scaledHeight = height * scaleFactorW
          else
            -- Use height ratio as scale factor.
            scaledWidth = width * scaleFactorH
            scaledHeight = height * scaleFactorH
          end
          Widget.scaleImage(self, scaledWidth, scaledHeight)
        end
      end
    end
    if nil == self.getImage() then
      self.superDraw()
    else
      self.drawCard()
    end
  end

  self.drawCard = function()
    local image = self.getImage()
    local width = mosync.EXTENT_X(mosync.maGetImageSize(image))
    local height = mosync.EXTENT_Y(mosync.maGetImageSize(image))
    local screenWidth = mosync.EXTENT_X(mosync.maGetScrSize())
    local screenHeight = mosync.EXTENT_Y(mosync.maGetScrSize())

    -- Is image smaller than the screen? Then center and fill with
    -- background color.
    if width < screenWidth or height < screenHeight then
      -- Fill background.
      --local color = ImageGetPixelValue(image, 2, 2)
      --maSetColor(color)
      mosync.maSetColor(0x000000)
      mosync.maFillRect(0, 0, screenWidth, screenHeight)
      -- Draw image.
      local x = self.getLeft() + ((screenWidth - width) / 2)
      local y = self.getTop() + ((screenHeight - height) / 2)
      mosync.maDrawImage(image, x, y)
    else
      -- Image fits (hopefully), draw image.
      mosync.maDrawImage(
        image,
        self.getLeft(),
        self.getTop())
    end
    return self
  end

  return self
end

function OnKeyDown(key)
  if mosync.MAK_BACK == key or mosync.MAK_0 == key then
    mosync.maExit(0)
  else
    Screen.handleKeyEvent('keyDownFun', key)
  end
end

function OnKeyUp(key)
  Screen.handleKeyEvent('keyUpFun', key)
end

function OnTouchDown(x, y)
  Screen.handleTouchEvent('touchDownFun', x, y)
end

function OnTouchUp(x, y)
  Screen.handleTouchEvent('touchUpFun', x, y)
end

function OnTouchDrag(x, y)
  Screen.handleTouchEvent('touchDragFun', x, y)
end

function ImageGetPixelValue(image, x, y)
  local buf = mosync.SysAlloc(4)
  local rect = mosync.SysRectCreate()
  local imageWidth = mosync.EXTENT_X(mosync.maGetImageSize(image))
  mosync.SysRectSetLeft(rect, x)
  mosync.SysRectSetTop(rect, y)
  mosync.SysRectSetWidth(rect, 1)
  mosync.SysRectSetHeight(rect, 1)
  mosync.maGetImageData(image, buf, rect, imageWidth)
  mosync.SysFree(rect)
  local pixelValue = mosync.SysBufferGetInt(buf, 0)
  mosync.SysFree(buf)
  return pixelValue
end

-- Create an image from a data resource.
function LoadImageFromBinaryResource(resourceId)
  local image = mosync.maCreatePlaceholder()
  local result = mosync.maCreateImageFromData(
    image,
    resourceId,
    0,
    mosync.maGetDataSize(resourceId))
  if mosync.RES_OK == result then
    return image
  else
    return nil
  end
end

function CreateCard(stack, resourceId)
  local card = Widget.Card.create()
   stack.addCard(card)
   card.setImageResourceId(resourceId)
  --local image = LoadImageFromBinaryResource(resourceId)
  --if image then
  --  card.setImage(image).scaleImage()
  --end
end

function OnInitApp()
  local stack = Widget.Stack.create()
  stack.setRect(Screen.getRect().copy())
  Screen.setMainWidget(stack)
  CreateCard(stack, 1)
  CreateCard(stack, 2)
  CreateCard(stack, 3)
  CreateCard(stack, 4)
  CreateCard(stack, 5)
  CreateCard(stack, 6)
  stack.showCard(1)
end

function Main()
  mosync.EventMonitor:OnKeyDown(OnKeyDown)
  mosync.EventMonitor:OnKeyUp(OnKeyUp)
  mosync.EventMonitor:OnTouchDown(OnTouchDown)
  mosync.EventMonitor:OnTouchUp(OnTouchUp)
  mosync.EventMonitor:OnTouchDrag(OnTouchDrag)
  OnInitApp()
end

Main()
