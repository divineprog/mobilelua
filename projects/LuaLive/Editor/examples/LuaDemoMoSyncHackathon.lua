

Slides = {
  "Dynamic Languages On MoSync",
  "Mikael Kindborg<br\>"..
  "mikael.kindborg@mosync.com<br\>"..
  "@divineprog",
  "Fav Langs: Lua, Smalltalk, Lisp, C,"..
  "Python, JavaScript.",
  "Live Coding",
  "MobileLua:<br\>github.com/divineprog/mobilelua"
  }

SlideNo = 0

function ShowSlide(html)
  if nil ~= html then
    LuaLive.WebView:EvalJS(
      "document.body.innerHTML = '"..html.."'")
  end
end

mosync.EventMonitor:OnKeyDown(function()
  SlideNo = SlideNo + 1
  ShowSlide(Slides[SlideNo])
end)

mosync.NativeUI:ShowScreen(LuaLive.Screen)
