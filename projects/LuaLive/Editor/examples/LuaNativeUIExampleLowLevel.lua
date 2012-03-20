--[[
File: LuaNativeUIExampleLowLevel.lua
Author: Mikael Kindborg

Description:

Basic demo of NativeUI in Lua that uses low-level
syscalls to create and manage widgets.

This example uses global variables for the Widgets, to make
it possible to interactively experiment with the UI using
the LuaLive editor.

First press "Run program" in the editor to run all of the
code in this file. That will create the UI.

Then you can run code interactively. Here are some things
to try. Select a line of code, then press "Do selection".

mosync.maWidgetSetProperty(MessageLabel, mosync.MAW_LABEL_FONT_SIZE, "60")
mosync.maWidgetRemoveChild(MessageLabel)
mosync.maWidgetAddChild(MainLayout, MessageLabel)
mosync.maExit(0)
--]]

-- Widget size values as strings (the MAW_CONSTANT_* values
-- are integers and cannot be used with maWidgetSetProperty).
mosync.FILL_PARENT = ""..mosync.MAW_CONSTANT_FILL_AVAILABLE_SPACE
mosync.WRAP_CONTENT = ""..mosync.MAW_CONSTANT_WRAP_CONTENT

-- Create screen with widgets.
Screen = mosync.maWidgetCreate(mosync.MAW_SCREEN)

MainLayout = mosync.maWidgetCreate(mosync.MAW_VERTICAL_LAYOUT)
mosync.maWidgetSetProperty(MainLayout, mosync.MAW_WIDGET_WIDTH, mosync.FILL_PARENT)
mosync.maWidgetSetProperty(MainLayout, mosync.MAW_WIDGET_HEIGHT, mosync.FILL_PARENT)
mosync.maWidgetSetProperty(MainLayout, mosync.MAW_WIDGET_BACKGROUND_COLOR, "000000")
mosync.maWidgetAddChild(Screen, MainLayout)

MessageLabel = mosync.maWidgetCreate(mosync.MAW_LABEL)
mosync.maWidgetSetProperty(MessageLabel, mosync.MAW_WIDGET_WIDTH, mosync.FILL_PARENT)
mosync.maWidgetSetProperty(MessageLabel, mosync.MAW_WIDGET_HEIGHT, mosync.WRAP_CONTENT)
mosync.maWidgetSetProperty(MessageLabel, mosync.MAW_LABEL_FONT_SIZE, "36")
mosync.maWidgetSetProperty(MessageLabel, mosync.MAW_LABEL_FONT_COLOR, "AAAAAA")
mosync.maWidgetSetProperty(MessageLabel, mosync.MAW_LABEL_TEXT, "Demo of MoSync NativeUI")
mosync.maWidgetAddChild(MainLayout, MessageLabel)

ButtonSayHello = mosync.maWidgetCreate(mosync.MAW_BUTTON)
mosync.maWidgetSetProperty(ButtonSayHello, mosync.MAW_WIDGET_WIDTH, FILL_PARENT)
mosync.maWidgetSetProperty(ButtonSayHello, mosync.MAW_WIDGET_HEIGHT, WRAP_CONTENT)
mosync.maWidgetSetProperty(ButtonSayHello, mosync.MAW_BUTTON_TEXT_VERTICAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
mosync.maWidgetSetProperty(ButtonSayHello, mosync.MAW_BUTTON_TEXT_HORIZONTAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
mosync.maWidgetSetProperty(ButtonSayHello, mosync.MAW_BUTTON_FONT_SIZE, "24")
mosync.maWidgetSetProperty(ButtonSayHello, mosync.MAW_BUTTON_TEXT, "Say Hello")
mosync.maWidgetAddChild(MainLayout, ButtonSayHello)

ButtonSayHi = mosync.maWidgetCreate(mosync.MAW_BUTTON)
mosync.maWidgetSetProperty(ButtonSayHi, mosync.MAW_WIDGET_WIDTH, mosync.FILL_PARENT)
mosync.maWidgetSetProperty(ButtonSayHi, mosync.MAW_WIDGET_HEIGHT, mosync.WRAP_CONTENT)
mosync.maWidgetSetProperty(ButtonSayHi, mosync.MAW_BUTTON_TEXT_VERTICAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
mosync.maWidgetSetProperty(ButtonSayHi, mosync.MAW_BUTTON_TEXT_HORIZONTAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
mosync.maWidgetSetProperty(ButtonSayHi, mosync.MAW_BUTTON_FONT_SIZE, "24")
mosync.maWidgetSetProperty(ButtonSayHi, mosync.MAW_BUTTON_TEXT, "Say Hi")
mosync.maWidgetAddChild(MainLayout, ButtonSayHi)

-- Show screen.
mosync.maWidgetScreenShow(Screen)

-- Create a widget event listener.
mosync.EventMonitor:OnWidget(function(widgetEvent)
  if ButtonSayHello == mosync.SysWidgetEventGetHandle(widgetEvent) then
    mosync.maWidgetSetProperty(MessageLabel, mosync.MAW_LABEL_TEXT, "Hello World!")
  elseif ButtonSayHi == mosync.SysWidgetEventGetHandle(widgetEvent) then
    mosync.maWidgetSetProperty(MessageLabel, mosync.MAW_LABEL_TEXT, "Hi there!")
  end
end)
