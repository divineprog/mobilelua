---------------------------------------------------
-- Welcome to the Wonderful World of Mobile Lua! --
--                                               --
-- Experimental sensor demo.                     --
---------------------------------------------------

-- Set function to be called on sensor events.
mosync.EventMonitor:OnSensor(function(type, x, y, z)
  log("OnSensor " .. x .. " " .. y .. " " .. z)
  local red = ((x * 255) / 10) % 255
  local green = (y * 255) % 255
  local blue = (y * 255) % 255
  mosync.Screen:SetColor(red, green, blue)
  mosync.Screen:Fill()
  mosync.Screen:Update()
end)

-- Start the accelerometer sensor.
local result = mosync.maSensorStart(1, -2)
if result == 0 then
  log("Sensor successfullt started")
else
  log("Sensor not started")
end

-- Stop sensor when screen is touched.
mosync.EventMonitor:OnTouchDown(function()
  mosync.maSensorStop(1)
end)
