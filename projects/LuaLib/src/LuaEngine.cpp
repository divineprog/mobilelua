/*
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
 */

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "toluabindings/tolua.h"
#include "inc/SystemAPI.h"
}

#include <maapi.h>
#include <mastdlib.h>
#include <MAUtil/Geometry.h>
#include <MAUtil/String.h>
#include <conprint.h>

#include "inc/LuaEngine.h"

// #include <tolua/tolua.h>

// This function loads the tolua generated bindings to MoSync.
extern "C" TOLUA_API int tolua_lua_maapi_open (lua_State* tolua_S);

namespace MobileLua
{

// ========== Helper functions ==========

/**
 * Set the user data object at the given key.
 */
static void setUserData(lua_State *L, const char* key, void* data)
{
	// Push key.
	// lua_pushlightuserdata(L, (void*)&key);  // Use a C pointer as a key
	lua_pushstring(L, key);

	// Push value.
	lua_pushlightuserdata(L, data);

	// Store in register.
	lua_settable(L, LUA_REGISTRYINDEX);
}

/**
 * Get the user data object at the given key.
 */
static void* getUserData(lua_State *L, const char* key)
{
	// Push key.
	lua_pushstring(L, key);

	// Get value.
	lua_gettable(L, LUA_REGISTRYINDEX);

	// Return value.
	void* data = (void*) lua_topointer(L, -1);

	// Pop value before returning it.
	lua_pop(L, 1);

	return data;
}

/**
 * Returns true if the stack element is an integer.
 */
static bool isinteger(lua_State *L, int narg)
{
	lua_Integer d = lua_tointeger(L, narg);
	if (d == 0 && !lua_isnumber(L, narg))
	{
		return false;
	}
	else
	{
		return true;
	}
}

static LuaEngine* getLuaEngineInstance(lua_State *L)
{
    // Get pointer to engine instance from global Lua register.
    return (LuaEngine*) getUserData(L, "LuaEngineInstance");
}


/**
 * Define a global table if it does not exist.
 */
static void ensureThatGlobalTableExists(
	lua_State *L,
	const char* tableName)
{
	// Push global or nil onto the stack.
	lua_getglobal(L, tableName);

	// Does the global variable exist?
	if (lua_isnoneornil(L, -1))
	{
		// It does not exist. Push new table onto stack.
		lua_newtable(L);

		// Define it as a global variable. This pops the table off the stack.
		lua_setglobal(L, tableName);
	}

	// Important to pop the initial global element.
	lua_pop(L, 1);
}

static void RegTableFun(
	lua_State* L,
	const char* tableName,
	const char* funName,
	lua_CFunction funPointer)
{
	ensureThatGlobalTableExists(L, tableName);

	// Push table onto stack.
	lua_getglobal(L, tableName);

	// Push table key.
	lua_pushstring(L, funName);

	// Push value.
	lua_pushcfunction(L, funPointer);

	// Set table entry. Pops value and key.
	lua_rawset(L, -3);

	// Pop table off the stack.
	lua_pop(L, 1);
}

static void RegFun(
	lua_State* L,
	const char* funName,
	lua_CFunction funPointer)
{
	lua_pushcfunction(L, funPointer);
	lua_setglobal(L, funName);
}

// ========== Implementation of Lua primitives ==========

/**
 * Print to console, e.g. the logcat output on Android.
 */
static int luaLog(lua_State *L)
{
	const char* message = luaL_checkstring(L, 1);
	lprintfln("%s", message);
	return 0; // Number of results
}

/**
 * Print to the device screen (and also to the console on e.g. Android).
 */
static int luaPrint(lua_State *L)
{
	const char* message = luaL_checkstring(L, 1);
	printf("%s\n", message);
	return 0; // Number of results
}

/**
 * Convert the contents of a zero terminated
 * string pointer (char*) to a Lua string.
 */
static int luaBufferToString(lua_State *L)
{
	// First param is pointer to text buffer, must not
	// be nil and must be light user data.
	if (!lua_isnoneornil(L, 1) && lua_islightuserdata(L, 1))
	{
		char* text = (char*) lua_touserdata(L, 1);
		if (NULL != text)
		{
			// This copies the text.
			lua_pushstring(L, text);
		}
	}

	return 1; // Number of results
}

/**
 * Convert a Lua string to a string pointer (char*).
 */
static int luaStringToBuffer(lua_State *L)
{
	// Get pointer to Lua string.
	const char* s = luaL_checkstring(L, 1);

	// Allocate new string buffer.
	int size = strlen(s);
	char* s2 = (char*) malloc(sizeof(char) * size);

	// Copy to buffer.
	strcpy(s2, s);

	// Return buffer pointer to Lua.
	lua_pushlightuserdata(L, s2);

	return 1; // Number of results
}

/**
 * Helper function that escapes a string.
 */
static MAUtil::String EscapeHelper(const MAUtil::String& str)
{
	// The encoded string.
	MAUtil::String result = "";
    char buf[8];

    for (int i = 0; i < str.length(); ++i)
    {
    	char c = str[i];
        if ((48 <= c && c <= 57) ||  // 0-9
            (65 <= c && c <= 90) ||  // a..z
            (97 <= c && c <= 122))   // A..Z
        {
        	result.append(&str[i], 1);
        }
        else
        {
        	result += "%";
            sprintf(buf, "%02X", str[i]);
            result += buf;
        }
    }

    return result;
}

/**
 * Helper function that unescapes a string.
 */
static MAUtil::String UnescapeHelper(const MAUtil::String& str)
{
	// The decoded string.
	MAUtil::String result = "";

	for (int i = 0; i < str.length(); ++i)
	{
		// If the current character is the '%' escape char...
		if ('%' == (char) str[i])
		{
			// Get the char value of the two digit hex value.
			MAUtil::String hex = str.substr(i + 1, 2);
			long charValue = strtol(
				hex.c_str(),
				NULL,
				16);
			// Append to result.
			result += (char) charValue;

			// Skip over the hex chars.
			i += 2;
		}
		else
		{
			// Not encoded, just copy the character.
			result += str[i];
		}
	}

	return result;
}

/**
 * Decodes a "percent encoded" Lua string (like
 * the Javascript unescape function).
 */
static int luaStringUnescape(lua_State *L)
{
	// Get string param (escaped url).
	const char* escapedString = luaL_checkstring(L, 1);

	MAUtil::String unescapedString = UnescapeHelper(escapedString);

	// This copies the string to a Lua string.
	lua_pushstring(L, unescapedString.c_str());

	return 1; // Number of results
}

/**
 * Encodes a Lua string using "percent encoding" (like
 * the Javascript escape function).
 */
static int luaStringEscape(lua_State *L)
{
	// Get string param (escaped url).
	const char* unescapedString = luaL_checkstring(L, 1);

	MAUtil::String escapedString = EscapeHelper(unescapedString);

	// This copies the string to a Lua string.
	lua_pushstring(L, escapedString.c_str());

	return 1; // Number of results
}

/**
 * Create a new Lua engine instance.
 * Currently does no error checking (update
 * this comment if that is added).
 */
static int luaEngineCreate(lua_State *L)
{
	LuaEngine* engine = new LuaEngine();
	engine->initialize();
	lua_pushlightuserdata(L, engine);

	return 1; // Number of results
}

/**
 * Delete a Lua engine instance.
 */
static int luaEngineDelete(lua_State *L)
{
	// First param is pointer to the engine, it must not
	// be nil and must be light user data.
	if (!lua_isnoneornil(L, 1) && lua_islightuserdata(L, 1))
	{
		LuaEngine* engine = (LuaEngine*) lua_touserdata(L, 1);
		if (NULL != engine)
		{
			delete engine;
		}
	}

	return 0; // Number of results
}

/**
 * Evaluate Lua code.
 */
static int luaEngineEval(lua_State *L)
{
	// First param is pointer to the engine, it must not
	// be nil and must be light user data.
	if (!lua_isnoneornil(L, 1) && lua_islightuserdata(L, 1))
	{
		LuaEngine* engine = (LuaEngine*) lua_touserdata(L, 1);
		if (NULL != engine)
		{
			const char* code = luaL_checkstring(L, 2);
			int result = engine->eval(code);
			if (0 != result)
			{
				// Return true to Lua.
				lua_pushboolean(L, 1);
				return 1; // Number of results
			}
		}
	}

	// Return false to Lua.
	lua_pushboolean(L, 0);
	return 1; // Number of results
}

static void registerNativeFunctions(lua_State* L)
{
	RegFun(L, "print", luaPrint);
	RegFun(L, "log", luaLog);
	RegTableFun(L, "mosync", "SysBufferToString", luaBufferToString);
	RegTableFun(L, "mosync", "SysStringToBuffer", luaStringToBuffer);
	RegTableFun(L, "mosync", "SysStringUnescape", luaStringUnescape);
	RegTableFun(L, "mosync", "SysStringEscape", luaStringEscape);
	RegTableFun(L, "mosync", "SysLuaEngineCreate", luaEngineCreate);
	RegTableFun(L, "mosync", "SysLuaEngineDelete", luaEngineDelete);
	RegTableFun(L, "mosync", "SysLuaEngineEval", luaEngineEval);
}

// ========== Constructor/Destructor ==========

/**
 * Constructor.
 */
LuaEngine::LuaEngine() :
	mLuaState(NULL),
	mLuaErrorListener(NULL)
{
}

/**
 * Destructor.
 */
LuaEngine::~LuaEngine()
{
	shutdown();
}

// ========== Methods ==========

///**
// * High-level entry point for executing a Lua script.
// * Initializes the Lua interpreter, then evaluates the code
// * in the script and enters the event loop. Cleans up after
// * the event loop exits.
// * @param script String with Lua code.
// * @return Non-zero if successful, zero on error.
// */
//int LuaEngine::run(const char* script)
//{
//	if (!initialize())
//	{
//		return -1;
//	}
//
//	// Load Lua library functions in the first resource handle.
//	if (!eval(1))
//	{
//		return -1;
//	}
//
//	// Load and run the application.
//	if (!eval(script))
//	{
//		return -1;
//	}
//
//	// TODO: Enter main event loop.
//}
//
///**
// * High-level entry point for executing a Lua script contained
// * in a resource handle.
// * Initializes the Lua interpreter, then evaluates the code
// * in the script and enters the event loop. Cleans up after
// * the event loop exits.
// * @param scriptResourceId Handle to data object with Lua code,
// * typically a resource id.
// * @return Non-zero if successful, zero on error.
// */
//int LuaEngine::run(MAHandle scriptResourceId)
//{
//	// TODO: Implement.
//}

/**
 * Initialize the Lua engine.
 * @return Non-zero if successful, zero on error.
 */
int LuaEngine::initialize()
{
	lua_State* L = (lua_State*) mLuaState;

	// Deallocate previous Lua state, if it exists.
	if (L)
	{
		lua_close(L);
		mLuaState = NULL;
	}

	// Create Lua state.
	L = lua_open();
	mLuaState = L;
	if (!L)
	{
		return 0;
	}

	luaL_openlibs(L);

	tolua_lua_maapi_open(L);

	registerNativeFunctions(L);

	// Now we save a pointer to the engine instance in the
	// global Lua register.
	setUserData(L, "LuaEngineInstance", (void*) this);

	return 1;
}

/**
 * Shutdown the Lua engine.
 */
void LuaEngine::shutdown()
{
	lua_State* L = (lua_State*) mLuaState;

	if (L)
	{
		lua_close(L);
		mLuaState = NULL;
	}

	// TODO: Free function closures.
	// We can skip this as we close the entire interpreter, but
	// remember to free old functions when new ones are set.
}

/**
 * Evaluate a Lua script.
 * @param script String with Lua code.
 * @return Non-zero if successful, zero on error.
 */
int LuaEngine::eval(const char* script)
{
	lua_State* L = (lua_State*) mLuaState;

	// Create temporary script string with an ending space.
	// There seems to be a bug in Lua when evaluating
	// statements like:
	//   "return 10"
	//   "x = 10"
	// But this works:
	//   "return 10 "
	//   "return (10)"
	//   "x = 10 "
	int length = strlen(script);
	char* s = (char*) malloc(length + 2);
	strcpy(s, script);
	s[length] = ' ';
	s[length + 1] = 0;

	// Evaluate Lua script.
	int result = luaL_dostring(L, s);

	// Free temporary script string.
	free(s);

	// Was there an error?
	if (0 != result)
	{
		MAUtil::String errorMessage;

    	if (lua_isstring(L, -1))
    	{
    		errorMessage = lua_tostring(L, -1);

            // Pop the error message.
        	lua_pop(L, 1);
    	}
    	else
    	{
    		errorMessage =
    			"There was a Lua error condition, but no error message.";
    	}

        lprintfln("Lua Error: %s\n", errorMessage.c_str());

    	// Print size of Lua stack (debug info).
    	lprintfln("Lua stack size: %i\n", lua_gettop(L));

    	reportLuaError(errorMessage.c_str());
	}

	return result == 0;
}

/**
 * Helper method that evaluates a Lua script contained in
 * a resource handle.
 * @param scriptResourceId Handle to data object with Lua code,
 * typically a resource id.
 * @return Non-zero if successful, zero on error.
 */
int LuaEngine::eval(MAHandle handle)
{
	char* script = SysLoadStringResource(handle);
	if (script)
	{
		int result = eval(script);
		free(script);
		return result;
	}
	else
	{
		return 0;
	}
}

/**
 * Set a listener that will get notified when there is a
 * Lua error.
 */
void LuaEngine::setLuaErrorListener(LuaErrorListener* listener)
{
	mLuaErrorListener = listener;
}

/**
 * Called to report a Lua error (for private use, really).
 */
void LuaEngine::reportLuaError(const char* errorMessage)
{
	if (NULL != mLuaErrorListener)
	{
		mLuaErrorListener->onError(errorMessage);
	}
}

}

