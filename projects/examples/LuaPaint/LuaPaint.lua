--[[
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
--]]

--[[
File: LuaPaint.lua
Author: Mikael Kindborg
Date: 2011-08-31

Very simple paint demo application. Supports multi-touch.

Tested in MoRE and on Android.
--]]

-- Fill mosync.Screen with background color.
mosync.Screen:SetColor(255, 255, 255)
mosync.Screen:Fill()
mosync.Screen:Update()

-- Function that paints a "brush stamp" on the mosync.Screen.
function Paint(x, y, touchId)
  if touchId == 0 then 
    mosync.Screen:SetColor(0, 0, 0) 
  else
    mosync.Screen:SetColor(0, 200, 0) 
  end
  mosync.Screen:FillRect(x - 20, y - 20, 40, 40)
  mosync.Screen:Update()
end

-- Bind the Paint function to touch events.
mosync.EventMonitor:OnTouchDown(Paint)
mosync.EventMonitor:OnTouchDrag(Paint)

-- Exit when any key is pressed.
mosync.EventMonitor:OnKeyDown(function(keyCode)
  mosync.EventMonitor:ExitEventLoop()
end)
