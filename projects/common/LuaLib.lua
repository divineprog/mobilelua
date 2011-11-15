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
 *
 * Parts of the code contributed by Paul Kulchenko, https://github.com/pkulchenko
--]]

--[[
File: LuaLib.lua
Author: Mikael Kindborg

This is a Lua library built directly on top of the MoSync API.

Call EventMonitor:RunEventLoop() to enter the MoSync event loop.
This can be done from Lua or from C/C++ by evaluating Lua code.
]]

-- Create the global EventMonitor object.
EventMonitor = (function ()

  local self = {}
  local touchDownFun = nil
  local touchUpFun = nil
  local touchDragFun = nil
  local keyDownFun = nil
  local keyUpFun = nil
  local sensorFun = nil
  local widgetFun = nil
  local anyFun = nil
  local connectionFuns = {}
  local isRunning = false
  
  -- The time to wait in maWait. Can be changed by the
  -- application by setting EventMonitor.WaitTime = <value>
  self.WaitTime = 0

  self.OnTouchDown = function(self, fun)
    touchDownFun = fun
  end

  self.OnTouchUp = function(self, fun)
    touchUpFun = fun
  end

  self.OnTouchDrag = function(self, fun)
    touchDragFun = fun
  end

  self.OnKeyDown = function(self, fun)
    keyDownFun = fun
  end

  self.OnKeyUp = function(self, fun)
    keyUpFun = fun
  end

  self.OnSensor = function(self, fun)
    sensorFun = fun
  end

  self.OnWidget = function(self, fun)
    widgetFun = fun
  end

  self.OnAny = function(self, fun)
    anyFun = fun
  end

  self.SetConnectionFun = function(self, connection, fun)
    connectionFuns[connection] = fun
  end

  self.RemoveConnectionFun = function(self, connection)
    connectionFuns[connection] = nil
  end
  
  self.ExitEventLoop = function(self)
    isRunning = false
  end

  self.RunEventLoop = function(self)

    -- Create a MoSync event object.
    local event = SysEventCreate()

    -- Set isRunning flag to true.
    isRunning = true
    
    -- This is the event loop.
    while isRunning do
      maWait(self.WaitTime)
      while isRunning and 0 ~= maGetEvent(event) do
        local eventType = SysEventGetType(event)
        if EVENT_TYPE_CLOSE == eventType then
          isRunning = false
          break -- Exit inner while loop.
        elseif EVENT_TYPE_KEY_PRESSED == eventType then
          if nil ~= keyDownFun then
            keyDownFun(SysEventGetKey(event))
          end
        elseif EVENT_TYPE_KEY_RELEASED == eventType then
          if nil ~= keyUpFun then
            keyUpFun(SysEventGetKey(event))
          end
        elseif EVENT_TYPE_POINTER_PRESSED == eventType then
          if nil ~= touchDownFun then
            touchDownFun(
              SysEventGetX(event),
              SysEventGetY(event),
              SysEventGetTouchId(event))
          end
        elseif EVENT_TYPE_POINTER_RELEASED == eventType then
          if nil ~= touchUpFun then
            touchUpFun(
              SysEventGetX(event),
              SysEventGetY(event),
              SysEventGetTouchId(event))
          end
        elseif EVENT_TYPE_POINTER_DRAGGED == eventType then
          if nil ~= touchDragFun then
            touchDragFun(
              SysEventGetX(event),
              SysEventGetY(event),
              SysEventGetTouchId(event))
          end
        elseif EVENT_TYPE_CONN == eventType then
          local connectionFun = connectionFuns[SysEventGetConnHandle(event)]
          if nil ~= connectionFun then
            connectionFun(
              SysEventGetConnHandle(event),
              SysEventGetConnOpType(event),
              SysEventGetConnResult(event))
          end
        elseif EVENT_TYPE_SENSOR == eventType then
          if nil ~= sensorFun then
            sensorFun(
              SysEventSensorGetType(event),
              SysEventSensorGetValue1(event),
              SysEventSensorGetValue2(event),
              SysEventSensorGetValue3(event))
          end
        elseif EVENT_TYPE_WIDGET == eventType then
          if nil ~= widgetFun then
            widgetFun(SysEventGetData(event))
          end
        end -- End of ifs

        -- Always pass the event to the any function.
        if nil ~= anyFun then
          anyFun(event, result)
        end
      end -- End of inner event loop
    end -- End of outer event loop

    -- Free the event object.
    SysFree(event)

  end -- End of function runEventLoop

  return self

end)()

