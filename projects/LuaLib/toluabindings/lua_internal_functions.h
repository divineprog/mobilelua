// These are functions that are defined and implemented
// by the Lua engine, in file LuaEngine.cpp. All these
// functions are in the "mosync" Lua name space.
//
// The following declarations are meant to be used by
// tools that produce documentation support, like the
// ZeroBrane Studio IDE.
//
// This file is not included in any C implementation files.

/**
 * Create an object the represents a size (width and height).
 * @param x The width value of the extent.
 * @param y The width value of the extent.
 * @return An extent object (a 32-bit int with x and y packed as 16-bit values).
 */
MAExtent EXTENT(int x, int y);

/**
 * Create a new Lua string from a null-terminated
 * C-string pointed to by "buffer".
 * @param buffer Buffer that contains string data.
 * @return Lua string on success, nil on error.
 */
char* SysBufferToString(void* buffer);

/**
 * Copy contents of a Lua string to a C-buffer
 * pointed to by "buffer".
 * Does NOT copy the terminating null character.
 * @param string String object.
 * @param buffer Buffer to receive string data.
 * @return true on success, false on error.
 */
int SysStringToBuffer(char* string, void* buffer);

/**
 * Search from back of string for substring until
 * end of string and return last found start index.
 * Note that this function is defined in LuaLib.lua
 * @param str String to search in.
 * @param subStr String to look for.
 * @return The index of the start of the last occurence
 * of subStr.
 */
int SysStringFindLast(char* str, char* subStr);

/**
 * Decodes a "percent encoded" Lua string (like
 * the Javascript unescape function).
 * @param string String to unescape.
 * @return Decoded string.
 */
char* SysStringUnescape(char* string);

/**
 * Encodes a Lua string using "percent encoding" (like
 * the Javascript escape function).
 * @param string String to escape.
 * @return Encoded string.
 */
char* SysStringEscape(char* string);

/**
 * Create a new instance of the Lua engine.
 * Note: Experimental function, not tested.
 * @return Pointer to the new engine object.
 */
void* SysLuaEngineCreate();

/**
 * Delete a Lua engine.
 * Note: Experimental function, not tested.
 * @param engine Pointer to the engine object.
 */
void* SysLuaEngineDelete(void* engine);

/**
 * Evaluate Lua code in a Lua engine.
 * Note: Experimental function, not tested.
 * @param engine Pointer to the engine object.
 * @param code String with Lua code to eval. 
 * @return true on suvvecc, false on error.
 */
int SysLuaEngineEval(void* engine, char* code);
