--[[
File: LuaCamera.lua
Author: Mikael Kindborg
Description: Demo of how to use the device camera.
Press "Run program" in the editor to run all of the
code in this file.

TODO: This program works very crappy.

--]]

Screen = NativeUI:CreateWidget
{
  type = "Screen"
}

MainLayout = NativeUI:CreateWidget 
{
  type = "VerticalLayout",
  parent = Screen,
  width = FILL_PARENT,
  height = FILL_PARENT,
  backgroundColor = "FF8800" 
}
 
CameraPreview = NativeUI:CreateWidget 
{
  type = MAW_CAMERA_PREVIEW,
  parent = MainLayout,
  width = 300,
  height = 300
}

ButtonSnapshot = NativeUI:CreateButton 
{
  parent = MainLayout,
  width = FILL_PARENT,
  height = WRAP_CONTENT,
  text = "Take picture",
  eventFun = function(widget, widgetEvent)
    TakePicture()
  end
}

NativeUI:ShowScreen(Screen)

function SetupCamera()
  --maCameraSetProperty(MA_CAMERA_IMAGE_FORMAT, MA_CAMERA_IMAGE_RAW)
  
--[[
-- This is implemented in the wrong way on Android.
-- It works, but in the wrong way.
  log("set format")
  local format = SysAlloc(8)
  SysBufferSetInt(format, 0, 270)
  SysBufferSetInt(format, 1, 270)
  maCameraFormat(0, format)
  SysFree(format)
  log("format is set")
  --]]
  maCameraSelect(0)

  maCameraSetPreview(CameraPreview:GetHandle())
  maCameraStart()
end

function TakePicture()

  log("TakePicture1")
  local picture = maCreatePlaceholder()
  maCameraSnapshot(0, picture)
  
  log("TakePicture2")
  --maCameraStart()
  RenderPicture(picture)
end

function RenderPicture(picture)
  log("RenderPicture1")

  --maWidgetScreenShow(MAW_CONSTANT_MOSYNC_SCREEN_HANDLE)
  
  local size = maGetDataSize(picture)
  log("data size "..size)

  log("RenderPicture2")
  local image = maCreatePlaceholder()
  maCreateImageFromData(image, picture, 0, size)
  

  log("RenderPicture3")
  maDrawImage(image, 0, 0)
  maUpdateScreen()
  
  maWidgetScreenShow(MAW_CONSTANT_MOSYNC_SCREEN_HANDLE)

  log("RenderPicture4")
  local imageWidth = EXTENT_X(maGetImageSize(image))
  local imageHeight = EXTENT_Y(maGetImageSize(image))
  log("Image size: "..imageWidth.." "..imageHeight)
  local pixels = SysAlloc(imageWidth * imageHeight * 4)
  local sourceRect = SysRectCreate()
  SysRectSetLeft(sourceRect, 0)
  SysRectSetTop(sourceRect, 0)
  SysRectSetWidth(sourceRect, imageWidth - 1)
  SysRectSetHeight(sourceRect, imageHeight - 1)

  log("RenderPicture5")
  maGetImageData(image, pixels, sourceRect, imageWidth)

  log("RenderPicture6")
  SysFree(pixels)
  SysFree(sourceRect)

  log("RenderPicture7")
  --[[
  local pixels = SysAlloc(size)
  maReadData(picture, pixels, 0, size)
  -- process pixels
  SysFree(pixels)
  --]]
  maDestroyObject(image)
  maDestroyObject(picture)
end

SetupCamera()

--maCameraStop()


