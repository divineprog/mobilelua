/*
Copyright (C) 2012 MoSync AB

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License,
version 2, as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.
*/

/**
 * @file LuaWormholeMoblet.cpp
 * @author Mikael Kindborg
 *
 * @brief Lua-enabled moblet that has a WebView and supports
 * communication between a JavaScript and C++.
 */

#include "LuaWormholeMoblet.h"

namespace MobileLua
{
	// Functions called from Lua.

	static LuaWormholeMoblet* TheWormhole;

	static int WormholeShowWebView(lua_State *L)
	{
		TheWormhole->getWebView()->setVisible(true);
		return 0; // Number of results
	}

	static int WormholeHideWebView(lua_State *L)
	{
		TheWormhole->getWebView()->setVisible(false);
		return 0; // Number of results
	}

	static int WormholeGetScreenWidgetHandle(lua_State *L)
	{
		MAWidgetHandle widget = TheWormhole->getScreenWidgetHandle();
		lua_pushnumber(L, widget);  // push result
		return 1; // Number of results
	}

	static int WormholeGetWebViewWidgetHandle(lua_State *L)
	{
		MAWidgetHandle widget = TheWormhole->getWebViewWidgetHandle();
		lua_pushnumber(L, widget);  // push result
		return 1; // Number of results
	}

	static int WormholeInitialize(lua_State *L)
	{
		TheWormhole->initializeWormhole();
		return 0; // Number of results
	}

	/**
	 * Class that listens for WebView events.
	 * Here we receive messages from JavaScript.
	 */
	class LuaWormholeMoblet_WebViewListener : public NativeUI::WebViewListener
	{
	public:
		/**
		 * Constructor that saves the pointer to the moblet.
		 */
		LuaWormholeMoblet_WebViewListener(LuaWormholeMoblet* moblet)
		{
			mMoblet = moblet;
		}

		/**
		 * This method is called when a "mosync://" url is
		 * invoked in the WebView.
		 *
		 * Note: The urlData is deallocated automatically
		 * by the WebView after this call finishes.
		 */
		virtual void webViewHookInvoked(
			NativeUI::WebView* webView,
			int hookType,
			MAHandle urlData)
		{
			// Note: urlData is deallocated automatically by
			// the framework, we should not deallocate it here.
			mMoblet->handleWebViewMessage(webView, urlData);
		}

	private:
		/**
		 * Pointer to the moblet.
		 */
		LuaWormholeMoblet* mMoblet;
	};
	// End of class LuaWormholeMoblet_WebViewListener

	/**
	 * Constructor.
	 */
	LuaWormholeMoblet::LuaWormholeMoblet() :
		mScreen(NULL),
		mWebView(NULL),
		mWebViewListener(NULL),
		mFileUtil(NULL),
		mFileSystemIsExtracted(false),
		mLastEvent(NULL),
		mPhoneGapMessageHandler(getWebView()),
		mNativeUIMessageHandler(getWebView()),
		mResourceMessageHandler(getWebView())
	{
		TheWormhole = this;

		// Create file utility object.
		mFileUtil = new Wormhole::FileUtil();

		// Initialize the Lua engine.
		if (!mLuaEngine.initialize())
		{
			maPanic(0, "Could not initialize Lua");
		}

		// Register helper functions for the Wormhole interface.
		mLuaEngine.registerGlobalTableFunction("mosync",
			"WormholeShowWebView", (LUA_FUNCTION) WormholeShowWebView);
		mLuaEngine.registerGlobalTableFunction("mosync",
			"WormholeHideWebView", (LUA_FUNCTION) WormholeHideWebView);
		mLuaEngine.registerGlobalTableFunction("mosync",
			"WormholeGetScreenWidgetHandle", (LUA_FUNCTION) WormholeGetScreenWidgetHandle);
		mLuaEngine.registerGlobalTableFunction("mosync",
			"WormholeGetWebViewWidgetHandle", (LUA_FUNCTION) WormholeGetWebViewWidgetHandle);
		mLuaEngine.registerGlobalTableFunction("mosync",
			"WormholeInitialize", (LUA_FUNCTION) WormholeInitialize);

		// Extract files in LocalFiles folder to the device.
		extractFileSystem();

		// Enable message sending from JavaScript to C++.
		enableWebViewMessages();

		// Show the WebView that contains the HTML/CSS UI
		// and the JavaScript code.
		getWebView()->setVisible(true);

		// The page in the "LocalFiles" folder to
		// show when the application starts.
		//showPage("index.html");

		mScreen->show();
	}

