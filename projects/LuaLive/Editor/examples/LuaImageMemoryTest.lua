for j = 0, 10, 1 do
log("j: " .. j)
image = mosync.maCreatePlaceholder()
mosync.maCreateDrawableImage(image, 600 ,600)
oldDrawTarget = mosync.maSetDrawTarget(image) 
for i = 0, 200, 1 do
  mosync.Screen:SetColor(255, 255, 255)
  mosync.Screen:Fill()
  mosync.Screen:SetColor(20 + j, 20 + i, 200)
  mosync.Screen:FillRect(0, 0, 300, 300)
  mosync.maDrawImage(image, 10, 10)
  mosync.maUpdateScreen()
end
log("maDestroyPlaceholder")
mosync.maDestroyPlaceholder(image)
log("maSetDrawTarget")
--mosync.maSetDrawTarget(oldDrawTarget)
log("end")
end
