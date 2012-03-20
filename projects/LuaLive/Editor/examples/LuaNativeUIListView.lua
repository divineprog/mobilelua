--[[
 * Copyright (c) 2012 MoSync AB
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
File: LuaNativeUIListView.lua
Author: Mikael Kindborg

Description:

NativeUI demo in Lua that shows how to use a layout
with a ListView, uses the high-level Lua NativeUI API.
]]

function CreateUI()

  -- Create screen with widgets.
  local screen = mosync.NativeUI:CreateScreen
  {
  }

  -- Create main layout.
  local layout = mosync.NativeUI:CreateVerticalLayout
  {
    parent = screen,
    backgroundColor = "000000" 
  }
  
  -- Title label.
  local label = mosync.NativeUI:CreateWidget
  {
    type = "Label",
    parent = layout,
    width = mosync.FILL_PARENT,
    height = mosync.WRAP_CONTENT,
    fontSize = "36",
    fontColor = "FFFFFF",
    text = "My ToDo List"
  }

  -- Edit box to input text.
  local editbox = mosync.NativeUI:CreateWidget
  {
    type = "EditBox",
    parent = layout,
    width = mosync.FILL_PARENT,
    height = mosync.WRAP_CONTENT,
    fontSize = "24"
  }
  
  -- Button to add text.
  local button = mosync.NativeUI:CreateButton
  {
    parent = layout,
    width = mosync.FILL_PARENT,
    height = mosync.WRAP_CONTENT,
    fontSize = "24",
    fontColor = "FFFFFF",
    text = "Add Item"
  }

  -- ListView with items.
  local list = mosync.NativeUI:CreateWidget
  {
    type = "ListView",
    parent = layout,
    width = mosync.FILL_PARENT,
    height = mosync.FILL_PARENT,
    backgroundColor = "FF0000"
  }
  
  -- Time to show screen.
  mosync.NativeUI:ShowScreen(screen)

  -- Table (array) that holds list items so that we can access them.
  local items = {}
  
  -- Button event function.
  button:widget:EventFun(function(widget, widgetEvent)
    if (mosync.MAW_EVENT_CLICKED == mosync.SysWidgetEventGetType(widgetEvent)) then
      local editText = editbox:GetProp("text")
      local listItem = mosync.NativeUI:CreateWidget
      {
        type = "ListViewItem",
        parent = list,
        text = editText
      }
      table.insert(items, editText)
    end
  end)
  
  -- List event function.
  onListClicked = function(widget, widgetEvent)
    if (mosync.MAW_EVENT_ITEM_CLICKED == mosync.SysWidgetEventGetType(widgetEvent)) then
      local index = mosync.SysWidgetEventGetListItemIndex(widgetEvent)
      if index > -1 then
        local text = items[index + 1]
        editbox:SetProp("text", "You selected: "..text)
      end
    end
  end

  -- Exit on BACK key on Android
  mosync.EventMonitor:OnKeyDown(function(key)
    if mosync.MAK_BACK == key then
      mosync.maExit(0)
    end
  end)
end

-- Create the UI (starts the program).
CreateUI()