	/**
	 * Destructor.
	 */
	LuaWormholeMoblet::~LuaWormholeMoblet()
	{
		// Deleting the root widget will also delete child widgets.
		delete mScreen;

		// Delete the WebView listener.
		if (NULL != mWebViewListener)
		{
			delete mWebViewListener;
			mWebViewListener = NULL;
		}

		// Delete the file utility object.
		delete mFileUtil;
	}

  /**
   * This should be called from Lua after having loaded a 
   * new web page, to enable Workmhole/PhoneGap.
   */
	void LuaWormholeMoblet::initializeWormhole()
	{
		// Send the Device Screen size to JavaScript.
		MAExtent scrSize = maGetScrSize();
		int width = EXTENT_X(scrSize);
		int height = EXTENT_Y(scrSize);
		char buf[512];
		sprintf(
			buf,
			"{mosyncScreenWidth=%d; mosyncScreenHeight = %d;}",
			width,
			height);
		callJS(buf);

		// Set the beep sound. This is defined in the
		// Resources/Resources.lst file. You can change
		// this by changing the sound file in that folder.
		mPhoneGapMessageHandler.setBeepSound(2);

		// Initialize PhoneGap.
		mPhoneGapMessageHandler.initializePhoneGap();
	}

	void LuaWormholeMoblet::callLuaEventFun(lua_State* L, void* event)
	{
		// Used for consistency check.
		int stackSize = lua_gettop(L);

		// Push table "mosync" onto stack.
		lua_getfield(L, LUA_GLOBALSINDEX, "mosync");

		// Push field "EventMonitor".
		lua_getfield(L, -1, "EventMonitor");

		// Push field "HandleEvent" (function).
		lua_getfield(L, -1, "HandleEvent");

		// Push copy of "self" ("EventMontor").
		lua_pushvalue(L, -2);

		// Push event pointer.
		lua_pushlightuserdata(L, event);

		// Call.
		int result = lua_pcall(
			L,
			2,  // nargs
			0,  // nresults
			0); // no errfunc

		// Remove remaining stack elements.
		lua_remove(L, -1); // "EventMonitor"
		lua_remove(L, -1); // "mosync"

		if (stackSize != lua_gettop(L))
		{
			maPanic(0, "Stack is inconsistent in CallLuaEventFun");
		}
	}

	/**
	 * Pass event to Lua.
	 * Overridden method.
	 */
	bool LuaWormholeMoblet::handleEvent(const MAEvent& event)
	{
		// Save pointer to event.
		mLastEvent = (void*) &event;
	  
		// Call Lua event handler, unless this is a HOOK_INVOKED event.
		// HOOK_INVOKED are dispatched to Lua in handleWebViewMessage().
		if (EVENT_TYPE_WIDGET == event.type)
		{
			MAWidgetEventData* widgetEvent = (MAWidgetEventData*) event.data;
			if (MAW_EVENT_WEB_VIEW_HOOK_INVOKED == widgetEvent->eventType)
			{
				return false;
			}
		}

		callLuaEventFun((lua_State*) mLuaEngine.mLuaState, (void*) &event);

		// Always let the moblet process the event.
		return false;
	}

	MAWidgetHandle LuaWormholeMoblet::getScreenWidgetHandle()
	{
		return mScreen->getWidgetHandle();
	}

	MAWidgetHandle LuaWormholeMoblet::getWebViewWidgetHandle()
	{
		return mWebView->getWidgetHandle();
	}

	MobileLua::LuaEngine* LuaWormholeMoblet::getLuaEngine()
	{
		return &mLuaEngine;
	}

	/**
	 * Get the WebView widget displayed by this moblet.
	 * Creates the WebView if it does not exist.
	 * @return Pointer to a WebView instance.
	 */
	NativeUI::WebView* LuaWormholeMoblet::getWebView()
	{
		// Create the WebView if it does not exist.
		if (NULL == mWebView)
		{
			// Create and configure the WebView.
			mWebView = new NativeUI::WebView();
			mWebView->fillSpaceHorizontally();
			mWebView->fillSpaceVertically();

			// Create and show the screen that holds the WebView.
			mScreen = new NativeUI::Screen();
			mScreen->setMainWidget(mWebView);
		}

		return mWebView;
	}

