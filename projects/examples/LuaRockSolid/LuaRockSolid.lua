--[[
 * Copyright (c) 2012 MoSync AB
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

  File: LuaRockSolid.lua
  Author: Mikael Kindborg

--]]

-- The application object.
LuaRockSolid = {}

LuaRockSolid.Main = function(self)
  -- We want to app to exit on devices that have a back button.
  mosync.EventMonitor:OnKeyDown(function(key)
    if mosync.MAK_BACK == key then
      mosync.maExit(0)
    end
  end)
  
  -- Create the user interface widgets and the HTML code
  -- for the UI.
  self:CreateUI()
  self:CreateHTML()
  
  -- Display the main screen.
  mosync.NativeUI:ShowScreen(self.Screen)
  
  -- Set up the sensor callback function.
  self:SetUpSensor()
  
  -- Enter the event loop.
  mosync.EventMonitor:RunEventLoop()
end

LuaRockSolid.SetUpSensor = function(self)
  self.mCaptureSensor = false
  mosync.EventMonitor:OnSensor(function(type, x, y, z)
    if self.mCaptureSensor then
      local ax = math.abs(x)
      local ay = math.abs(y)
      local az = math.abs(z)
      -- Last sensor values must have been initialized.
      if self.mLastSensorValue[1] ~= 0 then
        -- Update accumulated values
        local lx = self.mLastSensorValue[1];
        local ly = self.mLastSensorValue[2];
        local lz = self.mLastSensorValue[3];
        local dx = math.abs(lx - ax)
        local dy = math.abs(ly - ay)
        local dz = math.abs(lz - az)
        self.mAccumulatedSensorValue[1] = self.mAccumulatedSensorValue[1] + dx
        self.mAccumulatedSensorValue[2] = self.mAccumulatedSensorValue[2] + dx
        self.mAccumulatedSensorValue[3] = self.mAccumulatedSensorValue[3] + dx
      end
      -- Set last known values.
      self.mLastSensorValue[1] = ax
      self.mLastSensorValue[2] = ay
      self.mLastSensorValue[3] = az
    end
  end)
end

-- Start accelerometer
LuaRockSolid.SensorStart = function(self)
  self.mAccumulatedSensorValue = {0, 0, 0}
  self.mLastSensorValue = {0, 0, 0}
  self.mCaptureSensor = true
  mosync.maSensorStart(mosync.SENSOR_TYPE_ACCELEROMETER, mosync.SENSOR_RATE_UI)
end

LuaRockSolid.SensorStop = function(self)
  self.mCaptureSensor = false
  mosync.maSensorStop(mosync.SENSOR_TYPE_ACCELEROMETER)
  local result = 
    self.mAccumulatedSensorValue[1] +
    self.mAccumulatedSensorValue[2] +
    self.mAccumulatedSensorValue[3]
  self.WebView:EvalJS("DisplayResult("..result..")")
end

LuaRockSolid.PlaySound = function(self, resourceId)
  mosync.maSoundPlay(resourceId, 0, mosync.maGetDataSize(resourceId))
end

LuaRockSolid.CreateUI = function(self)
  self.Screen = mosync.NativeUI:CreateScreen
  {
  }
  self.WebView = mosync.NativeUI:CreateWebView
  {
    parent = self.Screen,
    enableZoom = "true"
  }
end

LuaRockSolid.CreateHTML = function(self)
   self.WebView:SetProp(mosync.MAW_WEB_VIEW_HTML,
[==[
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=320, user-scalable=no">
<style type="text/css">
html, body {
  margin: 5px;
  padding: 0px;
  width: 100%;
  /*height: 100%;*/
  background-color: #FFFFFF;
  font-family: sans-serif;
  text-decoration: none;

  /* Disable text selection. */
  -webkit-touch-callout: none;
  -webkit-user-select: none;
  -khtml-user-select: none;
  -moz-user-select: none;
  -ms-user-select: none;
  -o-user-select: none;
  user-select: none;
}

.instruction-block {
  display: block;
  clear: both;
  margin: 5px 0px 10px 0px;
  font-size: 18px;
  background: #0000FF;
}

.instruction-item {
  display: inline-block;
  float: left;
  width: 260px;
  margin: 5px 0px 5px 10px;
}

#heading {
  font: 32px Arial, sans-serif;
  text-align: center;
  font-weight: bold;
  margin: 0px 0px 5px 0px;
}

#instruction {
}

#introduction {
  font: 20px Arial, sans-serif;
  margin: 0px 0px 5px 0px;
}

#button-block {
  display: block;
  margin: 10px 0px 5px 0px;
}

