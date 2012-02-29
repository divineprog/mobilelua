-- Experimental code that stress test sensors.
-- Run this code interactively by selecting a section
-- at a time and click "Run selection", or run it all
-- by clicking "Run all". The app should not crash.
-- Inspect output log to verify that sensors work.

mosync.EventMonitor:OnSensor(function(sensor, x, y, z)
  log(sensor .. " " .. x .. " " .. y .. " " .. z)
end)

for i = 1, 100 do
  for sensor = 1, 5 do
    mosync.maSensorStart(sensor, -2)
  end
  for sensor = 1, 5 do
    mosync.maSensorStop(sensor)
  end
end

for i = 1, 100 do
  for sensor = 1, 5 do
    mosync.maSensorStart(sensor, -2)
  end
end

for i = 1, 100 do
  for sensor = 1, 5 do
    mosync.maSensorStop(sensor)
  end
end
