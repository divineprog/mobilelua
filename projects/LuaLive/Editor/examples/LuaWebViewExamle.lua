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
File: LuaWebView.lua
Author: Mikael Kindborg

Demonstration of using a WebView in Lua. Shows how to call 
Lua code from JavaScript.
]]

function Main()
  CreateUI()
  CreateHTML()
  mosync.NativeUI:ShowScreen(Screen)
end

function CreateUI()
  Screen = mosync.NativeUI:CreateWidget
  {
    type = "Screen"
  }

  WebView = mosync.NativeUI:CreateWebView
  {
    parent = Screen,
    enableZoom = "true"
  }
end

function CreateHTML()
  WebView:SetProp(mosync.MAW_WEB_VIEW_HTML,
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
</style>
<script>
]==] .. mosync.NativeUI:GetMoSyncBridgeJSScript() .. [==[
function EvalLua(script)
{
  mosync.bridge.sendRaw(escape(script))
}
</script>
</head>
<body>
<div id="TouchArea" ontouchstart="EvalLua('mosync.maVibrate(500)')">Touch Me!</div>
</body>
</html>
]==])
end

-- Start the program.
Main()