-- Create the global Screen object
Screen = (function()

  local self = {}

  self.Width = function(self)
    return EXTENT_X(maGetScrSize())
  end

  self.Height = function(self)
    return EXTENT_Y(maGetScrSize())
  end

  self.SetColor = function(self, red, green, blue)
    maSetColor(blue + (green * 256) + (red * 65536))
  end

  self.FillRect = function(self, top, left, width, height)
    maFillRect(top, left, width, height)
  end

  self.Fill = function(self)
    self:FillRect(0, 0, self:Width(), self:Height())
  end

  self.Update = function(self)
    maUpdateScreen()
  end

  return self

end)()

-- Global Connection object. Data that is read is zero terminated.
Connection = {}

Connection.Create = function(selfIsNotUsed)
  -- Table holding the object's methods.
  local self = {}

  -- MoSync connection handle.
  local mConnectionHandle

  -- Callback functions.
  local mConnectedFun
  local mReadDoneFun
  local mWriteDoneFun

  -- Input buffer and read status.
  local mInBuffer
  local mNumberOfBytesToRead
  local mNumberOfBytesRead

  -- Output buffer.
  local mOutBuffer
  
  -- Is the connection open flag.
  local mOpen = false

  -- Private connection listener callback function. Used internally by
  -- the connection object. Do not call this function in your code.
  self.__ConnectionListener__ = function(connection, opType, result)
    if CONNOP_CONNECT == opType then
      -- First we get an event that confirms that the connection is created.
      log("CONNOP_CONNECT result: " .. result)
      mConnectedFun(result)
    elseif CONNOP_READ == opType then
      -- This is a confirm of a read or write operation.
      log("CONNOP_READ result: " .. result)
      if result > 0 then
        -- Update byte counters.
        mNumberOfBytesRead = mNumberOfBytesRead + result
        mNumberOfBytesToRead = mNumberOfBytesToRead - result
        if mNumberOfBytesToRead > 0 then
          -- There is more data to read, continue reading bytes
          -- into the input buffer.
          local pointer = SysBufferGetBytePointer(
            mInBuffer, 
            mNumberOfBytesRead)
          maConnRead(mConnectionHandle, pointer, mNumberOfBytesToRead)
        else
          -- Done reading, zero terminate buffer and call callback function.
          SysBufferSetByte(mInBuffer, mNumberOfBytesRead, 0)
          mReadDoneFun(mInBuffer, result)
        end
      else
        -- There was an error, free input buffer and report it.
        SysFree(mInBuffer)
        mReadDoneFun(nil, result)
      end
    elseif CONNOP_WRITE == opType then
      log("CONNOP_WRITE result: " .. result)
      mWriteDoneFun(mOutBuffer, result)
    end
  end
  
  -- Public protocol.

  -- Connect to an address.
  self.Connect = function(self, connectString, connectedFun)
    -- The connection must not be open.
    if mOpen then return false end
    mOpen = true
    mConnectionHandle = maConnect(connectString)
    mConnectedFun = connectedFun
    log("maConnect result: " .. mConnectionHandle)
    if mConnectionHandle > 0 then
      EventMonitor:SetConnectionFun(
        mConnectionHandle, 
        self.__ConnectionListener__)
      return true
    else
      -- Error
      mConnectedFun(-1)
      return false
    end
  end

  -- Close a connection.
  self.Close = function(self)
    -- The connection must be open.
    if not mOpen then return false end
    mOpen = false
    EventMonitor:RemoveConnectionFun(mConnectionHandle)
    maConnClose(mConnectionHandle)
    return true
  end

  -- Kicks off reading to a byte buffer. The connection
  -- listener function handles the read result.
  self.Read = function(self, numberOfBytes, readDoneFun)
    -- The connection must be open.
    if not mOpen then return false end
    mNumberOfBytesToRead = numberOfBytes
    mNumberOfBytesRead = 0
    mReadDoneFun = readDoneFun
    -- Allocate input buffer. This will be handed to the readDoneFun
    -- on success. That function is responsible for deallocating it.
    -- We add one byte for a zero termination character.
    mInBuffer = SysAlloc(mNumberOfBytesToRead + 1)
    -- Start reading bytes into the input buffer.
    maConnRead(mConnectionHandle, mInBuffer, mNumberOfBytesToRead)
    return true
  end

  -- Kicks off writing from a byte buffer. The connection
  -- listener function handles the write result.
  self.Write = function(self, buffer, numberOfBytesToWrite, writeDoneFun)
    -- The connection must be open.
    if not mOpen then return false end
    mOutBuffer = buffer
    mWriteDoneFun = writeDoneFun
    -- Start writing bytes.
    maConnWrite(mConnectionHandle, buffer, numberOfBytesToWrite)
    return true
  end

  return self
