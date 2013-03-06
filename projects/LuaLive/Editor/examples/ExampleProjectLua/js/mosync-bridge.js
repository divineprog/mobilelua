/**
 * Create a global instance of the mosync object.
 */
mosync = (function()
{
	var mosync = {};

	// Detect platform.

	mosync.isAndroid =
		navigator.userAgent.indexOf("Android") != -1;

	mosync.isIOS =
		(navigator.userAgent.indexOf("iPod") != -1) ||
		(navigator.userAgent.indexOf("iPhone") != -1) ||
		(navigator.userAgent.indexOf("iPad") != -1);

	mosync.isWindowsPhone =
		navigator.userAgent.indexOf("Windows Phone OS") != -1;

	// The bridge submodule.

	mosync.bridge = (function()
	{
		var bridge = {};
		var rawMessageQueue = [];

		/**
		 * Send raw data to the C++ side.
		 */
		bridge.sendRaw = function(data)
		{
		if (mosync.isAndroid)
		{
			prompt(data, "");
		}
		else if (mosync.isIOS)
		{
			rawMessageQueue.push(data);
			window.location = "mosync://DataAvailable";
		}
		else if (mosync.isWindowsPhone)
		{
			window.external.notify(data);
		}
		};

		/**
		 * Called from iOS runtime to get message.
		 */
		bridge.getMessageData = function()
		{
		if (rawMessageQueue.length == 0)
		{
			// Return an empty string so the iOS runtime
			// knows we don't have any message.
			return "";
		}
		var message = rawMessageQueue.pop();
		return message;
		};

		return bridge;
	})();

	return mosync;
})();