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

#include <ma.h>
#include "LuaEngine.h"
#include "MAHeaders.h"

#include <conprint.h>

// Define the global variable errno.
LUA_DEFINE_ERRNO

// Lua interpreter takes some time to load,
// so we draw a splash screen initially.
//
void ShowSplashScreen()
{
	int screenSize = maGetScrSize();
	int screenWidth = EXTENT_X(screenSize);
	int screenHeight = EXTENT_Y(screenSize);

	int imageSize = maGetImageSize(SPLASH);
	int imageWidth = EXTENT_X(imageSize);
	int imageHeight = EXTENT_Y(imageSize);

	int imageX = (screenWidth - imageWidth) / 2;
	int imageY = (screenHeight - imageHeight) / 2;

	maSetColor(0x2288FF);
	maFillRect(0, 0, screenWidth, screenHeight);

	maDrawImage(SPLASH, imageX, imageY);

	maUpdateScreen();
}

extern "C" int MAMain()
{
	ShowSplashScreen();

	// Create the Lua engine.
	MobileLua::LuaEngine engine;
	if (!engine.initialize())
	{
		return -1;
	}

	// Load Lua library functions.
	engine.eval(LUALIB);

	// Load and run the application.
	engine.eval(LUAPLAY);

	// Enter the MoSync event loop.
	// RunEventLoop is defined in LuaLib.lua.
	engine.eval("mosync.EventMonitor:RunEventLoop()");

	return 0;
}

