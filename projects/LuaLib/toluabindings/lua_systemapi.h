/*
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
 */

// This file contains function declarations for use with tolua.
// The functions defined here are add-ons to the MoSync syscalls,
// to eanble to do things like manipulating memory from Lua.

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
int SysImageScale(MAHandle sourceImage, MARect* sourceRect, MAHandle destImagePlaceholder, int scaledImageWidth, int scaledImageHeight, int scaleType);

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
int SysImageScaleProportionally(MAHandle sourceImage, MARect* sourceRect, MAHandle destImagePlaceholder, double scaleFactor, int scaleType);

// Font and text support.

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
void SysBufferCopyBytes(void* sourceBuffer, int sourceIndex, void* destBuffer, int destIndex, int numberOfBytesToCopy);

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

// Create struct MACopyData.
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

-- Create a new Lua string from a null-terminated
-- C-string pointed to by "buffer".
-- Return Lua string on success, nil on error.
SysBufferToString(buffer) --> string

-- Copy contents of a Lua string to a C-buffer
-- pointed to by "buffer".
-- Does NOT copy the terminating null character.
-- Return true on success, false on error.
SysStringToBuffer(string, buffer) --> boolean

-- Search from back of string for substring until
-- end of string. Return last found start index.
-- Note that this function is defined in LuaLib.lua
mosync.SysStringFindLast(str, subStr)

-- Decodes a "percent encoded" Lua string (like
-- the Javascript unescape function).
mosync.SysStringUnescape(string) --> string

-- Encodes a Lua string using "percent encoding" (like
-- the Javascript escape function).
mosync.SysStringEscape(string) --> string

-- Create a new instance of the Lua engine.
SysLuaEngineCreate() -> ref to the engine

-- Delete a Lua engine.
SysLuaEngineDelete(engine) -> none

-- Evaluate Lua code. Param code is a string.
SysLuaEngineEval(engine, code) -> boolean
*/
