# MobileLua API

The MobileLua API consists of three parts:

* The Lua API, a high-level library with Lua objects for managing events, user interaction, NativeUI, and network communication. This library will be extended as MobileLua evolves.
* The Lua System API, a system library with helper function for communication with C-level data types, and to help access MoSync data structures. Functions in this library are prefixed with "Sys" and most functions are implemented in C/C++.
* The MoSync API itself, which consists of functions (syscalls) and events for accessing devices services like phone, text messages, UI, OpenGL, networking, file system, location, sensors, and so on. Most functions in this library are prefixed with "ma", which was originally short for "Mobile Author", but it can also be read as short for "MoSync API". The "ma"-function are called "syscalls" (the ones that are optional and not implemented on all platforms are called "IOClts" internally, but we will just call them "syscalls" in this document). Note that the MoSync C++ libraries are not available in Lua. Instead, Lua has its own implementation of the corresponding functionality.

This document provides an overview of these APIs. Please note that MobileLua is an open source project, it is not part of the official MoSync package. Documentation and APIs are evolving organically. You are most welcome to participate in the development of MobileLua, Lua is a fantastic language.

## Lua API
This API is implemented in file [projects/common/LuaLib.lua](https://github.com/divineprog/mobilelua/blob/master/projects/common/LuaLib.lua), and must be loaded by every Lua application. This is a pure Lua API, implmeneted on top of the moSync syscalls and the Lua System API.

Here is an overview of the objects in this API.

Note that in Lua, you use a colon : when calling a method. You use a dot . when accessing a variable of an object.

### EventMonitor
This object handles MoSync events, and has methods for setting event listener functions, and for controlling the event loop. There is one global instance of this object in the system, called EventMonitor.

    -- Set function called on touch down events.
    EventMonitor:OnTouchDown(function(x, y, touchId))

    -- Set function called on touch up events.
    EventMonitor:OnTouchUp(function(x, y, touchId))

    -- Set function called on touch drag events.
    EventMonitor:OnTouchDrag(function(x, y, touchId))

    -- Set function called on key down events.
    EventMonitor:OnKeyDown(function(key))

    -- Set function called on key up events.
    EventMonitor:OnKeyUp(function(key))

    -- Set function called on sensor events.
    EventMonitor:OnSensor(function(sensorType, value1, value2, value3))

    -- Set function called on widget events.
    EventMonitor:OnWidget(function(widgetEvent))

    -- Bind a connection listener function to the given
    -- connection handle.
    EventMonitor:SetConnectionFun(
      connection, 
      function(connHandle, connOpType, connResult))

    -- Remove a connection function from the given connection handle.
    EventMonitor:RemoveConnectionFun(connection)

    -- Called for all events. Here you can trap MoSync events not 
    -- handled by the predefined event handler functions.
    EventMonitor:OnAny(function(event))

    -- Call to enter the event loop. Normally done by the
    -- C-program that loads the Lua code, after the code 
    -- is loaded.
    EventMonitor:RunEventLoop()

    -- Call to exit the event loop.
    EventMonitor:ExitEventLoop()

    -- Time to wait in maWait in the event loop. 
    -- Can be changed by the application by setting:
    -- EventMonitor.WaitTime = <value>
    EventMonitor.WaitTime

### Screen
This object is used to draw to the MoSync screen. You can use this screen to render the user interface of the application. There are several syscalls for drawing to the screen. Some of the most basic ones have methods in this object. When you use NativeUI, the MoSync screen is not visible, you then compose your UI out of NativeUI widgets. 

There is one global instance of this object in the system, called Screen.

    -- Returns width of the MoSync screen.
    Screen:Width()

    -- Returns height of the MoSync screen.
    Screen:Height()

    -- Set the current drawing color.
    Screen:SetColor(red, green, blue)

    -- Fill a rectangular area with the current color.
    Screen:FillRect(top, left, width, height)

    -- Fill entire screen with current color.
    Screen:Fill = function(self)

    -- You must call Update to redraw the screen when 
    -- it has been drawn to.
    Screen:Update()

### Connection
There is one global instance of this object in the system, called Connection. Then there are connection instance objects, that are created by calling Connection:Create(). It is the instance objects you use to do the work, connecting, reading and writing data.

    -- Method that returns a connection instance object. When using this
    -- object, you do not need to call EventMonitor:SetConnectionFun.
    -- Data that is read is zero terminated. If you are reading string data
    -- this is convenient. If you read binary data, just skip the last byte.
    Connection:Create()

A connection object instance has the following methods:

    -- Connect to the address (url) given in the connect string.
    -- If a connection is successfully established, result is > 0,
    -- and <0 on error.
    connectionObject:Connect(
        connectString, 
        function(result))

    -- Close a connection.
    connectionObject:Close()

    -- Kicks off reading the specified number of bytes.
    -- The callback function is called with a byte buffer
    -- that contains the result. Data is zero terminated. 
    -- The buffer param is nil on error. You need to free 
    -- the buffer with SysFree(buffer) when done using the 
    -- data. The result param is a result code.
    connectionObject:Read(
        numberOfBytesToRead, 
        function(buffer, result))

    -- Kicks off writing data from a byte buffer. The result param
    -- in the callback function is <0 on error. The buffer param in
    -- the callback is the same buffer as given to Write. This is
    -- convinient as you can then free the buffer, if desired, 
    -- when it is written to the connection.
    connectionObject:Write(
        buffer, 
        numberOfBytesToWrite, 
        function(buffer, result))

### NativeUI
This object makes it easy to create user interfaces that have NativeUI widgets.

There is one global instance of this object in the system, called NativeUI. There are also widget instance objects, that represent actual widgets. These objects wrap a MoSync NativeUI widget handle.

Constants (global variables):

    -- Widget size values as strings (the MAW_CONSTANT_* values
    -- are integers and cannot be used with maWidgetSetProperty).
    FILL_PARENT = ""..MAW_CONSTANT_FILL_AVAILABLE_SPACE
    WRAP_CONTENT = ""..MAW_CONSTANT_WRAP_CONTENT

Methods in the NativeUI object:

    -- Create the global NativeUI manager object.
    NativeUI = (function()

    -- Method that creates a widget. The parameter
    -- proplist is a table with widget properties.
    -- Valid property names are properties available for
    -- maWidgetSetProperty, plus "type", "parent", 
    -- "eventFun", and "data". The "data" property is
    -- user for setting custom data associated with
    -- the widget object. The widget object is a Lua
    -- object (table), it wraps a widhet handle, which
    -- identifies a Native UI widget.
    NativeUI:CreateWidget(proplist)

    -- Method that creates a button widget with some
    -- default property values.
    NativeUI:CreateButton(proplist)

    -- TODO: Add more convenience methods for creating widgets.

    -- Show a screen widget. The screen widget is a Lua object.
    NativeUI:ShowScreen(screen)

    -- Show the deafult MoSync screen.
    NativeUI:ShowDefaultScreen()

    -- Register an event function for the supplied widget handle.
    -- This method is useful if you wish to use the bare MoSync
    -- Widget API and still have the benefit of attaching event
    -- handler functions to widgets. Note that the widhetHandle
    -- parameter is a handle to a MoSync widget (it is NOT a Lua
    -- widget object). To unregister an event function, it should
    -- work to pass nil as the eventFun parameter.
    NativeUI.OnWidgetEvent(widgetHandle, function(widgetEvent))

    -- Call this method to start listening for Widget events.
    -- This could have been done right when creating the
    -- UI manager object, but since we have only one widget event
    -- listener function in EventMonitor, it will ve overwritten
    -- by the widget event listener in the LuaLive client. Then
    -- the application using NativeUI will not work.
    -- TODO: Fix this.
    NativeUI.Init()

Widget instance methods:

    -- Returns the Native UI widget handle.
    widget.GetHandle()

    -- Utility method that sets a widget property. The 
    -- value can be either a number or a string, it will
    -- be converted to a string since that is what
    -- maWidgetSetProperty wants.
    widget.SetProp(property, value)
    
    -- TODO: Add more methods as needed.

## Lua System API

The Lua System API consists of functions implemented in C/C++ that can be called from Lua. These functions enable access to platform features, and provide access to C data types and MoSync data structures. These functions are defined in file [projects/LuaLib/toluabindings/lua_systemapi.h](https://github.com/divineprog/mobilelua/blob/master/projects/LuaLib/toluabindings/lua_systemapi.h) and are implemented by the files in projects/LuaLib/src](https://github.com/divineprog/mobilelua/tree/master/projects/LuaLib/src)

The type MAHandle is an int value (a number in Lua).

    // SysScaleImage scaling types.
    #define SCALETYPE_NEAREST_NEIGHBOUR 1
    #define SCALETYPE_BILINEAR 2

    /**
     * Scale an image the the specified width and height.
     *
     * @param sourceImage The source image (left untouched).
     * @param sourceRect part of source image to scale, may be NULL.
     * @param scaledImagePlaceholder Handle that will refer to the
     * scaled image.
     * @param scaledImageWidth The width of the scaled image.
     * @param scaledImageHeight The height of the scaled.
     *
     * @return 1 on success, 0 on error (not enough memory to
     * create destination image).
     */
    int SysImageScale(
        MAHandle sourceImage, 
        MARect* sourceRect, 
        MAHandle destImagePlaceholder, 
        int scaledImageWidth, 
        int scaledImageHeight, 
        int scaleType);

    /**
     * Scale an image proportionally by a scale factor.
     *
     * @param sourceImage The source image (left untouched).
     * @param sourceRect part of source image to scale, may be NULL.
     * @param scaledImagePlaceholder Handle that will refer to the
     * scaled image.
     * @param scaleFactor The scale factor.
     *
     * @return 1 on success, 0 on error (not enough memory to
     * create destination image).
     */
    int SysImageScaleProportionally(
        MAHandle sourceImage, 
        MARect* sourceRect, 
        MAHandle destImagePlaceholder, 
        double scaleFactor, 
        int scaleType);

    // Font and text support.
    // TODO: Document how to create and obtain font object.
    // You can look in the MoSync documentation for how to create
    // fonts. Fonts are referred to by handles. Fonts are used
    // to render text to the MoSync screen. Use can also use the
    // new device font API, or use NativeUI widgets to display text.

    void* SysTextCreate(int fontHandle);
    void SysTextDelete(void* textObj);
    void SysTextSetString(void* textObj, char* str);
    void SysTextSetLineSpacing(void* textObj, int lineSpacing);
    int SysTextGetStringSize(void* textObj, int extent);
    void SysTextDrawString(void* textObj, int x, int y, int extent);

    /**
     * Allocate data.
     */
    void* SysAlloc(int size);

    /**
     * Free allocated data.
     * This function is used to free allocated data, and
     * also data structures like Events, Points and Rects.
     */
    void SysFree(void* buffer);

    /**
     * Get an int value in a memory block.
     * @param buffer Pointer to memory block.
     * @param index Offset to an integer index (as if the
     * memory block was an array of ints).
     * @return The int at the given index.
     */
    int SysBufferGetInt(void* buffer, int index);

    /**
     * Set an int value in a memory block.
     * @param buffer Pointer to memory block.
     * @param index Offset to an integer index (as if the
     * memory block was an array of ints).
     */
    void SysBufferSetInt(void* buffer, int index, int value);

    /**
     * Get a byte value in a memory block.
     * @param buffer Pointer to memory block.
     * @param index Offset to a byte index (as if the
     * memory block was an array of bytes).
     * @return The byte value at the given index.
     */
    int SysBufferGetByte(void* buffer, int index);

    /**
     * Set a byte value in a memory block.
     * @param buffer Pointer to memory block.
     * @param index Offset to a byte index (as if the
     * memory block was an array of bytes).
     */
    void SysBufferSetByte(void* buffer, int index, int value);

    /**
     * Get an float value in a memory block.
     * @param buffer Pointer to memory block.
     * @param index Offset to a float index (as if the
     * memory block was an array of floats).
     * @return The float value at the given index.
     */
    float SysBufferGetFloat(void* buffer, int index);

    /**
     * Get an double value in a memory block.
     * @param buffer Pointer to memory block.
     * @param index Offset to a double index (as if the
     * memory block was an array of doubles).
     * @return The double value at the given index.
     */
    double SysBufferGetDouble(void* buffer, int index);

    /**
     * Copy bytes from one memory block to another. The number of bytes
     * given by numberOfBytesToCopy bytes, starting at sourceIndex in 
     * the source block, will be copied to the destination block, 
     * starting at destIndex.
     * @param sourceBuffer Pointer to the source memory block.
     * @param sourceIndex Offset to a byte index in the source block.
     * @param destBuffer Pointer to the destination memory block.
     * @param destIndex Offset to a byte index in the destination block.
     * @param numberOfBytesToCopy Number of bytes that will be copied
     * from source to destination.
     */
    void SysBufferCopyBytes(
        void* sourceBuffer, 
        int sourceIndex, 
        void* destBuffer, 
        int destIndex, 
        int numberOfBytesToCopy);

    /**
     * Return a pointer to a byte at an index in a buffer.
     * This function is useful when calling functions that
     * write to memory using a pointer.
     * @param buffer Pointer to  memory block.
     * @param index Offset to a byte index.
     * @return A pointer to the byte at the given index.
     */
    void* SysBufferGetBytePointer(void* buffer, int index);

    /**
     * Get the size of an int in bytes.
     * @return The size.
     */
    int SysSizeOfInt();

    /**
     * Get the size of an int in bytes.
     * @return The size.
     */
    int SysSizeOfFloat();

    /**
     * Get the size of an int in bytes.
     * @return The size.
     */
    int SysSizeOfDouble();

    // Bit manipulation functions.
    int SysBitAnd(int a, int b);
    int SysBitOr(int a, int b);
    int SysBitXor(int a, int b);
    int SysBitShiftLeft(int a, int bits);
    int SysBitShiftRight(int a, int bits);

    // MAEvent access functions that make it easier to access event data.
    MAEvent* SysEventCreate();
    int SysEventGetType(MAEvent* event);
    int SysEventGetKey(MAEvent* event);
    int SysEventGetNativeKey(MAEvent* event);
    uint SysEventGetCharacter(MAEvent* event);
    int SysEventGetX(MAEvent* event);
    int SysEventGetY(MAEvent* event);
    int SysEventGetTouchId(MAEvent* event);
    int SysEventGetState(MAEvent* event);
    MAHandle SysEventGetConnHandle(MAEvent* event);
    int SysEventGetConnOpType(MAEvent* event);
    int SysEventGetConnResult(MAEvent* event);
    int SysEventGetTextBoxResult(MAEvent* event);
    int SysEventGetTextBoxLength(MAEvent* event);
    void* SysEventGetData(MAEvent* event);
    int SysEventSensorGetType(MAEvent* event);
    float SysEventSensorGetValue1(MAEvent* event);
    float SysEventSensorGetValue2(MAEvent* event);
    float SysEventSensorGetValue3(MAEvent* event);
    int SysEventLocationGetState(MAEvent* event);
    double SysEventLocationGetLat(MAEvent* event);
    double SysEventLocationGetLon(MAEvent* event);
    double SysEventLocationGetHorzAcc(MAEvent* event);
    double SysEventLocationGetVertAcc(MAEvent* event);
    float SysEventLocationGetAlt(MAEvent* event);
    int SysWidgetEventGetType(void* widgetEvent);
    int SysWidgetEventGetHandle(void* widgetEvent);
    int SysWidgetEventGetListItemIndex(void* widgetEvent);
    int SysWidgetEventGetChecked(void* widgetEvent);
    int SysWidgetEventGetTabIndex(void* widgetEvent);
    int SysWidgetEventGetUrlData(void* widgetEvent);

    // MAPoint2d
    MAPoint2d* SysPointCreate();
    int SysPointGetX(MAPoint2d* point);
    int SysPointGetY(MAPoint2d* point);
    void SysPointSetX(MAPoint2d* point, int x);
    void SysPointSetY(MAPoint2d* point, int y);

    // MARect
    MARect* SysRectCreate();
    int SysRectGetLeft(MARect* rect);
    int SysRectGetTop(MARect* rect);
    int SysRectGetWidth(MARect* rect);
    int SysRectGetHeight(MARect* rect);
    void SysRectSetLeft(MARect* rect, int left);
    void SysRectSetTop(MARect* rect, int top);
    void SysRectSetWidth(MARect* rect, int width);
    void SysRectSetHeight(MARect* rect, int height);

    // SMACopyData
    MACopyData* SysCopyDataCreate(MAHandle dst, int dstOffset, MAHandle src, int srcOffset, int size);

    // Screen functions.
    void SysScreenSetColor(int red, int green, int blue);
    void SysScreenDrawText(const char* text, int x, int y, void* font);

    // String functions.

    /**
     * Convert a char string to a wchar string.
     * It is the responsibility of the caller to deallocate the
     * returned string with SysFree.
     */
    void* SysStringCharToWideChar(const char* str);

    /**
     * Convert a wchar string to a char string.
     * In C it is the responsibility of the caller to deallocate the
     * returned string with SysFree. When called from Lua, a Lua string
     * will be returned.
     * Conversion only supports basic 256 char set.
     */
    char* SysStringWideCharToChar(const void* wstr);

    /**
     * Helper method that reads a text string from resource file.
     * In C it is the responsibility of the caller to deallocate the
     * returned string with SysFree. When called from Lua, a Lua string
     * will be returned, which does not need to be deallocated.
     */
    char* SysLoadStringResource(MAHandle handle);

    /*
    These Lua functions are implemented in LuaEngine.cpp.
    They are listed here for documentation purposes,
    to make the list of Lua "Sys" functions complete.

    -- Convert a null-terminated C-string pointer to
    -- by "buffer" to a Lua string.
    SysBufferToString(buffer) -> string

    -- Create a new instance of the Lua engine.
    SysLuaEngineCreate() -> ref to the engine

    -- Delete a Lua engine.
    SysLuaEngineDelete(engine) -> none

    -- Evaluate Lua code. Param code is a string.
    SysLuaEngineEval(engine, code) -> boolean
    */

## MoSync API

The [MoSync API documentation](http://www.mosync.com/files/imports/doxygen/latest/html/index.html) is available online, and locally in the MoSync IDE (select "Help/MoSync API Reference").

The documentation is generated from the file [maapi.idl](https://github.com/MoSync/MoSync/blob/master/tools/idl2/maapi.idl). The maapi.idl-file is the definitive reference for the MoSync API. If you cannot find what you look for the the web-based documentation, take a look in the idl-file. It is hard to read, but contains everything. 

Note that not all of the syscalls in maapi.idl are available in Lua. A list of everything that is available can be found in the C-binding definitions, in file [projects/LuaLib/toluabindings/lua_maapi.h](https://github.com/divineprog/mobilelua/blob/master/projects/LuaLib/toluabindings/lua_maapi.h). (The bindings are generated with a tool called tolua.)