#result-block {
  display: block;
  font: 20px Arial, sans-serif;
  font-weight: bold;
  margin: 10px 0px 5px 0px;
}

#result-explanation {
  display: block;
  font: 20px Arial, sans-serif;
  margin: 10px 0px 5px 0px;
}

.button {
  display: block;
  border: 1px solid #222222;
  text-align: center;
  background: #15D2FF;
  color: #222222;
  font-size: 18px;
  font-weight: bold;
  -webkit-border-radius: 8px;
  -moz-border-radius: 8px;
  border-radius: 8px;
  width: 280px;
  padding: 20px;
  margin: 10px 0px 10px 0px;
  /*height: 70px;*/
  padding: 6px;
  cursor: pointer;
}

.number-circle {
  display: inline-block;
  float: left;
  clear: left;
  
  -webkit-border-radius: 999px;
  -moz-border-radius: 999px;
  border-radius: 999px;
  behavior: url(PIE.htc);

  width: 20px;
  height: 20px;
  padding: 3px;
  margin: 0px 0px 0px 0px;

  background: #FFFFFF;
  border: 2px solid #000000;
  color: #000000;
  text-align: center;

  font: 18px Arial, sans-serif;
}
</style>
</head>
<body>
<div id="screen-one">
  <div id="heading">RockSolid!</div> 
  <div id="instruction">
    <div id="introduction">Are you RockSolid? Test how steady your hand is!</div>
    <!--<div class="instruction-block">
      <div class="number-circle">1</div>
      <div class="instruction-item">
        <div style="display: inline-block; margin-right: 5px">Press</div>
        <div class="button" onclick="PlayGame()">Start</div>
      </div>
    </div>
    -->
    <div class="instruction-block">
      <div class="number-circle" style="float: left;">1</div>
      <div class="instruction-item">
        Turn on sound.
      </div>
    </div>
    <div class="instruction-block">
      <div class="number-circle" style="float: left;">2</div>
      <div class="instruction-item">
        Hold the phone in your hand and extend your arm.
      </div>
    </div>
    <div class="instruction-block">
      <div class="number-circle" style="float: left;">3</div>
      <div class="instruction-item">
        Press the Start button below.
      </div>
    </div>
    <div class="instruction-block">
      <div class="number-circle">4</div>
      <div class="instruction-item">
        After two seconds shake detection starts!
      </div>
    </div>
    <div class="instruction-block">
      <div class="number-circle">5</div>
      <div class="instruction-item">
        Hold steady for 60 seconds until told to relax!
      </div>
    </div>
    <div class="instruction-block">
    </div>
  </div>
  <div></div>
  <div id="button-block">
    <div class="button" onclick="PlayGame()">Start</div>
  </div>
  <div id="result-block">
    Your shakiness is: <div style="display: inline-block;" id="result">?</div>
  </div>
  <div id="result-explanation">
    The lower shakiness, the steadier you are!
  </div>
</div>
<script>
]==] .. mosync.NativeUI:GetMoSyncBridgeJSScript() .. [==[
function PlayGame()
{
  // Five seconds from now sensor capture will start.
  console.log("Starting game")
  setTimeout(function() {
    EvalLua("LuaRockSolid:PlaySound(3)")
    EvalLua("LuaRockSolid:SensorStart()")
    console.log("Starting sensor")
  }, 2000)
  setTimeout(function() {
    EvalLua("LuaRockSolid:PlaySound(5)")
  }, 2000 + 10000)
  setTimeout(function() {
    EvalLua("LuaRockSolid:PlaySound(6)")
  }, 2000 + 20000)
  setTimeout(function() {
    EvalLua("LuaRockSolid:PlaySound(7)")
  }, 2000 + 30000)
  setTimeout(function() {
    EvalLua("LuaRockSolid:PlaySound(8)")
  }, 2000 + 40000)
  setTimeout(function() {
    EvalLua("LuaRockSolid:PlaySound(9)")
  }, 2000 + 50000)
  setTimeout(function() {
    console.log("Stopping sensor")
    EvalLua("LuaRockSolid:SensorStop()")
    EvalLua("LuaRockSolid:PlaySound(4)")
  }, 2000 + 60000)
}

function DisplayResult(result)
{
  // Display adjusted result.
  console.log("Result: " + result)
  var element = document.getElementById("result")
  var index = Math.round((result - 0.5) * 10)
  console.log("Index: " + index)
  element.innerHTML = index
}

function EvalLua(script)
{
  mosync.bridge.sendRaw(escape(script))
}
</script>
</body>
</html>
]==])
end

-- Start the program
LuaRockSolid:Main()