	/**
	 * Get a file utility object used for accessing the
	 * device's local file system.
	 * @return Pointer to a FileUtil instance.
	 */
	Wormhole::FileUtil* LuaWormholeMoblet::getFileUtil()
	{
		return mFileUtil;
	}

	/**
	 * Enable JavaScript to C++ communication.
	 */
	void LuaWormholeMoblet::enableWebViewMessages()
	{
		if (NULL == mWebViewListener)
		{
			mWebViewListener = new LuaWormholeMoblet_WebViewListener(this);
			getWebView()->addWebViewListener(mWebViewListener);
			getWebView()->enableWebViewMessages();
		}
	}

	/**
	 * Disable JavaScript to C++ communication.
	 */
	void LuaWormholeMoblet::disableWebViewMessages()
	{
		if (NULL != mWebViewListener)
		{
			getWebView()->removeWebViewListener(mWebViewListener);
			getWebView()->disableWebViewMessages();
			delete mWebViewListener;
			mWebViewListener = NULL;
		}
	}

	/**
	 * Display a page in the WebView of this moblet.
	 * @param url Url of page to open.
	 */
	void LuaWormholeMoblet::showPage(const MAUtil::String& url)
	{
		// Since extractFileSystem() is moved out of the constructor
		// into application code, make sure it has been called before
		// displaying the page. This makes the code updates backwards
		// compatible with old application code.
		if (!mFileSystemIsExtracted)
		{
			extractFileSystem();
		}

		// Make sure the WebView is displayed.
		// It should do no harm to call this method multiple times.
		showWebView();

		// Open the page.
		getWebView()->openURL(url);
	}

	/**
	 * Display the WebView.
	 */
	void LuaWormholeMoblet::showWebView()
	{
		// Make sure the WebView is created.
		getWebView();

		// Show the screen that contains the WebView.
		mScreen->show();
	}

	/**
	 * Run JavaScript code in the WebView.
	 */
	void LuaWormholeMoblet::callJS(const MAUtil::String& script)
	{
		getWebView()->callJS(script);
	}

	// /**
	 // * This method is called to show a screen while unpacking the
	 // * file bundle. You can override this method to customize
	 // * the screen displayed. You can display anything you wish
	 // * in the WebView widget. The default implementation just
	 // * displays a plain message.
	 // */
	// void LuaWormholeMoblet::displayUnpackScreen()
	// {
		// getWebView()->setHtml(
			// "<!DOCTYPE html>"
			// "<html><head>"
			// "<style type=\"text/css\">"
			// "#Message {"
				// "margin: 0.3em 0.3em;"
				// "font-size: 3.0em;"
				// "font-weight: bold;"
				// "color: white;"
				// "text-align: center;"
				// "background-color: black;"
				// "font-family: sans-serif;"
			// "}"
			// "</head><body>"
			// "<div id=\"Message\">Installing application files...</div>"
			// "</body></html>"
			// );
	// }

	/**
	 * This method is called when a key is pressed.
	 * Forwards the event to PhoneGapMessageHandler.
	 */
	void LuaWormholeMoblet::keyPressEvent(int keyCode, int nativeCode)
	{
		// Forward to PhoneGap MessageHandler.
		mPhoneGapMessageHandler.processKeyEvent(keyCode, nativeCode);
	}

	/**
	 * This method handles messages sent from the WebView.
	 *
	 * Note that the data object will be valid only during
	 * the life-time of the call of this method, then it
	 * will be deallocated.
	 *
	 * @param webView The WebView that sent the message.
	 * @param urlData Data object that holds message content.
	 */
	void LuaWormholeMoblet::handleWebViewMessage(
		NativeUI::WebView* webView,
		MAHandle data)
	{
		// Uncomment to print message data for debugging.
		// You need to build the project in debug mode for
		// the log output to be displayed.
		//printMessage(data);

		// Check the message protocol.
		Wormhole::MessageProtocol protocol(data);
		if (protocol.isMessageStreamJSON())
		{
			handleMessageStreamJSON(webView, data);
		}
		else if (protocol.isMessageStream())
		{
			handleMessageStream(webView, data);
		}
		else
		{
		  // The event was not any of the predefined protocols
		  // used by Wormhole, pass it on to Lua.
		  callLuaEventFun((lua_State*) mLuaEngine.mLuaState, mLastEvent);
		}
	}

