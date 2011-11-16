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
File: LuaCountDown.lua
Author: Mikael Kindborg

Demonstration of using a WebView in Lua. Shows how to call 
Lua code from JavaScript.

The app displays a "count-down item" when you touch the 
"Touch Me!" button. At zero the device vibrates. Touch the
button again, and the sequence is repeated.

The logic that is implemenetd in Lua could have been
implemented in JavaScript as well, but the program is a
nice demonstration of how to Lua and JavaScript interplay.
]]

function Main()
  CreateUI()
  CreateHTML()
  NativeUI:ShowScreen(Screen)
  CreateKeyHandler()
end

function CreateUI()
  Screen = NativeUI:CreateWidget
  {
    type = "Screen"
  }

  WebView = NativeUI:CreateWidget
  {
    type = "WebView",
    parent = Screen,
    width = FILL_PARENT,
    height = FILL_PARENT,
    enableZoom = "true",
    hardHook = "lua://.*",
    eventFun = function(widget, widgetEvent)
      widget:EvalLuaOnHookInvoked(widgetEvent)
    end
  }
end

function CreateKeyHandler()
  -- Exit when Android back key is pressed.
  EventMonitor:OnKeyDown(function(key)
    if MAK_BACK == key then
      EventMonitor:ExitEventLoop()
    end
  end)
end
  
Counter = 11

function OnTouch()
  Counter = Counter - 1
  if Counter > 0 then
    WebView:EvalJS("AddItem('"..Counter.."')")
  elseif Counter == 0 then
    maVibrate(1000)
    WebView:EvalJS("AddItem('Take Off!')")
  else
    Counter = 11
    WebView:EvalJS("ClearItems()")
  end
end

function CreateHTML()
  WebView:SetProp(MAW_WEB_VIEW_HTML,
[==[
<!DOCTYPE html>
<html>
<head>
<style>
html
{
  margin: 0;
  padding: 0;
  width: 100%;
  height: 100%;
  background-color: #FFFFFF;
}
#TouchArea
{
  font-size: 2.0em;
  font-family: sans-serif;
  font-weight: bold;
  text-align: center;
  
  padding: 0.3em 0.5em;
  border-radius: 0.3em;
  -webkit-border-radius: 0.3em;
  margin: 1em 0.5em;

  color: white;
  background-color: #99CF00;
}
.TextItem
{
  font-size: 1.8em;
  font-family: sans-serif;
  font-weight: bold;
  text-align: center;
  
  padding: 0.3em 0.5em;
  border-radius: 0.3em;
  -webkit-border-radius: 0.3em;
  margin: 0.5em 0.5em;

  color: white;
  background-color: #99CF88;
}
</style>
<script>
function EvalLua(script)
{
  window.location = "lua://" + escape(script)
}

function AddItem(itemText)
{
  var itemArea = document.getElementById("ItemArea")
  var item = document.createElement('div')
  item.innerHTML = itemText
  item.className = "TextItem"
  itemArea.appendChild(item)
}

function ClearItems()
{
  var itemArea = document.getElementById("ItemArea")
  while (itemArea.hasChildNodes())
  {
    itemArea.removeChild(itemArea.firstChild)
  }
}
</script>
</head>
<body>
<div id="TouchArea" ontouchstart="EvalLua('OnTouch()')">Touch Me!</div>
<div id="ItemArea"></div>
</body>
</html>
]==])
end

-- Start the program.
Main()
