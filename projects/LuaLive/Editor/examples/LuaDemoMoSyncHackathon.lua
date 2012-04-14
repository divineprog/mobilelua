-- Slides and demo for MoSync Hackathon, April 14, 2012

Slides = {
  "Dynamic Languages On MoSync",
  "Mikael Kindborg<br\>"..
  "mikael.kindborg@mosync.com<br\>"..
  "@divineprog",
  "Fav Langs: Lua, Smalltalk, Lisp, C,"..
  "Python, JavaScript.",
  "Live Coding - Late Binding",
  "MobileLua:<br\>github.com/divineprog/mobilelua"
  }

SlideNo = 0

mosync.EventMonitor:OnKeyDown(function()
  SlideNo = SlideNo + 1
  if SlideNo > # Slides then
    SlideNo = 1
  end
  ShowSlide(Slides[SlideNo])
end)

function ShowSlide(html)
  if nil ~= html then
    LuaLive.WebView:EvalJS(
      "document.body.innerHTML = '<h1>"..html.."</h1>'")
  end
end

mosync.NativeUI:ShowScreen(LuaLive.Screen)

-- Note: This is JavaScript.
document.body.innerHTML = "<h1>Hello World<h1>"
document.body.style.textAlign = "center"

mosync.maExit(0)