	/**
	 * Handles JSON messages. This is used by PhoneGap.
	 *
	 * You can send your own messages from JavaScript and handle them here.
	 *
	 * @param webView A pointer to the web view posting this message.
	 * @param data The raw encoded JSON message array.
	 */
	void LuaWormholeMoblet::handleMessageStreamJSON(
		NativeUI::WebView* webView,
		MAHandle data)
	{
		// Create the message object. This parses the message data.
		// The message object contains one or more messages.
		Wormhole::JSONMessage message(webView, data);

		// Loop through messages.
		while (message.next())
		{
			// This detects the PhoneGap protocol.
			if (message.is("PhoneGap"))
			{
				mPhoneGapMessageHandler.handlePhoneGapMessage(message);
			}

			// Here you can add your own message handing as needed.
		}
	}

	/**
	 * Handles string stream messages (generally faster than JSON messages).
	 * This is used by the JavaScript NativeUI system.
	 *
	 * You can send your own messages from JavaScript and handle them here.
	 *
	 * @param webView A pointer to the web view posting this message.
	 * @param data The raw encoded stream of string messages.
	 */
	void LuaWormholeMoblet::handleMessageStream(
		NativeUI::WebView* webView,
		MAHandle data)
	{
		// Create a message stream object. This parses the message data.
		// The message object contains one or more strings.
		Wormhole::MessageStream stream(webView, data);

		// Pointer to a string in the message stream.
		const char* p;

		// Process messages while there are strings left in the stream.
		while (p = stream.getNext())
		{
			if (0 == strcmp(p, "NativeUI"))
			{
				//Forward NativeUI messages to the respective message handler
				mNativeUIMessageHandler.handleMessage(stream);
			}
			else if (0 == strcmp(p, "Resource"))
			{
				//Forward Resource messages to the respective message handler
				mResourceMessageHandler.handleMessage(stream);
			}
			else if (0 == strcmp(p, "close"))
			{
				// Close the application (calls method in class Moblet).
				exitEventLoop();
			}

			// Here you can add your own message handing as needed.
		}
	}

	/**
	 * For debugging.
	 */
	void LuaWormholeMoblet::printMessage(MAHandle dataHandle)
	{
		// Get length of the data, it is not zero terminated.
		int dataSize = maGetDataSize(dataHandle);

		// Allocate buffer for string data.
		char* stringData = (char*) malloc(dataSize + 1);

		// Get the data.
		maReadData(dataHandle, stringData, 0, dataSize);

		// Zero terminate.
		stringData[dataSize] = 0;

		// Print unparsed message data.
		maWriteLog("@@@ MOSYNC Message:", 19);
		maWriteLog(stringData, dataSize);

		free(stringData);
	}

	/**
	 * Extract HTML/CSS/JS/Media files to the local file system.
	 */
	void LuaWormholeMoblet::extractFileSystem()
	{
		// This function has been called.
		mFileSystemIsExtracted = true;

		// Display splash screen if this is the first time launch
		// or if the checksum has changed.
		if (checksumHasChanged())
		{
			// Extract bundled files to the local file system.
			mFileUtil->extractLocalFiles();
		}
	}

	/**
	 * @return true if the checksum has changed (or if the old
	 * value did not exist, such as on first time load).
	 */
	bool LuaWormholeMoblet::checksumHasChanged()
	{
		// Assume checksum has changed (or does not exist).
		bool hasChanged = true;

		// Read existing checksum value and check it.
		MAUtil::String filePath = getFileUtil()->getLocalPath();
		filePath += "MoSyncFileBundleChecksum";
		int checksum = getFileUtil()->getFileSystemChecksum(1);

		MAUtil::String data;
		if (getFileUtil()->readTextFromFile(filePath, data))
		{
			int existingChecksum = (int)strtol(data.c_str(), NULL, 10);
			hasChanged = checksum != existingChecksum;
		}

		// Save checksum value if it has changed.
		if (hasChanged && checksum != 0)
		{
			char checksumBuf[16];
			sprintf(checksumBuf, "%d", checksum);
			getFileUtil()->writeTextToFile(filePath, checksumBuf);
		}

		return hasChanged;
	}

} // namespace
