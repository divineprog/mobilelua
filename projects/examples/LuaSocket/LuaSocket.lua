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
File: LuaSocket.lua
Author: Mikael Kindborg
Date: 2011-08-18

Program that demonstrates how to use MoSync socket connections from Lua.

This program also shows how to use the "Sys" utility functions to create
C byte buffers and read and write bytes. These functions are listed in
MobileLuaLib/toluabindings/lua_systemapi.h

The support functions that calls back into Lua on connection events
are implemented in MobileLua/lualib/LuaEngine.cpp.

Tested in MoRE and on Android.
]]

function Main()
  print("Touch screen to open a socket connection.")
  print("Press BACK or Key 0 to exit.")
  mosync.EventMonitor:OnTouchUp(OpenSocket)
  mosync.EventMonitor:OnKeyDown(OnKeyDown)
end

function OpenSocket()
  local connection = mosync.maConnect("socket://www.openplay.se:80")
  print("maConnect result: " .. connection)
  if connection > 0 then
    mosync.EventMonitor:SetConnectionFun(connection, CreateConnectionListener())
  end
end

function OnKeyDown(key)
  if mosync.MAK_BACK == key or mosync.MAK_0 == key then
    mosync.maExit(0)
  end
end

--[[
Create function called on a connection event.
  connection The handle to the connection associated with the event.
  opType One of the \link #mosync.CONNOP_READ CONNOP \endlink constants.
  result A success value \> 0 or a \link #CONNERR_GENERIC CONNERR \endlink code.
]]
function CreateConnectionListener()

  local outBuffer = mosync.SysAlloc(1000)
  local inBuffer = mosync.SysAlloc(1000)

  return function(connection, opType, result)

    print("ConnectionListener(" ..
      connection .. ", " .. opType .. ", " .. result .. ")")

    -- First we get an event that confirms that the connection is created,
    -- if this is successful we write a request to get a web page.
    if mosync.CONNOP_CONNECT == opType and result > 0 then
      print("mosync.CONNOP_CONNECT successful, writing request.")
      local numberOfBytes = WriteStringToBuffer(
        "GET /index.html HTTP/1.0\r\nHost: www.openplay.se\r\n\r\n",
        outBuffer)
      mosync.maConnWrite(connection, outBuffer, numberOfBytes)

    -- Next we get a confirm of the write operation, if successful
    -- we read the response.
    elseif mosync.CONNOP_WRITE == opType and result > 0 then
      print("mosync.CONNOP_WRITE successful, reading response.")
      mosync.maConnRead(connection, inBuffer, 1000)

    -- Finally we the result of the read operation. Note that we
    -- may need to do several calls to mosync.maConnRead to read all
    -- data you want to get. A call to mosync.maConnRead reads between
    -- one and the number of requested bytes. You may not get all
    -- bytes first time.
    elseif mosync.CONNOP_READ == opType and result > 0 then
      print("mosync.CONNOP_READ read " .. result .. " bytes.")
      -- Print result.
      PrintBuffer(inBuffer, result)
      -- Clean up.
      mosync.SysFree(inBuffer)
      mosync.SysFree(outBuffer)
      mosync.EventMonitor:RemoveConnectionFun(connection)
      mosync.maConnClose(connection)
      -- Print message.
      print("Test complete - read data.")
      print("Press BACK or Key 0 to exit.")
    end

  end
end

--[[ 
Copy string char values to a C buffer.
Note that in Lua first element has index one,
in a C buffer first byte has index zero.
TODO: Replace this with mosync.SysStringToBuffer()
]]
function WriteStringToBuffer(s, buffer)
  --print(s)
  local i = 0
  for c in s:gmatch(".") do
    i = i + 1
    local b = s:byte(i)
    --print("Char: " .. c)
    --print("Byte: " .. b)
    mosync.SysBufferSetByte(buffer, i - 1, b)
  end
  -- Return number of bytes written to buffer.
  return i
end

function PrintBuffer(buffer, size)
  local line = ""
  for i = 0, size - 1 do
    local c = mosync.SysBufferGetByte(buffer, i)
    -- If we have end-of-line, print the line
    if 10 == c or 13 == c then
      if line:len() > 0 then
        print(line)
        -- Start new line
        line = ""
      end
    else
      -- Append char to line.
      line = line .. string.char(c)
    end
  end
  -- Print final line (may be empty)
  print(line)
end

-- Start the program
Main()
