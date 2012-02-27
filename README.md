MobileLua
=========

MobileLua is a port of Lua to [MoSync](http://mosync.com/), a C/C++ 
cross-platform development system for mobile devices. This enables Lua 
to be used on a wide range of mobile devices.

News
----

MobileLua now wraps all functions and constants in the "mosync" namespace.

For example, when you previously wrote:

    Screen:SetColor(255, 255, 255)
    
You now write:
    
    mosync.Screen:SetColor(255, 255, 255)

Example programs are being updated to use this

Error handling
--------------

MoSync does not yet support exceptions or setjmp/longjmp, so Lua error handling 
is replaced with return in case of errors and check for error status. 
This is not implemented for all error conditions, so for some errors you can 
get incomplete error information, or in the worst case the program may hang or crash.

Example code
------------

The following is a very simple paint application. Supports multi-touch.
    
    -- Fill screen with background color.
    mosync.Screen:SetColor(255, 255, 255)
    mosync.Screen:Fill()
    mosync.Screen:Update()
    
    -- Function that paints a "brush stamp" on the screen.
    function Paint(x, y, touchId)
      if touchId == 0 then 
        mosync.Screen:SetColor(0, 0, 0) 
      else
        mosync.Screen:SetColor(0, 200, 0) 
      end    
      mosync.Screen:FillRect(x - 20, y - 20, 40, 40)
      mosync.Screen:Update()
    end    
    
    -- Bind the Paint function to touch events.
    mosync.EventMonitor:OnTouchDown(Paint)
    mosync.EventMonitor:OnTouchDrag(Paint)

Contact
-------

mikael.kindborg@mosync.com  
mikael.kindborg@gmail.com

License
-------

Unless stated otherwise, the MIT license is used for the source code.

Each source file should contain a license header.
