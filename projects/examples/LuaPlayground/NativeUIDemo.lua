-- Demo of NativeUI in Lua.

-- The widget event type is the int at index zero.
function maWidgetEventGetType(event)
  local widgetEvent = maEventGetData(event)
  return maBufferGetInt(widgetEvent, 0)
end

-- The widget handle is the int at index one.
function maWidgetEventGetWidgetHandle(event)
  local widgetEvent = maEventGetData(event)
  return maBufferGetInt(widgetEvent, 1)
end

-- The widget event action is the int at index two.
function maWidgetEventGetAction(event)
  local widgetEvent = maEventGetData(event)
  return maBufferGetInt(widgetEvent, 2)
end

-- The widget event messageId is the int at index two.
function maWidgetEventGetMessageId(event)
  local widgetEvent = maEventGetData(event)
  return maBufferGetInt(widgetEvent, 2)
end

-- The widget event messageSize is the int at index three.
function maWidgetEventGetMessageSize(event)
  local widgetEvent = maEventGetData(event)
  return maBufferGetInt(widgetEvent, 3)
end

-- Widget size constants.
FILL_PARENT = "-1"
WRAP_CONTENT = "-2"

-- Create first screen.

screen1 = maWidgetCreate("Screen")
maWidgetScreenShow(screen1)

mainLayout1 = maWidgetCreate("VerticalLayout")
maWidgetSetProperty(mainLayout1, "width", FILL_PARENT)
maWidgetSetProperty(mainLayout1, "height", FILL_PARENT)
maWidgetAddChild(screen1, mainLayout1)

label = maWidgetCreate("Label")
maWidgetSetProperty(label, "width", FILL_PARENT)
maWidgetSetProperty(label, "height", WRAP_CONTENT)
maWidgetSetProperty(label, "fontSize", "20.0")
maWidgetSetProperty(label, "fontColor", "FFFFFF")
maWidgetSetProperty(label, "text", "Demo of MoSync NativeUI")
maWidgetAddChild(mainLayout1, label)

buttonSayHello = maWidgetCreate("Button")
maWidgetSetProperty(buttonSayHello, "width", FILL_PARENT)
maWidgetSetProperty(buttonSayHello, "height", WRAP_CONTENT)
--maWidgetSetProperty(buttonSayHello, "textVerticalAlignment", "center")
--maWidgetSetProperty(buttonSayHello, "textHorizontalAlignment", "center")
maWidgetSetProperty(buttonSayHello, "text", "Say Hello")
maWidgetAddChild(mainLayout1, buttonSayHello)

buttonOpenWebView = maWidgetCreate("Button")
maWidgetSetProperty(buttonOpenWebView, "width", FILL_PARENT)
maWidgetSetProperty(buttonOpenWebView, "height", WRAP_CONTENT)
maWidgetSetProperty(buttonOpenWebView, "textVerticalAlignment", "center")
maWidgetSetProperty(buttonOpenWebView, "textHorizontalAlignment", "center")
maWidgetSetProperty(buttonOpenWebView, "text", "Open WebView")
maWidgetAddChild(mainLayout1, buttonOpenWebView)

-- Create second screen.

screen2 = maWidgetCreate("Screen")

mainLayout2 = maWidgetCreate("VerticalLayout")
maWidgetSetProperty(mainLayout2, "width", FILL_PARENT)
maWidgetSetProperty(mainLayout2, "height", FILL_PARENT)
maWidgetAddChild(screen2, mainLayout2)

button3 = maWidgetCreate("Button")
maWidgetSetProperty(button3, "width", FILL_PARENT)
maWidgetSetProperty(button3, "height", WRAP_CONTENT)
maWidgetSetProperty(button3, "textVerticalAlignment", "center")
maWidgetSetProperty(button3, "textHorizontalAlignment", "center")
maWidgetSetProperty(button3, "text", "Go Back")
maWidgetAddChild(mainLayout2, button3)

webView = maWidgetCreate("WebView")
maWidgetSetProperty(webView, "width", FILL_PARENT)
maWidgetSetProperty(webView, "height", FILL_PARENT)
maWidgetSetProperty(webView, "url", "http://www.mosync.com")
maWidgetAddChild(mainLayout2, webView)

System.onCustomEvent(function(event)
  if EVENT_TYPE_WIDGET == maEventGetType(event) then
    if WIDGET_EVENT_CLICKED == maWidgetEventGetType(event) then
      if buttonSayHello == maWidgetEventGetWidgetHandle(event) then
         maWidgetSetProperty(label, "text", "Hello World!")
      elseif buttonOpenWebView == maWidgetEventGetWidgetHandle(event) then
	    maWidgetScreenShow(screen2)
      elseif button3 == maWidgetEventGetWidgetHandle(event) then
	    maWidgetScreenShow(screen1)
	  end
    end
  end
end)

-- maWidgetRemoveChild(mainLayout, mSubmitButton);
-- maExit(0)
