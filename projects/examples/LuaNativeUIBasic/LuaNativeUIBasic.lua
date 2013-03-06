--[[
 * Copyright (c) 2011 MoSync AB
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

--[[
File: LuaNativeUIBasic.lua
Author: Mikael Kindborg

Simple NativeUI demo in Lua. Uses MoSync API directly.
]]

function CreateUI()
  -- Create screen with widgets.
  local screen = mosync.maWidgetCreate(mosync.MAW_SCREEN)

  -- Create main layout.
  local layout = mosync.maWidgetCreate(mosync.MAW_VERTICAL_LAYOUT)
  mosync.maWidgetSetProperty(
    layout,
    mosync.MAW_WIDGET_WIDTH,
    mosync.FILL_PARENT)
  mosync.maWidgetSetProperty(
    layout,
    mosync.MAW_WIDGET_HEIGHT,
    mosync.FILL_PARENT);
  mosync.maWidgetSetProperty(
    layout,
    mosync.MAW_WIDGET_BACKGROUND_COLOR,
    "0x000000")
  mosync.maWidgetAddChild(screen, layout)
  
  -- Title label.
  local label = mosync.maWidgetCreate(mosync.MAW_LABEL)
  mosync.maWidgetSetProperty(label, mosync.MAW_WIDGET_WIDTH, mosync.FILL_PARENT)
  mosync.maWidgetSetProperty(label, mosync.MAW_WIDGET_HEIGHT, mosync.WRAP_CONTENT)
  mosync.maWidgetSetProperty(label, mosync.MAW_BUTTON_TEXT_VERTICAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
  mosync.maWidgetSetProperty(label, mosync.MAW_BUTTON_TEXT_HORIZONTAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
  mosync.maWidgetSetProperty(label, mosync.MAW_BUTTON_FONT_SIZE, "36")
  mosync.maWidgetSetProperty(label, mosync.MAW_BUTTON_FONT_COLOR, "0xFFFFFF")
  mosync.maWidgetSetProperty(label, mosync.MAW_BUTTON_TEXT, "My ToDo List")
  mosync.maWidgetAddChild(layout, label)

  -- Edit box to input text.
  local editbox = mosync.maWidgetCreate(mosync.MAW_EDIT_BOX)
  mosync.maWidgetSetProperty(editbox, mosync.MAW_WIDGET_WIDTH, mosync.FILL_PARENT)
  mosync.maWidgetSetProperty(editbox, mosync.MAW_WIDGET_HEIGHT, mosync.WRAP_CONTENT)
  mosync.maWidgetAddChild(layout, editbox)
  
  -- Button to add text.
  local button = mosync.maWidgetCreate(mosync.MAW_BUTTON)
  mosync.maWidgetSetProperty(button, mosync.MAW_WIDGET_WIDTH, mosync.FILL_PARENT)
  mosync.maWidgetSetProperty(button, mosync.MAW_WIDGET_HEIGHT, mosync.WRAP_CONTENT)
  mosync.maWidgetSetProperty(button, mosync.MAW_BUTTON_TEXT_VERTICAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
  mosync.maWidgetSetProperty(button, mosync.MAW_BUTTON_TEXT_HORIZONTAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
  mosync.maWidgetSetProperty(button, mosync.MAW_BUTTON_FONT_SIZE, "24")
  mosync.maWidgetSetProperty(button, mosync.MAW_BUTTON_FONT_COLOR, "0xFFFFFF")
  mosync.maWidgetSetProperty(button, mosync.MAW_BUTTON_TEXT, "Add Item")
  mosync.maWidgetAddChild(layout, button)
  
  -- List with items.
  local list = mosync.maWidgetCreate(mosync.MAW_LIST_VIEW)
  mosync.maWidgetSetProperty(list, mosync.MAW_WIDGET_WIDTH, mosync.FILL_PARENT)
  mosync.maWidgetSetProperty(list, mosync.MAW_WIDGET_HEIGHT, mosync.FILL_PARENT)
  mosync.maWidgetSetProperty(list, mosync.MAW_BUTTON_FONT_SIZE, "24")
  mosync.maWidgetSetProperty(list, mosync.MAW_WIDGET_BACKGROUND_COLOR, "0x000000")
  mosync.maWidgetAddChild(layout, list)
  
  -- Time to show screen.
  mosync.maWidgetScreenShow(screen)

  -- Table (array) that holds list items so that we can access them.
  local items = {}
  
  -- Create a widget event listener.
  mosync.EventMonitor:OnWidget(function(widgetEvent)
    if button == mosync.SysWidgetEventGetHandle(widgetEvent) then
      -- Button was clicked, add item to list.
      local buffer = mosync.SysAlloc(256)
      mosync.maWidgetGetProperty(editbox, "text", buffer, 256);
      local text = mosync.SysBufferToString(buffer)
      mosync.SysFree(buffer)
      local listItem = mosync.maWidgetCreate(mosync.MAW_LIST_VIEW_ITEM)
      mosync.maWidgetSetProperty(listItem, "text", text)
      mosync.maWidgetAddChild(list, listItem)
      table.insert(items, text)
    elseif list == mosync.SysWidgetEventGetHandle(widgetEvent) then
      -- List was clicked, display selected item text.
      local index = mosync.SysWidgetEventGetListItemIndex(widgetEvent)
      if index > -1 then
        local text = items[index + 1]
        mosync.maWidgetSetProperty(editbox, "text", "You selected: "..text)
      end
    end
  end)
end

-- Exit on BACK key on Android
mosync.EventMonitor:OnKeyDown(function(key)
  if mosync.MAK_BACK == key then
    mosync.maExit(0)
  end
end)

CreateUI()

--[[
function CreateUI()
  -- Create screen with widgets.
  local screen = mosync.maWidgetCreate(mosync.MAW_SCREEN)

  -- Create main layout.
  local layout = mosync.maWidgetCreate(mosync.MAW_VERTICAL_LAYOUT)
  mosync.maWidgetSetProperty(
    layout,
    mosync.MAW_WIDGET_WIDTH,
    mosync.FILL_PARENT)
  mosync.maWidgetSetProperty(
    layout,
    mosync.MAW_WIDGET_HEIGHT,
    mosync.FILL_PARENT);
  mosync.maWidgetSetProperty(
    layout,
    mosync.MAW_WIDGET_BACKGROUND_COLOR,
    "0xFFFFFF")
  mosync.maWidgetAddChild(screen, layout)
  
  local label = mosync.maWidgetCreate(mosync.MAW_LABEL)
  mosync.maWidgetSetProperty(label, mosync.MAW_WIDGET_WIDTH, mosync.FILL_PARENT)
  mosync.maWidgetSetProperty(label, mosync.MAW_WIDGET_HEIGHT, mosync.WRAP_CONTENT)
  mosync.maWidgetSetProperty(label, mosync.MAW_BUTTON_TEXT_VERTICAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
  mosync.maWidgetSetProperty(label, mosync.MAW_BUTTON_TEXT_HORIZONTAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
  mosync.maWidgetSetProperty(label, mosync.MAW_BUTTON_FONT_SIZE, "36")
  mosync.maWidgetSetProperty(label, mosync.MAW_BUTTON_FONT_COLOR, "0x000000")
  mosync.maWidgetSetProperty(label, mosync.MAW_WIDGET_BACKGROUND_COLOR, "0x0000FF")
  mosync.maWidgetSetProperty(label, mosync.MAW_BUTTON_TEXT, "My ToDo List")
  mosync.maWidgetAddChild(layout, label)
  
  local button = mosync.maWidgetCreate(mosync.MAW_BUTTON)
  mosync.maWidgetSetProperty(button, mosync.MAW_WIDGET_WIDTH, mosync.FILL_PARENT)
  mosync.maWidgetSetProperty(button, mosync.MAW_WIDGET_HEIGHT, mosync.WRAP_CONTENT)
  mosync.maWidgetSetProperty(button, mosync.MAW_BUTTON_TEXT_VERTICAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
  mosync.maWidgetSetProperty(button, mosync.MAW_BUTTON_TEXT_HORIZONTAL_ALIGNMENT, mosync.MAW_ALIGNMENT_CENTER)
  mosync.maWidgetSetProperty(button, mosync.MAW_BUTTON_FONT_SIZE, "24")
  mosync.maWidgetSetProperty(button, mosync.MAW_BUTTON_FONT_COLOR, "0x000000")
  mosync.maWidgetSetProperty(button, mosync.MAW_WIDGET_BACKGROUND_COLOR, "0x0000FF")
  mosync.maWidgetSetProperty(button, mosync.MAW_BUTTON_TEXT, "Add Item")
  mosync.maWidgetAddChild(layout, button)
  
  local list = maWidgetCreate("ListView")
  mosync.maWidgetSetProperty(list, "width", "-1")
  mosync.maWidgetSetProperty(list, "height", "-1")
  mosync.maWidgetAddChild(layout, list)
  
  -- Show screen.
  mosync.maWidgetScreenShow(screen)
  
  -- Create a widget event listener.
  mosync.EventMonitor:OnWidget(function(widgetEvent)
    if button == mosync.SysWidgetEventGetHandle(widgetEvent) then
      mosync.maWidgetSetProperty(button, mosync.MAW_BUTTON_TEXT, "Hello World!")
    end
  end)
end

-- Exit on BACK key on Android
mosync.EventMonitor:OnKeyDown(function(key)
  if mosync.MAK_BACK == key then
    mosync.maExit(0)
  end
end)

CreateUI()
--]]
