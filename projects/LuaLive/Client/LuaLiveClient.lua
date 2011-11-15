--[[
 * Copyright (c) 2010 MoSync AB
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

  File: LuaLiveClient.lua
  Author: Mikael Kindborg

  LuaLive Client written in Lua.

  Use with the LuaLiveEditor found at https://github.com/divineprog/mobilelua

  Enter the ip address of the editor below in the
  variable SERVER_DEFAULT_ADDRESS.

  Protocol specification:

  The first 4 bytes of a message is a command integer.
  The next 4 bytes is an integer with the size of the rest
  of the message.

  After these binary integer values follows the message content,
  if any. There is always a size integer, event if there is
  no content. This is done to simplify the protocol implementation.
  If there is no data, the size should be zero.

  Thus we have:

    command - 4 byte integer
    data size - 4 byte integer, is 0 if there is no data
    optional data

--]]

LuaLive = (function()

  -- The LuaLive object.
  self = {}
  
  -- Command constants.
  
  -- Run Lua code on the client. After this command follows
  -- a length int and a string of byte-size characters.
  self.COMMAND_RUN_LUA_SCRIPT = 1
  
  -- Reset the interpreter state.
  self.COMMAND_RESET = 2
  
  -- Reply from client to server. After this command follows
  -- a length int and a string of byte-size characters.
  self.COMMAND_REPLY = 3
  
  -- Server address and port.
  -- TODO: Change the server address to the one used on your machine.
  -- When running in the Android emulator, use 10.0.2.2 for localhost.
  self.SERVER_DEFAULT_ADDRESS = "192.168.1.100"
  --self.SERVER_DEFAULT_ADDRESS = "10.0.2.2"
  self.SERVER_PORT = ":55555"
  
  -- The connection object.
  self.Connection = nil
  
  -- Global references to widgets.
  self.WebView = nil
  self.Screen = nil
  
  -- Set to false to connect directly using the
  -- hard-coded server ip-address. This is useful on
  -- platforms that do not have NativeUI, or if you
  -- use the same ip-address every time.
  -- Default is to use NativeUI to display a start
  -- screen where you can enter the ip-address.
  self.USE_NATIVE_UI = true
  
  self.Main = function()
    print("Welcome to the LuaLive client!")
    print("Press BACK or Key 0 to exit.")
    EventMonitor:OnKeyDown(self.OnKeyDown)

    if self.USE_NATIVE_UI then
      self.CreateGraphicalUI()
      self.CreateHTML()
      NativeUI:ShowScreen(self.Screen)
    else
      self.ConnectToServer(self.SERVER_DEFAULT_ADDRESS)
    end
  end
  
  -- Create a UI with a WebView for the start-up screen
  -- of the client. This will work on platforms that
  -- support NativeUI.
  self.CreateGraphicalUI = function()
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
        widget:EvalLuaOnHookInvoked(widgetEvent)
      end
    }
  end
  
  self.CreateHTML = function()
    -- HTML for the WebView.
    self.WebView:SetProp(MAW_WEB_VIEW_HTML,
[==[
<!DOCTYPE html>
<html>
<head>
</head>
<body>
<div id="MainUI">
  <div id="Heading">Welcome to the LuaLive client!</div> 
  <div id="Instruction">
    Enter the ip-address of the LuaLive editor and connect.
    On Android, press BACK to exit.</div>
  <input
    id="ServerIPAddress"
    type="text"
    value=""/>
  <input 
    id="ConnectButton"
    type="button"
    value="Connect"
    onclick="Connect()"/> 
  <div id="Status"></div>
</div>
<script>
function Connect()
{
  EvalLua(
    "LuaLive.SaveServerIPAddressAndConnect('"
    + GetServerIPAddress() 
    + "')")
}

function GetServerIPAddress()
{
  return document.getElementById("ServerIPAddress").value
}

function SetServerIPAddress(address)
{
  document.getElementById("ServerIPAddress").value = address
}

function EvalLua(script)
{
  window.location = "lua://" + script
}

// Call Lua to read and set the server ip address text box.
EvalLua("LuaLive.ReadServerIPAddressAndSetTextBox()")
</script>
</body>
</html>
]==])
  end
  
  self.OnKeyDown = function(key)
    if MAK_BACK == key or MAK_0 == key then
      maExit(0)
    end
  end
  
  self.SaveServerIPAddressAndConnect = function(serverAddress)
    -- TODO: Save serverAddress to file.
    self.ConnectToServer(serverAddress)
  end
  
  self.ReadServerIPAddressAndSetTextBox = function()
    self.WebView:EvalJS("SetServerIPAddress('"..self.ReadServerIPAddress().."')")
  end
  
  self.ReadServerIPAddress = function()
    -- TODO: Read serverAddress from file
    return self.SERVER_DEFAULT_ADDRESS
  end
  
  self.ConnectToServer = function(serverAddress)
    print("Connecting to: "..serverAddress)
    self.connection = Connection:Create()
    self.connection:Connect(
      "socket://"..serverAddress..self.SERVER_PORT,
      self.ConnectionEstablished)
  end
  
  self.ConnectionEstablished = function(result)
    if result > 0 then
      print("Successfully connected.")
      -- Read from server.
      self.ReadCommand()
    else
      print("Failed to connect - error: "..result)
    end
    if self.USE_NATIVE_UI then
      -- Hide the WebView.
      maWidgetScreenShow(MAW_CONSTANT_MOSYNC_SCREEN_HANDLE)
    end
  end
  
  self.ReadCommand = function()
    -- Read from server.
    log("ReadCommand")
    self.connection:Read(8, self.MessageHeaderReceived)
  end
  
  self.MessageHeaderReceived = function(buffer, result)
    -- Process the result.
    log("MessageHeaderReceived")
    if result > 0 then
      local command = self.BufferReadInt(buffer, 0)
      local dataSize = self.BufferReadInt(buffer, 4)
      if self.COMMAND_RUN_LUA_SCRIPT == command then
        -- Read script and evaluate it when recieved.
        self.connection:Read(dataSize, self.ScriptReceived)
      end
    end
    -- Free the result buffer.
    if nil ~= buffer then
      SysFree(buffer)
    end
  end
  
  self.ScriptReceived = function(buffer, result)
    -- Process the result.
    log("ScriptReceived")
    if result > 0 then
      -- Convert buffer to string.
      local script = SysBufferToString(buffer)
      local fun
      local resultOrErrorMessage
      local success = false
      -- Parse script.
      fun, resultOrErrorMessage = loadstring(script)
      if nil ~= fun then
        -- Parsing succeeded, evaluate script.
        success, resultOrErrorMessage = pcall(fun)
        if not success then
          resultOrErrorMessage = "Error: "..resultOrErrorMessage
          log("Failed to evaluate script. "..resultOrErrorMessage)
        end
      end
      -- Write response.
      self.WriteResponse(resultOrErrorMessage)
    end
    -- Free the result buffer.
    if nil ~= buffer then
      SysFree(buffer)
    end
  end
  
  self.WriteResponse = function(value)
    log("WriteResponse")
    if nil == value then
      value = "Undefined"
    end
    local response = "Lua Result: "..value
    -- Allocate buffer for the reply, reader plus string data.
    local dataSize = response:len()
    local buffer = SysAlloc(8 + dataSize)
    self.BufferWriteInt(buffer, 0, self.COMMAND_REPLY)
    self.BufferWriteInt(buffer, 4, dataSize)
    self.BufferWriteString(buffer, 8, response)
    self.connection:Write(buffer, 8 + dataSize, self.WriteResponseDone)
  end
  
  self.WriteResponseDone = function(buffer, result)
    log("Response written - result: "..result)
    if nil ~= buffer then SysFree(buffer) end
    self.ReadCommand()
  end
  
  self.BufferReadInt = function(buffer, index)
    return SysBufferGetInt(buffer, index / 4)
  end
  
  self.BufferWriteInt = function(buffer, index, value)
    SysBufferSetByte(buffer, index, SysBitAnd(value, 255));
    SysBufferSetByte(buffer, index + 1, SysBitAnd(SysBitShiftRight(value, 8), 255));
    SysBufferSetByte(buffer, index + 2, SysBitAnd(SysBitShiftRight(value, 16), 255));
    SysBufferSetByte(buffer, index + 3, SysBitAnd(SysBitShiftRight(value, 24), 255));
  end
  
  -- Write a Lua string to a buffer.
  -- Note that in Lua first element has index one,
  -- in a C buffer first byte has index zero.
  self.BufferWriteString = function(buffer, index, theString)
    local bufferIndex = index
    local stringIndex = 1
    for c in theString:gmatch(".") do
      local b = theString:byte(stringIndex)
      --log("Char: "..c)
      --log("Byte: "..b)
      SysBufferSetByte(buffer, bufferIndex, b)
      bufferIndex = bufferIndex + 1
      stringIndex = stringIndex + 1
    end
  end
  
  return self
end)()

-- Start the program
LuaLive.Main()
