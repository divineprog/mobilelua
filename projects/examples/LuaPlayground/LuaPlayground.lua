print("Hello World")

---[[
-- Application object.
local app = {}

app.Url = ""

print("1")

-- Open TextBox to enter URL to Lua code to run.
app.OpenUrlTextBox = function(self)
  mosync.SysOpenTextBox(
    "Enter URL",
    "http://divineprog.se/", mosync.MA_TB_TYPE_URL, 255,
    function(url)
      if nil == url then
        print("URL: nil!")
      else
        print("URL: " .. url)
        self.Url = url
        self:LoadAndRun()
      end
    end)
end
print("2")


-- Load and run Lua code from current URL.
app.LoadAndRun = function(self)
  -- Check that Url has some data.
  if #self.Url < 4 then
    return
  end
  
  -- Load the code and evaluate it.
  self:LoadUrl(self.Url, function(code) 
    if nil == code then
      print("Could not get Lua code")
    else
      self:EvalLuaCode(code)
    end
  end)
end
print("3")

app.LoadUrl = function(self, url, callbackFun)
  local connection = mosync.Connection:HttpCreate()
  connection:WhenDone(function(data, result)
    if nil == data then
      print("Could not download data from:")
      print(url)
      callbackFun(nil)
    else
      -- Zero terminate C string buffer and get a Lua string.
      mosync.SysBufferSetByte(data, result, 0)
      local text = mosync.SysBufferToString(data)
      mosync.SysFree(data)
      callbackFun(text)
    end
    connection:Close()
  end)
  connection:Get(url)
end
print("4")

app.EvalLuaCode = function(self, code)
  local fun, parseError = loadstring(code)
  if nil == fun then
    print("Lua Parse Error:")
    print(parseError)
    mosync.maMessageBox("Lua Error", parseError)
    return
  end
  
  -- Hide the native UI and show the MoSync drawing screen.
  maWidgetScreenShow(MAW_CONSTANT_MOSYNC_SCREEN_HANDLE)
  -- Evaluate the code using a protected call.
  local result, runtimeError = pcall(fun)
  if false == result then
    print("Lua Runtime Error:")
    print(runtimeError)
    mosync.maMessageBox("Lua Error", runtimeError)
  end
end

print("5")
----[[
mosync.EventMonitor:OnKeyDown(function(key)
  if mosync.MAK_BACK == key or mosync.MAK_0 == key then
    mosync.EventMonitor:ExitEventLoop()
  elseif mosync.MAK_1 == key then
    app:OpenUrlTextBox()
  elseif mosync.MAK_2 == key then
    app:LoadAndRun()
  end
end)
print("6")
--]]

--[[
ProgramInfo = {
  ProgramName = "LuaPlayground",
  Version = 1,
  Date = "2011-02-21",
  Author = "Mikael Kindborg",
  Licence = "MIT",
  Comment = "Client that runs MobileLua programs."
}

-- Program: LuaPlayground.lua
-- Author: Mikael Kindborg
-- Description: Lua browser/editor

----------------------------------------------
-- Highjack the keydown function            --
----------------------------------------------

-- The global application state.
GApplicationState = "RunningApplicationCode"

-- Create and call a closure that sets up a custom 
-- keydown functon. We "highjack" the system onKeyDown 
-- function with our own function. This prevents the 
-- programmer from blocking/replacing the exit on back 
-- behaviour.
System.onKeyDown = (function()
  -- "Instance variable" that refers to the user set
  -- keydown function.
  local userKeyDownFun = nil

  -- Set the keydown function that exits on back and
  -- calls the user set keydown function.
  System.onKeyDown(function(keyCode, nativeKeyCode)
    -- Always exit on MAK-BACK so that the user always
    -- can quit the program, even if "evil" code tries
    -- to prevent it.
    if MAK_BACK == keyCode then
      if "RunningUserCode" == GApplicationState then
        maWidgetScreenShow(TabScreen)
        GApplicationState = "RunningApplicationCode"
      else
        maExit(0)
      end
    end

    -- If there is a user set keydown function we call it.
    if nil ~= userKeyDownFun then
      userKeyDownFun(keyCode, nativeKeyCode)
    end
  end)

  -- This is our custom onKeyDown function.
  return function(keyDownFun)
    userKeyDownFun = keyDownFun
  end
end)()

----------------------------------------------
-- Helper functions                         --
----------------------------------------------

-- Helper function for parsing out the Lua code in a text.
-- The code is within "-- MOBILELUA BEGIN --" and 
-- "-- MOBILELUA END --" tags.
function ParseTextWithEmbeddedLuaCode(text)
  local startTag = "-- MOBILELUA BEGIN"
  local stopTag = "-- MOBILELUA END"
  local start = text:find(startTag, 0)
  local stop = text:find(stopTag, start)
  if nil == start or nil == stop then
    return nil
  else
    local code = text:sub(start, stop + stopTag:len())
    return code
  end
end

function EvaluateCode(data)
  print("Evaluate code: "..data)
  -- Parse out the script.
  local code = ParseTextWithEmbeddedLuaCode(data)
  print("EvaluateCode 1")
  if nil == code then
    -- Assume it is a Lua program without tags.
    code = data
  print("EvaluateCode 2")
  end
  -- Parse the code.
  
  print("EvaluateCode 3")
  local fun, parseError = loadstring(code)
  
  print("EvaluateCode 4")
  if nil == fun then
    print("Lua Parse Error "..parseError)
    maMessageBox("Lua Error", parseError)
  else
  
  print("EvaluateCode 5")
    -- Hide the native UI and show the MoSync drawing screen.
    maWidgetScreenShow(MAW_CONSTANT_MOSYNC_SCREEN_HANDLE)
    -- Evaluate the code using a protected call.
    local result, runtimeError = pcall(fun)
	if false == result then
      print("Lua Runtime Error "..runtimeError)
	  maWidgetScreenShow(TabScreen)
	  maMessageBox("Lua Error", runtimeError)
    else
      GApplicationState = "RunningUserCode"
    end
  end
end

function LoadAndRunFromUrl(url)
  -- Function called on download complete.
  local loadAndRunScriptFun = function(data)
    if nil == data then
      maMessageBox("Could not download code", url)
    else
      EvaluateCode(data)
    end
  end
  -- Start the download.
  System.downloadText(url, loadAndRunScriptFun)
end

----------------------------------------------
-- User interface creation                  --
----------------------------------------------

-- Create the screen width url field and list of program urls.
function CreateLoadProgramScreen()
end

--]]

