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

#ifndef MOBILELUA_LUAENGINE_H
#define MOBILELUA_LUAENGINE_H

#include <mawstring.h>
#include <MAUtil/HashMap.h>
#include <MAUtil/String.h>
#include <MAUI/Font.h>

#include "LuaErrorListener.h"

// To get the macro LUA_DEFINE_ERRNO
#include "../lua/inc/errno.h"

namespace MobileLua
{

/**
 * Function pointer type for functions that are
 * called from Lua. This type is here to avoid
 * forcing a Lua app to include Lua header files.
 * You still need to include Lua header files when
 * making your own bindings. This is just to make
 * the binding methods build happily without them.
 * @param L The Lua State (of type lua_State).
 * @return Number of return values.
 */
typedef int (*LUA_FUNCTION) (void* L);


/**
 * Wrapper for the Lua interpreter.
 */
class LuaEngine
{
public:

	/**
	 * Constructor.
	 */
	LuaEngine();

	/**
	 * Destructor.
	 */
	virtual ~LuaEngine();

//	/**
//	 * High-level entry point for executing a Lua script.
//	 * Initializes the Lua interpreter, then evaluates the code
//	 * in the script and enters the event loop. Cleans up after
//	 * the event loop exits.
//	 * @param script String with Lua code.
//	 * @return Non-zero if successful, zero on error.
//	 */
//	virtual int run(const char* script);
//
//	/**
//	 * High-level entry point for executing a Lua script contained
//	 * in a resource handle.
//	 * Initializes the Lua interpreter, then evaluates the code
//	 * in the script and enters the event loop. Cleans up after
//	 * the event loop exits.
//	 * @param scriptResourceId Handle to data object with Lua code,
//	 * typically a resource id.
//	 * @return Non-zero if successful, zero on error.
//	 */
//	virtual int run(MAHandle scriptResourceId);

	/**
	 * Initialize the Lua engine.
	 * @return Non-zero if successful, zero on error.
	 */
	virtual int initialize();

	/**
	 * Shutdown the Lua engine.
	 */
	virtual void shutdown();

	/**
	 * Evaluate a Lua script.
	 * @param script String with Lua code.
	 * @return Non-zero if successful, zero on error.
	 */
	virtual int eval(const char* script);

	/**
	 * Helper method that evaluates a Lua script contained in
	 * a resource handle.
	 * @param scriptResourceId Handle to data object with Lua code,
	 * typically a resource id.
	 * @return Non-zero if successful, zero on error.
	 */
	virtual int eval(MAHandle scriptResourceId);

	void registerGlobalTableFunction(
		const char* tableName,
		const char* funName,
		LUA_FUNCTION funPointer);

	void registerGlobalFunction(
		const char* funName,
		LUA_FUNCTION funPointer);

	/**
	 * Set a listener that will get notified when there is a
	 * Lua error.
	 */
	virtual void setLuaErrorListener(LuaErrorListener* listener);

	/**
	 * Called to report a Lua error (for private use, really).
	 */
	virtual void reportLuaError(const char* errorMessage);

public:
	/**
	 * The Lua execution state (using void* rather than
	 * lua_State* to avoid including lua.h, since this file
	 * is includes in application code).
	 */
	void* mLuaState;

	/**
	 * Last Lua error message.
	 */
	MAUtil::String mLastLuaErrorMessage;

	/**
	 * Listener called when a Lua error occurs.
	 */
	LuaErrorListener* mLuaErrorListener;
};

}

#endif
