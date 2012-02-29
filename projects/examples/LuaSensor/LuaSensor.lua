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
File: LuaSensor.lua
Author: Mikael Kindborg
Date: 2011-10-12

Demo of the accelerometer sensor.
Move the device to change color or the screen.
The result is not that pretty, the app can be improved!

Tested on Android.
]]

-- Start the accelerometer sensor (this sensor has id 1,
-- the second parameter (-1) gives us a medium-high update frequency.
local result = mosync.maSensorStart(1, -2)
if 0 ~= result then 
  mosync.maPanic(0, "Sensor failed to start") 
end

-- Register sensor listener that draws the screen based
-- on sensor values.
mosync.EventMonitor:OnSensor(function(type, x, y, z)
  local red = ((x * 255) / 10) % 255
  local green = (y * 255) % 255
  local blue = (y * 255) % 255
  mosync.Screen:SetColor(red, green, blue)
  mosync.Screen:Fill()
  mosync.Screen:Update()
end)

-- Exit when any key is pressed.
mosync.EventMonitor:OnKeyDown(function(keyCode)
  mosync.maSensorStop(1)
  mosync.EventMonitor:ExitEventLoop()
end)
