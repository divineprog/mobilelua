--[[

This file contains just crap.

Julpyssel
Christmas Fun

--]]


Card {
  name = "Card1",
  width = 1000,
  color = 0x990000,
}

Sprite {
  -- card = "Card1",
  image = "Sprite1.png",
  x = Center,
  y = Center,
  width = 200,
  touchUp = function(Me) OpenCard("Card2") end,
}

Card {
  name = "Card2",
  width = 1000,
  color = 0x000099,
}

Sprite {
  -- Card = "Card1",
  Image = "Sprite2.png",
  X = Left,
  Y = Center,
  Width = 200,
  TouchUp = function(Me)
    Me:GoToCard("Card2")
  end,
}

Sprite
  :Image("Sprite2.png")
  :X(Left)
  :Y(Center)
  :Width(200)
  :TouchUp(function(Me)
    Me:GoToCard("Card2")
  end,
