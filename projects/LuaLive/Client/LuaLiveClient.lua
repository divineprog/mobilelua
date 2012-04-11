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

  File: LuaLiveClient.lua
  Author: Mikael Kindborg

  LuaLive Client written in Lua.

  Use with the LuaLiveEditor found at https://github.com/divineprog/mobilelua

  Enter the ip address of the editor below in the
  variable SERVER_DEFAULT_ADDRESS.
  
  If you want the app to display a user interface where you can
  enter an ip-address of the server/editor (currently only works
  on Android/iOS/Windows Phone), then enable this below by setting:
  
    self.USE_NATIVE_UI = true
    
  If you do not want the initial user interface to display, or are
  building for a platform that does not support NativeUI, you can 
  just set the ip-address in the code below and disable the initial
  screen like this (change the IP address to that displayed in the 
  LuaLive editor):
  
    self.SERVER_DEFAULT_ADDRESS = "192.168.0.145"
    
    self.USE_NATIVE_UI = false

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
  
  -- Reset the interpreter state. Not used?
  self.COMMAND_RESET = 1
  
  -- Reply from client to server. After this command follows
  -- a length int and a string of byte-size characters.
  self.COMMAND_REPLY = 2
  
  -- Run Lua code on the client. After this command follows
  -- a length int and a string of byte-size characters.
  self.COMMAND_EVAL_LUA = 3
  
  -- Run JavaScript code on the client. After this command follows
  -- a length int and a string of byte-size characters.
  self.COMMAND_EVAL_JAVASCRIPT = 4
  
  -- Store a file on the client.
  self.COMMAND_STORE_BINARY_FILE = 5
  
  -- Server address and port.
  -- TODO: Change the server address to the one used on your machine.
  -- When running in the Android emulator, use 10.0.2.2 for localhost.
  --self.SERVER_DEFAULT_ADDRESS = "127.0.0.1"
  --self.SERVER_DEFAULT_ADDRESS = "192.168.0.145"
  self.SERVER_DEFAULT_ADDRESS = "10.0.2.2"
  self.SERVER_PORT = ":55555"
  
  -- The connection object.
  self.Connection = nil
  
  -- Global references to widgets.
  self.WebView = nil
  self.Screen = nil
  
  -- Set to false to connect directly using the
  -- hard-coded server ip-address. This is useful on
  -- platforms that do not have mosync.NativeUI, or if you
  -- use the same ip-address every time.
  -- Default is to use mosync.NativeUI to display a start
  -- screen where you can enter the ip-address.
  self.USE_NATIVE_UI = true
  --self.USE_NATIVE_UI = false
  
  self.Main = function()
    mosync.EventMonitor:OnKeyDown(self.OnKeyDown)

    if self.USE_NATIVE_UI then
      self.CreateGraphicalUI()
      self.CreateHTML()
      mosync.NativeUI:ShowScreen(self.Screen)
    else
      print("Welcome to the LuaLive client!")
      self.ConnectToServer(self.SERVER_DEFAULT_ADDRESS)
    end
  end
  
  -- Create a UI with a WebView for the start-up screen
  -- of the client. This will work on platforms that
  -- support mosync.NativeUI.
  self.CreateGraphicalUI = function()
    self.Screen = mosync.NativeUI:CreateScreen
    {
    }

    self.WebView = mosync.NativeUI:CreateWebView
    {
      parent = self.Screen,
      enableZoom = "true"
    }
  end
  
  self.CreateHTML = function()
    -- HTML for the WebView.
    self.WebView:SetProp(mosync.MAW_WEB_VIEW_HTML,
[==[
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=320, user-scalable=yes">
</head>
<body>
<div id="MainUI">
  <div id="Heading">Welcome to the LuaLive client!</div> 
  <div id="Instruction">
    Enter the ip-address of the LuaLive editor and press Connect.
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
]==] .. mosync.NativeUI:GetMoSyncBridgeJSScript() .. [==[
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
  mosync.bridge.sendRaw(escape(script))
}

// Call Lua to read and set the server ip address text box.
EvalLua("LuaLive.ReadServerIPAddressAndSetTextBox()")
</script>
</body>
</html>
]==])
  end
  
  self.OnKeyDown = function(key)
    if mosync.MAK_BACK == key or mosync.MAK_0 == key then
      mosync.maExit(0)
    end
  end
  
  self.SaveServerIPAddressAndConnect = function(serverAddress)
    -- Save serverAddress to file.
    log("SaveServerIPAddressAndConnect: "..serverAddress)
    mosync.FileSys:WriteStoreText("ServerAddress", serverAddress)
    self.ConnectToServer(serverAddress)
  end
  
  self.ReadServerIPAddressAndSetTextBox = function()
    log("ReadServerIPAddressAndSetTextBox")
    self.WebView:EvalJS(
      "SetServerIPAddress('"..self.ReadServerIPAddress().."')")
  end
  
  self.ReadServerIPAddress = function()
    -- Read serverAddress from file.
    log("ReadServerIPAddress")
    local serverAddress = mosync.FileSys:ReadStoreText("ServerAddress")
    if nil == serverAddress or 0 == serverAddress:len() then
      return self.SERVER_DEFAULT_ADDRESS
    else
      return serverAddress
    end
  end
  
  self.ConnectToServer = function(serverAddress)
    print("Connecting to: "..serverAddress)
    self.connection = mosync.Connection:Create()
    self.connection:Connect(
      "socket://"..serverAddress..self.SERVER_PORT,
      self.ConnectionEstablished)
  end
  
  self.ConnectionEstablished = function(result)
    if result > 0 then
      print("Successfully connected.")
      print("Press BACK or Key 0 to exit.")
      -- Read from server.
      self.ReadCommand()
    else
      print("Failed to connect - error: "..result)
      print("Press BACK or Key 0 to exit.")
    end
    if self.USE_NATIVE_UI then
      -- Hide the WebView.
      mosync.maWidgetScreenShow(mosync.MAW_CONSTANT_MOSYNC_SCREEN_HANDLE)
    end
  end
  
  self.ReadCommand = function()
    -- Read from server.
    self.connection:Read(8, self.MessageHeaderReceived)
  end
  
  self.MessageHeaderReceived = function(buffer, result)
    -- Process the result.
    if result > 0 then
      local command = self.BufferReadInt(buffer, 0)
      local dataSize = self.BufferReadInt(buffer, 4)
      if self.COMMAND_EVAL_LUA == command then
        -- Read script and evaluate it when received.
        self.connection:Read(dataSize, self.EvalLua)
      elseif self.COMMAND_EVAL_JAVASCRIPT == command then
        -- Read script and evaluate it when received.
        self.connection:Read(dataSize, self.EvalJavaScript)
      elseif self.COMMAND_STORE_BINARY_FILE == command then
        -- Write file data to device.
        self.connection:Read(dataSize, self.StoreFile)
      end
    end
    -- Free the result buffer.
    if nil ~= buffer then
      mosync.SysFree(buffer)
    end
  end
  
  self.LoadFile = function(localPath)
    --log("LoadFile: "..localPath)
    local type = self.GetFileType(localPath)
    if 1 == type then
      local success, result = mosync.FileSys:LoadAndRunLocalLuaFile(localPath)
      return result
    end
    if 2 == type then
      self.LoadHTML(localPath)
      return "Done"
    end
  end
  
  self.LoadHTML = function(localPath)
      -- Create WebView if it does not exist.
      if nil == self.WebView then
        self.CreateGraphicalUI()
      end
      
      -- TODO: Make sure screen is shown also when 
      -- the web veiw exists. Will this do?
      mosync.NativeUI:ShowScreen(self.Screen)
      
      if nil ~= self.WebView then
        self.WebView:SetProp(mosync.MAW_WEB_VIEW_URL, localPath)
      end
  end
  
  -- Returns 1 for .lua, 2 for .html/.htm and 0 for unknown.
  -- Function is case insensitive.
  self.GetFileType = function(path)
    local pathUpper = path:upper()
    local a,b = pathUpper:find(".LUA", -4, true)
    if a ~= nil then
      return 1
    end
    a,b = pathUpper:find(".HTM", -4, true)
    if a ~= nil then
      return 2
    end
    a,b = pathUpper:find(".HTML", -5, true)
    if a ~= nil then
      return 2
    end
    return 0
  end
  
  self.EvalLua = function(buffer, result)
    -- Process the result.
    if result > 0 then
      -- Convert buffer to string.
      local script = mosync.SysBufferToString(buffer)
      -- Add ending space as a fix for the bug that
      -- causes statements like "return 10" to fail.
      -- "return 10 " will succeed.
      script = script .. " "
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
      mosync.SysFree(buffer)
    end
  end
  
  self.EvalJavaScript = function(buffer, result)
    -- Process the result.
    if result > 0 then
      -- Convert buffer to string.
      local script = mosync.SysBufferToString(buffer)
      
      -- Create WebView if it does not exist.
      if nil == self.WebView then
        self.CreateGraphicalUI()
      end
      
      -- Do not show the screen, we can evaluate JS
      -- in a hidden web view?
      --mosync.NativeUI:ShowScreen(self.Screen)
      
      if nil ~= self.WebView then
        self.WebView:EvalJS(script)
      end
      
      -- Write response.
      self.WriteResponse("JavaScript Evaluated")
    end
    
    -- Free the result buffer.
    if nil ~= buffer then
      mosync.SysFree(buffer)
    end
  end
  
  -- Write data to file. Data in buffer has this layout:
  --  32 bit int (filepath length)
  --  32 bit int (file data size)
  --  filepath (zero terminated)
  --  file data
  self.StoreFile = function(buffer, result)
    if result > 0 and nil ~= buffer then
      local pathSize = self.BufferReadInt(buffer, 0)
      local dataSize = self.BufferReadInt(buffer, 4)
      -- Get path string.
      local pathPointer = mosync.SysBufferGetBytePointer(buffer, 8)
      local path = mosync.SysBufferToString(pathPointer)
      --log("StoreFile: "..path)
      -- Write file data.
      local dataPointer = mosync.SysBufferGetBytePointer(buffer, 8 + pathSize)
      local dataHandle = mosync.maCreatePlaceholder()
      mosync.maCreateData(dataHandle, dataSize)
      mosync.maWriteData(dataHandle, dataPointer, 0, dataSize)
      local fullPath = mosync.FileSys:GetLocalPath()..path
      --log("StoreFile fullPath: "..fullPath)
      local success1 = mosync.FileSys:CreatePath(fullPath)
      --local success1 = true
      -- Write response.
      if success1 then
        local success2 = mosync.FileSys:WriteDataToFile(fullPath, dataHandle)
        mosync.maDestroyPlaceholder(dataHandle)
        if success2 then
          log("File written: "..path)
          --self.WriteResponse("File written: "..path)
        else
          log("Error writing file: "..fullPath)
          --self.WriteResponse("Error writing file: "..path)
        end
      else
        log("Error creating path: "..fullPath)
        --self.WriteResponse("Error writing file: "..path)
      end
    end
    -- Free the buffer.
    if nil ~= buffer then
      mosync.SysFree(buffer)
    end
    self.ReadCommand()
  end
  
  self.WriteResponse = function(value)
    if nil == value then
      value = "Ok"
    end
    local response = "Lua Result: "..value
    -- Allocate buffer for the reply, reader plus string data.
    local dataSize = response:len()
    local buffer = mosync.SysAlloc(8 + dataSize)
    self.BufferWriteInt(buffer, 0, self.COMMAND_REPLY)
    self.BufferWriteInt(buffer, 4, dataSize)
    self.BufferWriteString(buffer, 8, response)
    self.connection:Write(buffer, 8 + dataSize, self.WriteResponseDone)
  end
  
  self.WriteResponseDone = function(buffer, result)
    if nil ~= buffer then mosync.SysFree(buffer) end
    self.ReadCommand()
  end
  
  self.BufferReadInt = function(buffer, index)
    return mosync.SysBufferGetInt(buffer, index / 4)
  end
  
  self.BufferWriteInt = function(buffer, index, value)
    mosync.SysBufferSetByte(
      buffer,
      index,
      mosync.SysBitAnd(value, 255));
    mosync.SysBufferSetByte(
      buffer,
      index + 1,
      mosync.SysBitAnd(mosync.SysBitShiftRight(value, 8), 255));
    mosync.SysBufferSetByte(
      buffer,
      index + 2,
      mosync.SysBitAnd(mosync.SysBitShiftRight(value, 16), 255));
    mosync.SysBufferSetByte(
      buffer,
      index + 3,
      mosync.SysBitAnd(mosync.SysBitShiftRight(value, 24), 255));
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
      mosync.SysBufferSetByte(buffer, bufferIndex, b)
      bufferIndex = bufferIndex + 1
      stringIndex = stringIndex + 1
    end
  end
  
  return self
end)()

-- Start the program
LuaLive.Main()
