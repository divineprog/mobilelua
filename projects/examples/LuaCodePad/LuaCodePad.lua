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
File: LuaCodePad.lua
Author: Mikael Kindborg

Application for programming Lua (and JavaScxript!) directly on the device.

The program uses the MoSync Wormhole JavaScript to C++ communication
bridge for evaluating Lua from JavaScript. In this program, C++ is replaced
by Lua, and since Lua is a dynamic language, we can directly send Lua code
from JavaScript to Lua, and jujst evaluate the Lua code.
]]

-- Table that holds global objects. The reason for keeping global
-- references is to be able to access the objects interactively.
LuaCodePad = (function()

  local self = {}

  self.Main = function(self)
    self:CreateUI()
    self:CreateHTML()
    NativeUI:ShowScreen(self.Screen)
  end

  self.CreateUI = function(self)
    self.Screen = NativeUI:CreateWidget
    {
      type = "Screen"
    }

    self.WebView = NativeUI:CreateWidget
    {
      type = "WebView",
      parent = self.Screen,
      width = FILL_PARENT,
      height = FILL_PARENT,
      enableZoom = "true",
      hardHook = "lua://.*",
      eventFun = function(widget, widgetEvent)
        self:HandleWebViewEvent(widgetEvent)
      end
    }
  end

  self.CreateHTML = function(self)
    maWidgetSetProperty(
      self.WebView:GetHandle(),
      MAW_WEB_VIEW_HTML,
[==[
<!DOCTYPE html>
<html>
<head>
</head>
<body>
<div id="MainUI">
  <div>
    <textarea id="CodeEditor" rows="10" cols="32">log("@@@Hello World")
    </textarea>
  <br />
  <input value="Run" type="button" onmousedown="CodeEditorRunAll()" />
  <input value="Eval" type="button" onmousedown="CodeEditorEvalSelection()" />
  </div>
  <div>
    <input id="UrlField" value="http://" type="text" size="30"/>
    <br />
    <input value="Download" type="button" onmousedown="DownloadScript()" />
  </div>
  <div id="StatusMessage"></div>
</div>
<script>
function CodeEditorRunAll()
{
  EvalLuaScript(CodeEditorGetText())
}

function CodeEditorEvalSelection()
{
  EvalLuaScript(CodeEditorGetSelection())
}

function EvalLuaScript(script)
{
  if (script.length > 0)
  {
    window.location = "lua://" + escape(script)
  }
}

function CodeEditorSetText(text)
{
  var textarea = document.getElementById("CodeEditor")
  textarea.value = text
}

function CodeEditorGetText()
{
  var textarea = document.getElementById("CodeEditor")
  return textarea.value
}

function CodeEditorGetSelection()
{
  var textarea = document.getElementById("CodeEditor")
  return textarea.value.substring(
    textarea.selectionStart,
    textarea.selectionEnd)
}

function ShowStatusMessage(message)
{
  var status = document.getElementById("StatusMessage")
  status.innerHTML = message
}
// MobileLua Interactive Tour
</script>
</body>
</html>
]==])
  end

  self.HandleWebViewEvent = function(widget, widgetEvent)
    if MAW_EVENT_WEB_VIEW_HOOK_INVOKED == SysWidgetEventGetType(widgetEvent) then
      -- Get the url string.
      local urlData = SysWidgetEventGetUrlData(widgetEvent)
      local url = SysLoadStringResource(urlData)

      -- Parse out the Lua script.
      local start,stop = url:find("lua://")
      if nil ~= start then
        -- Get the script string and unescape it.
        local script = SysStringUnescape(url:sub(stop + 1))

        -- Parse script.
        local result = nil
        local resultOrErrorMessage = nil
        result, resultOrErrorMessage = loadstring(script)

        -- Run script.
        if nil ~= result then
          result, resultOrErrorMessage = pcall(result)
        end

        -- Display result
        if nil ~= resultOrErrorMessage then
          self:ShowResult(resultOrErrorMessage)
        end
      end

      -- Release the url data handle.
      maDestroyObject(urlData)
    end
  end

  self.ShowResult = function(self, message)
    log("@@@ ShowResult: "..message)
    self:EvalJS("ShowStatusMessage('"..message.."')");
  end

  self.EvalJS = function(self, script)
    log("@@@ EvalJS: "..script)
    maWidgetSetProperty(
      self.WebView:GetHandle(),
      MAW_WEB_VIEW_URL,
      "javascript:"..script)
  end

  return self
end)()

LuaCodePad:Main()
