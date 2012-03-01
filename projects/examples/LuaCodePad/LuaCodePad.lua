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

Application for programming Lua (and JavaScript!) directly on the device.

The program uses the MoSync Wormhole JavaScript to C++ communication
bridge for evaluating Lua from JavaScript. In this program, C++ is replaced
by Lua, and since Lua is a dynamic language, we can directly send Lua code
from JavaScript to Lua, and jujst evaluate the Lua code.
]]

-- Table that holds global objects. The reason for keeping global
-- references is to be able to access the objects interactively.
LuaCodePad = (function()

  local self = {}
  
  -- Table that hold scripts.
  self.Scripts = {}

  self.Main = function(self)
    self:CreateUI()
    self:CreateHTML()
    mosync.NativeUI:ShowScreen(self.Screen)
    -- Exit when Android back key is pressed.
    mosync.EventMonitor:OnKeyDown(function(key)
      if mosync.MAK_BACK == key then
        mosync.EventMonitor:ExitEventLoop()
      end
    end)
  end

  self.CreateUI = function(self)
    self.Screen = mosync.NativeUI:CreateWidget
    {
      type = "Screen"
    }

    self.WebView = mosync.NativeUI:CreateWebView
    {
      parent = self.Screen,
      enableZoom = "true",
      eventFun = mosync.NativeUI:CreateWebViewEventFun(
        function(success, result)
          if nil == result then
            result = "nil"
          end
          if success then
            self:ShowResult("RESULT: "..result)
          else
            self:ShowResult("ERROR: "..result)
          end
        end)
    }
  end

  self.PageLoaded = function(self)
    -- Populate script menu.
    -- TODO: Load scripts from file.
    self:CreateInitialScripts()
    self.WebView:EvalJS("ScriptMenuClear()");
    for key,value in pairs(self.Scripts) do
      self.WebView:EvalJS("ScriptMenuAddItem(".."'"..key.."')");
    end
  end
  
  self.LoadScript = function(self, scriptKey)
    --log("@@@"..scriptKey)
    local script = self.Scripts[scriptKey]
    if nil ~= script then
      --log(script)
      local js = "CodeEditorSetText('"..mosync.SysStringEscape(script).."')"
      --log(js)
      LuaCodePad.WebView:EvalJS(js)
    end
  end
  
  self.ShowResult = function(self, message)
    log("@@@ ShowResult: "..message)
    self.WebView:EvalJS("ShowStatusMessage('"..message.."')");
  end

  self.CreateInitialScripts = function(self)
    -- Add some scripts.
    self.Scripts["Workspace 1"] =
[==[mosync.maVibrate(500)
]==]

    self.Scripts["Workspace 2"] =
[==[mosync.maVibrate(1000)
log("Hello World")
]==]
  end
  
  self.CreateHTML = function(self)
    self.WebView:SetProp(mosync.MAW_WEB_VIEW_HTML,
[==[
<!DOCTYPE html>
<html>
<head>
</head>
<body>
<div id="MainUI">
  <div>
    <input value="Run" type="button" onmousedown="CodeEditorRunAll()" />
    <input value="Eval" type="button" onmousedown="CodeEditorEvalSelection()" />
    <select id="ScriptMenu" onchange="ScriptMenuSelected(this)">
    </select>
    <br />
    <textarea id="CodeEditor" rows="10" cols="32">log("@@@ Hello World")
    </textarea>
  </div>
  <div>
    <input id="UrlField" value="http://" type="text" size="30"/>
    <br />
    <input value="New Script" type="button" onmousedown="DownloadScript()" />
    <input value="Download Script" type="button" onmousedown="DownloadScript()" />
    <br />
    <input type="checkbox" name="CheckboxDeleteScript" value="" />
    <input value="Delete Script" type="button" onmousedown="DeleteScript()" />
  </div>
  <div id="StatusMessage"></div>
</div>
<script>
]==] .. mosync.NativeUI:GetMoSyncBridgeJSScript() .. [==[
function CodeEditorRunAll()
{
  EvalLua(CodeEditorGetText())
}

function CodeEditorEvalSelection()
{
  EvalLua(CodeEditorGetSelection())
}

function EvalLua(script)
{
  if (script.length > 0)
  {
    mosync.bridge.sendRaw(escape(script))
  }
}

// The text is escaped.
function CodeEditorSetText(text)
{
  var textarea = document.getElementById("CodeEditor")
  textarea.value = unescape(text)
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

function ScriptMenuClear()
{
  var menu = document.getElementById("ScriptMenu")
  while (menu.hasChildNodes())
  {
    menu.removeChild(menu.firstChild)
  }
}

function ScriptMenuAddItem(title)
{
  var menu = document.getElementById("ScriptMenu")
  var item = document.createElement('option')
  item.innerHTML = title
  menu.appendChild(item)
}

function ScriptMenuSelected(menu)
{
  var scriptKey = menu.options[menu.selectedIndex].value
  EvalLua("LuaCodePad:LoadScript('" + scriptKey + "')")
}

// MobileLua Interactive Tour
EvalLua("LuaCodePad:PageLoaded()")
</script>
</body>
</html>
]==])
  end

  return self
end)()

LuaCodePad:Main()

--[[
LuaCodePad.WebView:EvalJS("CodeEditorSetText(\"mosync.maVibrate(500)\")")
--]]
