# Getting started with MobileLua
MobileLua is a port of Lua to MoSync, a cross-platform mobile development platform.
This document helps you to get started with authoring MobileLua apps.

First it should be said that there are two ways to author MobleLua apps:

* The basic way is using the MoSync IDE, and this is the way you need to use when developing a stand-alone app that can be deployed to the app stores.
* The alternative way is to use LuaLive, an editor and client app that supports live editing and interactive development of Lua apps. This is a great way to experiment and learn Lua. It is also a very productive way of developing MobileLua apps as it dramatically cuts down the edit/build/deploy cycle.

Below, the basic way that uses the MoSync IDE is described. Using LuaLive will be explained in a forthcoming document.

## Set up the MoSync IDE with MobileLua
**Download MoSync.**
Go to the [MoSync website](http://mosync.com) and download and install MoSync. The IDE is Eclipse-based and works out of the box on Windows and iOS, but requires undocumented hand-tweaking to work on Linux.

**Download MobileLua.**
Get the source code for MoubleLua from [GitHub](https://github.com/divineprog/mobilelua).

**Start the MoSync IDE.**
Launch the MoSync Eclipse IDE. You will be asked to register. It is great if you wish to do so, then you will also be able to post to the MoSync forum (there is a section dedicated to Lua!). If you wish not to register, you can just close the registration screen or press the "MoSync" tab in Eclipse to go to  the coding screen.

**Import the MobileLua projects.**
Choose "File/Import/Existing MoSync project into workspace". Then do "Select root directory/Browse" and select the projects folder in MobileLua. That will import all Lua projects into the Eclipse workspace.

## Run example programs
**LuaLib.** The Lua interpreter is in the project called LuaLib. That is a library used by all MobileLua programs, and it must be built for the examples to work. The example projects are set up to build LuaLib automatically, but in case something goes wrong, try to rebuild LuaLib, then rebuild your project. You rebuild a project by selecting it in the Project Explorer, right click, and pick "Rebuild Project".

**Run LuaPaint in MoRE.** A good project to start with is LuaPaint. Select the project and click the green arrow-shaped "Run" icon in the Eclipse toolbar. This will automatically build the project. Select to run in MoRE, the MoSync Emulator. The program should launch immediately, and you should see the emulator with a white screen. Try painting on the screen with the mouse.

**Explore the source code.** In the LuaPaint projectm you will see three files:

* main.cpp - This is a C++ program that initialises the Lua interpreter and launches the LuaPaint.
* LuaPaint.lua - This is the Lua application code. The MoSync IDE currently does not support syntax highlighting for Lua, so you can edit Lua files with another editor, if you prefer.
* resource.lst - This is a resource description file. The Lua code is bundled as a resource in the application, which is extracted when the application launches.

**Naming.** A few notes about naming:

* main.cpp can be named anything .cpp as long as it has the MAMain function. 
* Lua files can be named anything and places in any folder, as long as the paths and file names in the resource file match.
* The resource file can be named anything .lst

**Build and deploy to a device.** Select the project you wish to run, for example LuaPaint (you need a device with a touch screen), then select the target device in the menu on the left. Lua works on all platforms supported by MoSync, but some libraries, such as NativeUI, are only available on Android and iOS (and soon Windows Phone). The section [How to build and run your app on Android or iPhone/iPad](http://www.mosync.com/documentation/manualpages/how-create-html5-project-mosync#How_to_build_and_run_your_app_on_Android_or_iPhoneiPad) in the MoSync HTML5 documentation provides an overview of the process of building and deploying a MoSync application. 

Once you have an example up and running, you can start coding your own app.

## Create your own project

The easiest way to create your own project is to pick an existing project and copy it. 

**Copy.** Select and right-click the project you wish to copy, and select "Copy".

**Paste.** Right-click on the background of the Project Explorer and select "Paste". You will be presented with a dialog where you name the new project and select where it will be located in the file system.

**Make sure LuaLib.lua is in place.** LuaLib.lua contains the source code for the objects in the MobileLua library. It is located in: projects/common/LuaLib.lua. When you copy a project, you must make sure that your project can find this file. It is referenced from resource.lst. Remember to update the path to the file in the resource file of the new project.

**Test it.** Rebuild and test your new project to make sure it works. Now you are ready to write code.

## Join the community

Join the MoSync forum and [start talking about MobileLua](http://www.mosync.com/forum/591). Ask questions, share your experiences, and help other developers!