end

-- For backwards compatibility.
SysConnectionCreate = Connection.Create

-- Widget size values as strings (the MAW_CONSTANT_* values
-- are integers and cannot be used with maWidgetSetProperty).
FILL_PARENT = ""..MAW_CONSTANT_FILL_AVAILABLE_SPACE
WRAP_CONTENT = ""..MAW_CONSTANT_WRAP_CONTENT

-- Create the global NativeUI manager object.
NativeUI = (function()

  -- The UI manager object.
  local uiManager = {}

  -- Table that maps widget handles to event functions.
  local mWidgetHandleToEventFun = {}

  -- Table that maps widget handles to widget objects.
  local mWidgetHandleToWidgetObject = {}
  
  -- Has the UI manager been initialised?
  local mIsInitialized = false
  
  -- Utility method that sets a table field to a value 
  -- if the field is nil. Intended for internal use.
  uiManager.__SetPropIfNil__ = function(self, proplist, key, value)
    if nil == proplist[key] then
      proplist[key] = value
      --log("Setting prop "..key.." to "..value)
    end
  end
  
  -- Function that creates a widget. The parameter
  -- proplist is a table with widget properties.
  -- Valid property names are properties available for
  -- maWidgetSetProperty, plus "type", "parent", 
  -- "eventFun", and "data". The "data" property is
  -- user for setting custom data associated with
  -- the widget object. The widget object is a Lua
  -- object (table), it wraps a widhet handle, which
  -- identifies a Native UI widget.
  uiManager.CreateWidget = function(self, proplist)
  
    -- The widget object.
    local widget = {}
    
    -- Create the Native UI widget and check that it went ok.
    local mWidgetHandle = maWidgetCreate(proplist.type)
    if mWidgetHandle < 1 then
      return nil
    end
  
    -- Returns the Native UI widget handle.
    widget.GetHandle = function(self)
      return mWidgetHandle
    end
    
    -- Utility method that sets a widget property. The 
    -- value can be either a number or a string, it will
    -- be converted to a string since that is what
    -- maWidgetSetProperty wants.
    widget.SetProp = function(self, property, value)
      -- Make sure value is always a string.
      maWidgetSetProperty(self:GetHandle(), property, ""..value)
    end

    -- Evaluate JavaScript in a WebView widget.
    -- Only valid for WebView widgets!
    widget.EvalJS = function(self, script)
      --log("@@@ EvalJS: "..script)
      self:SetProp(MAW_WEB_VIEW_URL, "javascript:"..script)
    end

    -- Evaluate a Lua script in respose to a HOOK_INVOKED event.
    -- Only valid for WebView widgets!
    widget.EvalLuaOnHookInvoked = function(self, widgetEvent)
      if MAW_EVENT_WEB_VIEW_HOOK_INVOKED == 
        SysWidgetEventGetType(widgetEvent) then

        -- Get the url data handle.
        local urlData = SysWidgetEventGetUrlData(widgetEvent)
        
        -- Convert handle to a Lua string (will be GC:ed).
        local url = SysLoadStringResource(urlData)

        -- Release the url data handle.
        maDestroyObject(urlData)
        
        -- Parse out the Lua script.
        local start,stop = url:find("lua://")
        if nil == start then
          return false, "url is missing lua:// scheme specifier"
        end
        
        -- Get the script string and unescape it.
        local script = SysStringUnescape(url:sub(stop + 1))

        -- Parse script.
        local result = nil
        local resultOrErrorMessage = nil
        result, resultOrErrorMessage = loadstring(script)
        if nil == result then
          return false, resultOrErrorMessage
        end
          
        -- Run script and return result.
        result, resultOrErrorMessage = pcall(result)
        return result, resultOrErrorMessage
      end
    end

    -- Set properties of the widget. Properties "parent", "type",
    -- "eventFun", and "data" are handled as special cases.
    for prop,value in pairs(proplist) do
      if "parent" == prop then
        maWidgetAddChild(value:GetHandle(), mWidgetHandle)
      elseif "eventFun" == prop then
        -- Add function as event handler for this widget.
        mWidgetHandleToEventFun[mWidgetHandle] = value
        -- Also add the widget to the widget handle table.
        mWidgetHandleToWidgetObject[mWidgetHandle] = widget
      elseif "data" == prop then
        widget.data = value
      elseif "type" ~= prop then
        widget:SetProp(prop, value)
      end
    end

    return widget
  end
  
  -- Method that creates a button widget with some
  -- default property values.
  uiManager.CreateButton = function(self, proplist)
    proplist.type = "Button"
    self:__SetPropIfNil__(proplist, "width", WRAP_CONTENT)
    self:__SetPropIfNil__(proplist, "height", WRAP_CONTENT)
    self:__SetPropIfNil__(proplist, "textHorizontalAlignment", "center")
    self:__SetPropIfNil__(proplist, "textVerticalAlignment", "center")
    self:__SetPropIfNil__(proplist, "fontSize", "24")
    return self:CreateWidget(proplist)
  end

  -- TODO: Add more convenience methods for creating widgets.
  
  -- Show a screen widget. The screen widget is a Lua object.
  uiManager.ShowScreen = function(self, screen)
    -- Initializes the UI manager if not done.
    self:Init()
    maWidgetScreenShow(screen:GetHandle())
  end
  
  -- Show the deafult MoSync screen.
  uiManager.ShowDefaultScreen = function(self)
    maWidgetScreenShow(0)
  end
  
  -- Register an event function for the supplied widget handle.
  -- This method is useful if you wish to use the bare MoSync
  -- Widget API and still have the benefit of attaching event
  -- handler functions to widgets. Note that the widhetHandle
  -- parameter is a handle to a MoSync widget (it is NOT a Lua
  -- widget object). To unregister an event function, it should
  -- work to pass nil as the eventFun parameter.
  uiManager.OnWidgetEvent = function(self, widgetHandle, eventFun)
    -- Initializes the UI manager if not done.
    self:Init()
    -- Add function as event handler for this widget.
    mWidgetHandleToEventFun[widgetHandle] = eventFun
  end
  
  -- Call this method to start listening for Widget events.
  -- This could have been done right when creating the
  -- UI manager object, but since we have only one widget event
  -- listener function in EventMonitor, it will ve overwritten
  -- by the widget event listener in the LuaLive client. Then
  -- the application using NativeUI will not work.
  -- TODO: Fix this.
  uiManager.Init = function(self)
    if not mIsInitialized then
      mIsInitialized = true
      -- Create widget event handler that dispatches to
      -- the registered widget event functions.
      EventMonitor:OnWidget(function(widgetEvent)
        -- Get the widget handle of the event.
        local widgetHandle = SysWidgetEventGetHandle(widgetEvent)
        -- Get the event function and the widget object.
        local eventFun = mWidgetHandleToEventFun[widgetHandle]
        local widget = mWidgetHandleToWidgetObject[widgetHandle]
        if nil ~= eventFun and nil ~= widget then
          -- We have both an event function and a widget object.
          -- Call the function with the object and the widget
          -- event as parameters.
          eventFun(widget, widgetEvent)
        elseif nil ~= eventFun then
          -- We have an event function.
          -- Call the function.
          eventFun(widgetEvent)
        end
      end)
    end
  end
  
  return uiManager
  
end)()

