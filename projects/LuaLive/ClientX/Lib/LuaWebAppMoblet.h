/*
Copyright (C) 2011 MoSync AB

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
 * @file LuaWebAppMoblet.h
 * @author Mikael Kindborg
 *
 * @brief Lua-enabled moblet that has a WebView and supports
 * communication between a JavaScript and C++.
 */

#ifndef LUA_WEB_APP_MOBLET_H_
#define LUA_WEB_APP_MOBLET_H_

#include <ma.h>
#include <mastdlib.h>
#include <mavsprintf.h>

#include <MAUtil/String.h>

#include <NativeUI/Screen.h>
#include <NativeUI/WebView.h>
#include <NativeUI/WebViewListener.h>

#include <Wormhole/WebViewMessage.h>
#include <Wormhole/FileUtil.h>
#include <Wormhole/MessageProtocol.h>
#include <Wormhole/MessageStream.h>
#include <Wormhole/Libs/JSONMessage.h>
#include <Wormhole/Libs/PhoneGap/PhoneGapMessageHandler.h>
#include <Wormhole/Libs/JSNativeUI/NativeUIMessageHandler.h>
#include <Wormhole/Libs/JSNativeUI/ResourceMessageHandler.h>

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "Moblet.h"
#include "LuaEngine.h"

/**
 * @brief Classes for communication with JavaScript code
 */
namespace MobileLua
{
	// Forward declaration.
	class LuaWebAppMoblet_WebViewListener;

	/**
	 * \brief A web view is a widget used to render web pages.
	 */
	class LuaWebAppMoblet : public MobileLua::Moblet
	{
	public:
		/**
		 * Constructor.
		 */
		LuaWebAppMoblet();

		/**
		 * Destructor.
		 */
		virtual ~LuaWebAppMoblet();

		void initializeWormhole();

		void callLuaEventFun(lua_State *L, void* event);

		/**
		 * Pass event to Lua.
		 * Overridden method.
		 */
		virtual bool handleEvent(const MAEvent& event);

		MAWidgetHandle getScreenWidgetHandle();

		MAWidgetHandle getWebViewWidgetHandle();

		MobileLua::LuaEngine* getLuaEngine();

		/**
		 * Get the WebView widget displayed by this moblet.
		 * @return Pointer to the WebView instance.
		 */
		virtual NativeUI::WebView* getWebView();

		/**
		 * Get a file utility object used for accessing the
		 * device's local file system.
		 * @return Pointer to a FileUtil instance.
		 */
		virtual Wormhole::FileUtil* getFileUtil();

		/**
		 * Enable JavaScript to C++ communication.
		 */
		virtual void enableWebViewMessages();

		/**
		 * Disable JavaScript to C++ communication.
		 */
		virtual void disableWebViewMessages();

		/**
		 * Display a page in the WebView of this moblet.
		 * @param url Url of page to open.
		 */
		virtual void showPage(const MAUtil::String& url);

		/**
		 * Display the WebView.
		 */
		virtual void showWebView();

		/**
		 * Run JavaScript code in the WebView.
		 */
		virtual void callJS(const MAUtil::String& script);

		/**
		 * This method is called when a key is pressed.
		 * Forwards the event to PhoneGapMessageHandler.
		 */
		virtual void keyPressEvent(int keyCode, int nativeCode);

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
		virtual void handleWebViewMessage(
			NativeUI::WebView* webView,
			MAHandle urlData);

		/**
		 * Handles JSON messages. This is used by PhoneGap.
		 *
		 * You can send your own messages from JavaScript and handle them here.
		 *
		 * @param webView A pointer to the web view posting this message.
		 * @param data The raw encoded JSON message array.
		 */
		void handleMessageStreamJSON(NativeUI::WebView* webView, MAHandle data);

		/**
		 * Handles string stream messages (generally faster than JSON messages).
		 * This is used by the JavaScript NativeUI system.
		 *
		 * You can send your own messages from JavaScript and handle them here.
		 *
		 * @param webView A pointer to the web view posting this message.
		 * @param data The raw encoded stream of string messages.
		 */
		void handleMessageStream(NativeUI::WebView* webView, MAHandle data);

		/**
		 * For debugging.
		 */
		void printMessage(MAHandle dataHandle);

		/**
		 * Extract HTML/CSS/JS/Media files to the local file system.
		 */
		virtual void extractFileSystem();

		/**
		 * @return true if the checksum has changed (or if the old
		 * value did not exist, such as on first time load).
		 */
		virtual bool checksumHasChanged();

	protected:
		MobileLua::LuaEngine mLuaEngine;

		/**
		 * The screen widget that is the root of the UI.
		 */
		NativeUI::Screen* mScreen;

		/**
		 * The WebView widget that displays the application UI.
		 */
		NativeUI::WebView* mWebView;

		/**
		 * JavsScript message listener.
		 */
		LuaWebAppMoblet_WebViewListener* mWebViewListener;

		/**
		 * File utility object.
		 */
		Wormhole::FileUtil* mFileUtil;

		/**
		 * Has extractFileSystem() been called?
		 */
		bool mFileSystemIsExtracted;

		/**
		 * Handler for PhoneGap messages.
		 */
		Wormhole::PhoneGapMessageHandler mPhoneGapMessageHandler;

		/**
		 * Handler for NativeUI messages
		 */
		Wormhole::NativeUIMessageHandler mNativeUIMessageHandler;

		/**
		 * Handler for resource messages used for NativeUI
		 */
		Wormhole::ResourceMessageHandler mResourceMessageHandler;
	};
} // namespace

#endif

