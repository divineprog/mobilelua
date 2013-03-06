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
 
Program name: 

  LuaLiveEditor

Description:

  This program is a Live Lua editor for use with the MobileLua Live Client
  application. Download this app for Android on www.mobilelua.org.

  If you want to build the client app for another platform you need the
  MoSync development tool, which can be downloded from www.mosync.com.

  The editor starts a server that the client app connects to. It is
  possible for multiple clients to connect to the server.
 
  Note that both the machine running the editor, and the mobile device
  running the client app, must be on the same network.
 
How to use:

  Start the editor by running LuaLiveEditor.bat (on Windows). On other
  platforms, launch Java with the jar file LuaLiveEditor.jar.

  Then launch the Lua Live Client on your mobile device. A text field
  for entering the ip-address of the machine running the editor is
  displayed. This address is displayed in the editor, on the button bar.
 
  Evaluate Lua code by clicking "Run program" (runs all code in the editor)
  or by selecting code and clicking "Do selection" (runs only the selected 
  code). In this way you can incremetally program your device using Lua.
 
  Lua can access most of the functions in the MoSync Syscall API. 
  See www.mosync.com for documentation of this API. Lua can not access
  the MoSync C++ class libraries. Instead there are Lua libraries
  providing this functionality (these libraries are under development). 
 
  The right-hand pane of the editor contains experimental GUI-editing 
  tools that are not yet documented.
 
  Have fun! Interactive programming is wonderful!
 
Credit:

  The inspiration for LuaLive comes from the Smalltalk programming 
  environment. See www.smalltalk.org, and www.squeak.org
 
  Lua home page: www.lua.org
 
  Home page for the RSyntaxTextArea text editor component:
  fifesoft.com/rsyntaxtextarea/

Contact:

  mikael.kindborg@mosync.com