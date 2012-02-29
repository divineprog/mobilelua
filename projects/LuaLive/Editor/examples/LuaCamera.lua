--[[
File: LuaCamera.lua
Author: Mikael Kindborg
Description: Demo of how to use the device camera.
Press "Run program" in the editor to run all of the
code in this file.

TODO: This program works very crappy.

--]]

Screen = mosync.NativeUI:CreateWidget
{
  type = "Screen"
}

MainLayout = mosync.NativeUI:CreateWidget 
{
  type = "VerticalLayout",
  parent = Screen,
  width = mosync.FILL_PARENT,
  height = mosync.FILL_PARENT,
  backgroundColor = "FF8800" 
}
 
CameraPreview = mosync.NativeUI:CreateWidget 
{
  type = mosync.MAW_CAMERA_PREVIEW,
  parent = MainLayout,
  width = 300,
  height = 300
}

ButtonSnapshot = mosync.NativeUI:CreateButton 
{
  parent = MainLayout,
  width = mosync.FILL_PARENT,
  height = mosync.WRAP_CONTENT,
  text = "Take picture",
  eventFun = function(widget, widgetEvent)
    TakePicture()
  end
}

mosync.NativeUI:ShowScreen(Screen)

function SetupCamera()
  --mosync.maCameraSetProperty(mosync.MA_CAMERA_IMAGE_FORMAT, mosync.MA_CAMERA_IMAGE_RAW)
  
--[[
-- This is implemented in the wrong way on Android.
-- It works, but in the wrong way.
  log("set format")
  local format = mosync.SysAlloc(8)
  mosync.SysBufferSetInt(format, 0, 270)
  mosync.SysBufferSetInt(format, 1, 270)
  mosync.maCameraFormat(0, format)
  mosync.SysFree(format)
  log("format is set")
  --]]
  mosync.maCameraSelect(0)

  mosync.maCameraSetPreview(CameraPreview:GetHandle())
  mosync.maCameraStart()
end

function TakePicture()

  log("TakePicture1")
  local picture = mosync.maCreatePlaceholder()
  mosync.maCameraSnapshot(0, picture)
  
  log("TakePicture2")
  --mosync.maCameraStart()
  RenderPicture(picture)
end

function RenderPicture(picture)
  log("RenderPicture1")

  --mosync.maWidgetScreenShow(mosync.MAW_CONSTANT_MOSYNC_SCREEN_HANDLE)
  
  local size = mosync.maGetDataSize(picture)
  log("data size "..size)

  log("RenderPicture2")
  local image = mosync.maCreatePlaceholder()
  mosync.maCreateImageFromData(image, picture, 0, size)

  log("RenderPicture3")
  mosync.maDrawImage(image, 0, 0)
  mosync.maUpdateScreen()
  
  mosync.maWidgetScreenShow(mosync.MAW_CONSTANT_MOSYNC_SCREEN_HANDLE)

  log("RenderPicture4")
  local imageWidth = mosync.EXTENT_X(mosync.maGetImageSize(image))
  local imageHeight = mosync.EXTENT_Y(mosync.maGetImageSize(image))
  log("Image size: "..imageWidth.." "..imageHeight)
  local pixels = mosync.SysAlloc(imageWidth * imageHeight * 4)
  local sourceRect = mosync.SysRectCreate()
  mosync.SysRectSetLeft(sourceRect, 0)
  mosync.SysRectSetTop(sourceRect, 0)
  mosync.SysRectSetWidth(sourceRect, imageWidth - 1)
  mosync.SysRectSetHeight(sourceRect, imageHeight - 1)

  log("RenderPicture5")
  mosync.maGetImageData(image, pixels, sourceRect, imageWidth)

  log("RenderPicture6")
  mosync.SysFree(pixels)
  mosync.SysFree(sourceRect)

  log("RenderPicture7")
  --[[
  local pixels = mosync.SysAlloc(size)
  mosync.maReadData(picture, pixels, 0, size)
  -- process pixels
  mosync.SysFree(pixels)
  --]]
  mosync.maDestroyObject(image)
  mosync.maDestroyObject(picture)
end

SetupCamera()

--maCameraStop()


