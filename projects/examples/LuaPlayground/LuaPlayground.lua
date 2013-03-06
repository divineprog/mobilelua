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
-- Support for simple widget event handling --
----------------------------------------------

function WidgetEventGetType(widgetEvent)
  return SysBufferGetInt(widgetEvent, 0)
end

function WidgetEventGetHandle(widgetEvent)
  return SysBufferGetInt(widgetEvent, 1)
end
  
function WidgetEventGetIntParam(widgetEvent)
  return SysBufferGetInt(widgetEvent, 2)
end

-- Create event handler object.
EventHandler = (function()
  -- The event handler object.
  self = {}
  
  -- Table that contains widget -> function pairs.
  local widgetEventTable = {}

  -- Add an event function to a widget.
  self.addWidgetEvent = function(widget, eventFunction)
    widgetEventTable[widget] = eventFunction
  end

  -- Set event function.
  System.onCustomEvent(function(event)
    -- Is this a widget event?
    if EVENT_TYPE_WIDGET == SysEventGetType(event) then
      -- Get the widget event.
      local widgetEvent = SysEventGetData(event)
      -- Get the widget handle of the event.
      local widget = WidgetEventGetHandle(widgetEvent)
      -- Is there a function registered for this widget?
      if nil ~= widgetEventTable[widget] then 
        -- Yes there is, call the function.
        widgetEventTable[widget](widgetEvent)
      end
    end
  end)

  return self

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
  -- Create screen and widgets.
  local screen = maWidgetCreate("Screen")
  maWidgetSetProperty(screen, "title", "Programs")

  local layout = maWidgetCreate("VerticalLayout")
  maWidgetSetProperty(layout, "width", "-1")
  maWidgetSetProperty(layout, "height", "-1")

  local urlEditBox = maWidgetCreate("EditBox")
  maWidgetSetProperty(urlEditBox, "width", "-1")
  maWidgetSetProperty(urlEditBox, "height", "-2")
  maWidgetSetProperty(urlEditBox, "text", "http://code.google.com/p/mobilelua/")

  local loadButton = maWidgetCreate("Button")
  maWidgetSetProperty(loadButton, "width", "-1")
  maWidgetSetProperty(loadButton, "height", "-2")
  maWidgetSetProperty(loadButton, "text", "Run program")
  
  local listView = maWidgetCreate("ListView")
  maWidgetSetProperty(listView, "width", "-1")
  maWidgetSetProperty(listView, "height", "-1")
  
  -- Create list view items.
  
  -- TODO: Read saved links from store.
  -- For now, add a couple of hardcoded urls.
  -- maWidgetSet/GetUserData would be nice to have...
  -- Would also enable event callbacks in C.
  
  -- Create list of urls.
  local urlList = {}
  
  urlList[1] =  "http://code.google.com/p/mobilelua/"
  urlList[2] =  "http://code.google.com/p/mobilelua/"
  urlList[3] =  "http://code.google.com/p/mobilelua/"
  urlList[4] =  "http://code.google.com/p/mobilelua/"
  
  for index, value in ipairs(urlList) do
    local listItem = maWidgetCreate("ListViewItem")
    maWidgetSetProperty(listItem, "text", value)
    maWidgetAddChild(listView, listItem)
  end
  
  -- Event handler for the run/load button.
  EventHandler.addWidgetEvent(loadButton, function(widgetEvent)
    -- Hide keyboard.
    maWidgetSetProperty(urlEditBox, "showKeyboard", "false")
    -- Get the url string.
    local urlBuffer = SysBufferCreate(256)
    maWidgetGetProperty(urlEditBox, "text", urlBuffer, 256)
    local url = SysBufferToString(urlBuffer)
    SysBufferDelete(urlBuffer)
    -- Load and run code.
    LoadAndRunFromUrl(url)
  end)
  
  -- Event handler for the list view.
  EventHandler.addWidgetEvent(listView, function(widgetEvent)
    -- Get the selected index.
    local index = WidgetEventGetIntParam(widgetEvent)
    local url = urlList[index + 1]
    -- Load and run code.
    LoadAndRunFromUrl(url)
  end)
  
  maWidgetAddChild(layout, urlEditBox)
  maWidgetAddChild(layout, loadButton)
  maWidgetAddChild(layout, listView)
  maWidgetAddChild(screen, layout)

  return screen
end

function CreateEditScreen()
  local screen = maWidgetCreate("Screen")
  maWidgetSetProperty(screen, "title", "Code")

  local layout = maWidgetCreate("VerticalLayout")
  maWidgetSetProperty(layout, "width", "-1")
  maWidgetSetProperty(layout, "height", "-1")

  local runButton = maWidgetCreate("Button")
  maWidgetSetProperty(runButton, "width", "-1")
  maWidgetSetProperty(runButton, "height", "-2")
  maWidgetSetProperty(runButton, "text", "Run program")

  local codeEditBox = maWidgetCreate("EditBox")
  maWidgetSetProperty(codeEditBox, "width", "-1")
  maWidgetSetProperty(codeEditBox, "height", "-1")
  maWidgetSetProperty(codeEditBox, "multiline", "true")
  -- Set initial example program.
  maWidgetSetProperty(codeEditBox, "text",
    '-- Fill the screen with a color.\n'..
    'Screen.setColor(255, 255, 0)\n'..
    'Screen.fillRect(0, 0, 2000, 2000)\n'..
    'Screen.update()')
	
  EventHandler.addWidgetEvent(runButton, function(widgetEvent)
    -- Hide keyboard.
    maWidgetSetProperty(codeEditBox, "showKeyboard", "false")
    -- Get the code string.
	-- TODO: Handle the hardcoded buffer size! Ask for the size then
	-- allocate more if needed. Also add error checking (out of memory).
    local codeBuffer = SysBufferCreate(16 * 1024)
    maWidgetGetProperty(codeEditBox, "text", codeBuffer, 16 * 1024)
    local code = SysBufferToString(codeBuffer)
    SysBufferDelete(codeBuffer)
	-- Run the code.
    EvaluateCode(code)
  end)

  maWidgetAddChild(layout, runButton)
  maWidgetAddChild(layout, codeEditBox)
  maWidgetAddChild(screen, layout)
  
  return screen
end

function CreateHelpScreen()
  local screen = maWidgetCreate("Screen")
  maWidgetSetProperty(screen, "title", "Help" )
  --maWidgetSetPropertyInt(screen, "icon", R_TV)

  local webView = maWidgetCreate("WebView")
  maWidgetSetProperty(webView, "width", "-1")
  maWidgetSetProperty(webView, "height", "-1")

  maWidgetSetProperty(webView, "url", "http://code.google.com/p/mobilelua/")
  maWidgetAddChild(screen, webView)

  return screen
end

-- Create screens.
TabScreen = maWidgetCreate("TabScreen")
LoadProgramScreen = CreateLoadProgramScreen()
maWidgetAddChild(TabScreen, LoadProgramScreen)
EditScreen = CreateEditScreen()
maWidgetAddChild(TabScreen, EditScreen)
HelpScreen = CreateHelpScreen()
maWidgetAddChild(TabScreen, HelpScreen)

-- Open main screen.
maWidgetScreenShow(TabScreen)