-- Create the global File System object.
FileSys = (function()

  local fileObj = {}
  
  -- Get the path to the local file system.
  -- Returns path that ends with a slash,
  -- empty string on error.
  fileObj.GetLocalPath = function(self)
    local bufferSize = 1024
    local buffer = SysAlloc(bufferSize)
    local size = maGetSystemProperty(
      "mosync.path.local",
      buffer,
      bufferSize);
    -- If there was an error, return empty string.
    if size < 0 or size > bufferSize then
      return ""
    end
    local path = SysBufferToString(buffer);
    SysFree(buffer)
    return path
  end
  
  
  -- Open a file for writing.
  -- Create the file if it does not exist.
  -- Note: Will truncate the file if it exists.
  -- Returns handle to the open file, false on error.
  fileObj.OpenFileForWriting = function(self, filePath)
    local file = maFileOpen(filePath, MA_ACCESS_READ_WRITE)
    if file < 0 then
      return false
    end

    if maFileExists(file) == 1 then
      -- If the file exists, truncate it to zero size.
      -- We do this to prevent problems with old data
      -- at the end of the file if the new file is
      -- shorter than the old file.
      maFileTruncate(file, 0)
    else
      -- If the file does not exist, create it.
      local result = maFileCreate(file)
      if result < 0 then
        return false
      end
    end

    return file
  end

  -- Open a file for reading.
  -- Returns handle to the open file, false on error.
  fileObj.OpenFileForReading = function(self, filePath)
    local file = maFileOpen(filePath, MA_ACCESS_READ)
    if file < 0 then
      return false
    end

    if not maFileExists(file) then
      return false
    end

    return file
  end
  
  -- Write a data object to a file.
  -- Returns true on success, false on error.
  fileObj.WriteDataToFile = function(self, filePath, dataHandle)
    local file = self:OpenFileForWriting(filePath)
    if file < 0 then
      return false
    end

    local result = maFileWriteFromData(
      file,
      dataHandle,
      0,
      maGetDataSize(dataHandle));

    maFileClose(file)

    if result < 0 then
      return false
    end
    
    return true
  end
  
  -- Read a data object from a file.
  -- Returns handle to data, false on error
  fileObj.ReadDataFromFile = function(self, filePath)
    local file = self:OpenFileForReading(filePath)
    if file < 0 then
      return false
    end

    local size = maFileSize(file);
    if size < 1 then
      return false
    end

    local dataHandle = maCreatePlaceholder()
    if dataHandle < 0 then
      return false
    end
    
    local result = maCreateData(dataHandle, size)
    if RES_OK ~= result then
      return false
    end

    result = maFileReadToData(file, dataHandle, 0, size);

    maFileClose(file)
    
    if result < 0 then
      return false
    end

    return dataHandle;
  end
  
  return fileObj
end)()
