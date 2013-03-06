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
#include <MAInterpreter/LuaInterpreter.h>
#include <MAInterpreter/InterpreterMoblet.h>
#include <MAInterpreter/System.h>
#include <conprint.h>
#include "MAHeaders.h"

using namespace MAInterpreter;

extern "C" int MAMain()
{
	LuaInterpreter* interpreter = new LuaInterpreter();
	if (!interpreter->initialize())
	{
		return -1;
	}

	InterpreterMoblet* moblet = new InterpreterMoblet(interpreter);
	if (!moblet)
	{
		return -1;
	}

	// Important to evaluate the Lua program after the Moblet
	// has been created. The Lua code might do networking or
	// other tasks that require a Moblet to be created.
	int success = interpreter->evalResource(SCRIPT);
	if (!success)
	{
		return -1;
	}

	moblet->mainLoop();

	delete moblet;

	return 0;
};
