--[[
File: LuaNativeUIExample.lua
Author: Mikael Kindborg
Description: Demo that uses an experimental Lua UI library 
to create a NativeUI. The object NativeUI is defined in
file: projects/common/LuaLib.lua

Here are some things to try in the LuaLive editor. 

First press "Run program" in the editor to run all of the
code in this file. That will create the UI.

Then select a line of code below and press "Do selection".

MessageLabel:SetProp(MAW_LABEL_FONT_SIZE, "60")
maWidgetRemoveChild(MessageLabel.GetHandle())
maWidgetAddChild(MainLayout.GetHandle(), MessageLabel.GetHandle())
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

MessageLabel = NativeUI:CreateWidget 
{
  type = "Label",
  parent = MainLayout,
  width = FILL_PARENT,
  height = WRAP_CONTENT,
  fontSize = "36",
  fontColor = "FFFFFF",
  text = "Demo of MoSync NativeUI" 
}

ButtonSayHello = NativeUI:CreateButton 
{
  parent = MainLayout,
  width = FILL_PARENT,
  height = WRAP_CONTENT,
  text = "Say Hello",
  eventFun = function(widget, widgetEvent)
    MessageLabel:SetProp("text", "Hello World!")
  end
}

ButtonSayHi = NativeUI:CreateButton 
{
  parent = MainLayout,
  width = FILL_PARENT,
  height = WRAP_CONTENT,
  text = "Say Hi",
  eventFun = function(widget, widgetEvent)
    MessageLabel:SetProp("text", "Hi there!")
  end
}

NativeUI:ShowScreen(Screen)
