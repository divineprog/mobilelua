package mosync.lualiveeditor;

import java.awt.Font;
import java.io.File;

import javax.swing.JFileChooser;
import javax.swing.JTabbedPane;

@SuppressWarnings("serial")
public class UIWorkspaceTabbedContainer extends JTabbedPane
{
	private UIMainWindow mMainUI;

	public UIWorkspaceTabbedContainer(UIMainWindow mainWindow)
	{
		mMainUI = mainWindow;
	}

	public void openPlayspace()
	{
		UIWorkspaceEditorPane editor = new UIWorkspaceEditorPane(mMainUI);
		this.addTab("Playspace", editor);
		int tabIndex = this.getTabCount() - 1;
		setSelectedIndex(tabIndex);

		String text = ""
			+ "---------------------------------------------------------\n"
			+ "----- Welcome to the Wonderful World of Mobile Lua! -----\n"
			+ "---------------------------------------------------------\n"
			+ "\n"
			+ "-- The LuaLive editor is used to live code mobile applications\n"
			+ "-- right on a mobile device or emulator. Supported platforms\n"
			+ "-- include Android, iOS, and Windows Phone. You can develop\n"
			+ "-- in Lua and/or HTML5 and JavaScript. This tutorial takes\n"
			+ "-- you on a tour.\n"
			+ "-- \n"
			+ "-- The most convenient way to set up the network connection\n"
			+ "-- between your computer and the mobile device usually is to\n"
			+ "-- connect them to the same local network. The LuaLive app\n"
			+ "-- running on the device connects to the editor on the computer,\n"
			+ "-- and executes commands and programs sent from the editor.\n"
			+ "-- \n"
			+ "-- Start by installing the LuaLive client app on your device.\n"
			+ "-- The Help menu takes you to the download page. Then start\n"
			+ "-- the LuaLive client app and enter the IP-address of the editor:\n"
			+ "-- IP_ADDRESS (use 10.0.2.2 for localhost in the Android emulator).\n"
			+ "-- \n"
			+ "-- Note that there are two variations of the LuaLive client,\n"
			+ "-- LuaLiveClient and LuaLiveClienX. The X-version is experimental\n"
			+ "-- and supports the MoSync Wormhole system, much like MoSync Reload.\n"
			+ "-- The code below assumes you use the LuaLiveClient version (non-X).\n"
			+ "-- \n"
			+ "-- Now we can try out some Lua code. Evaluate this snippet\n"
			+ "-- by selecting it in the editor, then press button [Eval Lua]:\n"
			+ "\n"
			+ "mosync.Screen:SetColor(255, 255, 255)\n"
			+ "mosync.Screen:Fill()\n"
			+ "mosync.Screen:SetColor(200, 0, 0)\n"
			+ "mosync.Screen:FillRect(0, 0, 300, 300)\n"
			+ "mosync.Screen:Update()\n"
			+ "\n"
			+ "-- The above code displays a colored rectangle.\n"
			+ "\n"
			+ "-- Next, lets make a NativeUI in Lua. Select the evaluate\n"
			+ "-- the following code:\n"
			+ "\n"
			+ "Screen = mosync.NativeUI:CreateWidget\n"
			+ "{\n"
			+ "  type = \"Screen\"\n"
			+ "}\n"
			+ "\n"
			+ "Button = mosync.NativeUI:CreateButton\n"
			+ "{\n"
			+ "  parent = Screen,\n"
			+ "  width = mosync.FILL_PARENT,\n"
			+ "  height = mosync.FILL_PARENT,\n"
			+ "  text = \"Click Me\",\n"
			+ "  eventFun = function(self, widgetEvent)\n"
			+ "    Counter = Counter + 1\n"
			+ "    Button:SetProp(\n"
			+ "      \"text\", \n"
			+ "      \"You Clicked Me \"..Counter..\"Times\")\n"
			+ "  end\n"
			+ "}\n"
			+ "\n"
			+ "Counter = 0\n"
			+ "\n"
			+ "mosync.NativeUI:ShowScreen(Screen)\n"
			+ "\n"
			+ "-- You can interactively modify the program.\n"
			+ "-- Select and evaluate this line to change the button text:\n"
			+ "\n"
			+ "Button:SetProp(\"text\", \"Hello World\")\n"
			+ "\n"
			+ "-- Update the value of the variable Counter:\n"
			+ "\n"
			+ "Counter = 1000\n"
			+ "\n"
			+ "-- Then click the button in the app to see what happens.\n"
			+ "\n"
			+ "-- Show the MoSync drawing screen again:\n"
			+ "\n"
			+ "mosync.NativeUI:ShowDefaultScreen()\n"
			+ "\n"
			+ "-- And show the NativeUI screen:\n"
			+ "\n"
			+ "mosync.NativeUI:ShowScreen(Screen)\n"
			+ "\n"
			+ "-- Next, we will do some experiments with JavaScript and HTML.\n"
			+ "-- Do you remember the LuaLive client's start screen? It is still\n"
			+ "-- around. Show it by evaluating this line of code:\n"
			+ "\n"
			+ "mosync.NativeUI:ShowScreen(LuaLive.Screen)\n"
			+ "\n"
			+ "-- Now we have a WebView to play with. Lets set the HTML of the body "
			+ "-- of that WebView. Evaluate this code, but now press [Eval JS] because"
			+ "-- this is JavaScript:\n"
			+ "\n"
			+ "savedHTML = document.body.innerHTML\n"
			+ "document.body.innerHTML = \"<h1>Hello World</h1>\"\n"
			+ "document.body.style.backgroundColor = \"red\"\n"
			+ "\n"
			+ "-- Since we saved the original HTML, we can restore the page:\n"
			+ "\n"
			+ "document.body.innerHTML = savedHTML\n"
			+ "\n"

			+ "-- Set the HTML of the WebView. This is Lua code, eval with [Eval Lua]:\n"
			+ "\n"
			+ "LuaLive.WebView:SetProp(\n"
			+ "  mosync.MAW_WEB_VIEW_HTML,\n"
			+ "  -- This is a Lua multiline string.\n"
			+ "  [==[\n"
			+ "<!DOCTYPE html>\n"
			+ "<html>\n"
			+ "<head>\n"
			+ "<meta name=\"viewport\" content=\"width=320, user-scalable=yes\">\n"
			+ "<!-- Include the mosync.bridge script, so that we can call\n"
			+ "Lua from JavaScript. -->\n"
			+ "<script>\n"
			+ "]==] .. mosync.NativeUI:GetMoSyncBridgeJSScript() .. [==[\n"
			+ "</script>\n"
			+ "</head>\n"
			+ "<body>\n"
			+ "<div>\n"
			+ "  <input\n"
			+ "    id=\"VibrateButton\"\n"
			+ "    type=\"button\"\n"
			+ "    value=\"Vibrate\"\n"
			+ "    onclick=\"Vibrate()\"/>\n"
			+ "</div>\n"
			+ "<script>\n"
			+ "function Vibrate()\n"
			+ "{\n"
			+ "  EvalLua(\"mosync.maVibrate(500)\")\n"
			+ "}\n"
			+ "\n"
			+ "function EvalLua(script)\n"
			+ "{\n"
			+ "  mosync.bridge.sendRaw(escape(script))\n"
			+ "}\n"
			+ "</script>\n"
			+ "\n"
			+ "</body>\n"
			+ "</html>\n"
			+ "]==])\n"
			+ "\n"
			+ "-- Finally, we can have some fun by exiting the app by\n"
			+ "-- evaluating this Lua code (this does not work on iOS):\n"
			+ "\n"
			+ "mosync.maExit(0)\n"
			;
			
			String ipAddress = mMainUI.getIpAddress();
			if (null == ipAddress)
			{
				ipAddress = "<none detected>";
			}
			editor.setText(text.replace("IP_ADDRESS", ipAddress));
	}

	public void openRunButtonTab()
	{
		int index = this.indexOfTab("Run");
		if (index < 0)
		{
			// No Run tab exists, create it.
			UIWorkspaceRunPane pane = new UIWorkspaceRunPane(mMainUI);
			this.addTab("Run", pane);
			int tabIndex = this.getTabCount() - 1;
			setSelectedIndex(tabIndex);
		}
		else
		{
			// Tab exists, show it.
			setSelectedIndex(index);
		}
	}

	public void openFile(File file)
	{
		try
		{
			int tabIndex = getTabIndexForFile(file);
			if (tabIndex > -1)
			{
				// Show existing tab.
				setSelectedIndex(tabIndex);
			}
			else
			{
				// File is not open.
				String fileName = Server.FileData.fileName(Server.FileData
					.unixPath(file.getCanonicalPath()));
				UIWorkspaceEditorPane editor = new UIWorkspaceEditorPane(mMainUI);
				editor.openFile(file);
				this.addTab(fileName, editor);
				tabIndex = this.getTabCount() - 1;
				setSelectedIndex(tabIndex);
			}
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
	}

	public void saveCurrentFile()
	{
		int i = getSelectedIndex();
		Log.i("saveCurrentFile i = " + i);
		UIWorkspaceAbstractPane pane = (UIWorkspaceAbstractPane) getComponentAt(i);
		Log.i("saveCurrentFile pane = " + pane);
		pane.save();
	}

	public void saveCurrentFileAs()
	{
		int i = getSelectedIndex();
		UIWorkspaceAbstractPane pane = (UIWorkspaceAbstractPane) getComponentAt(i);
		File file = pane.getFile();
		if (null == file)
		{
			file = mMainUI.getLastFile();
		}

		JFileChooser fc = new JFileChooser(file);
		fc.setCurrentDirectory(file);
		fc.setSelectedFile(file);
		fc.showSaveDialog(mMainUI);
		File selectedFile = fc.getSelectedFile();
		if (null == selectedFile)
		{
			return;
		}

		// Save file
		pane.saveAsFile(selectedFile);

		// Update tab title.
		setTitleAt(i, Server.FileData.fileName(
			Server.FileData.unixPath(selectedFile)));
	}

	public void saveAll()
	{
		for (int i = 0; i < getTabCount(); ++i)
		{
			UIWorkspaceAbstractPane pane = (UIWorkspaceAbstractPane) getComponentAt(i);
			pane.save();
		}
	}

	public void closeCurrentTab()
	{
		int index = this.getSelectedIndex();
		this.removeTabAt(index);
	}

	public String getSelectedText()
	{
		int i = getSelectedIndex();
		UIWorkspaceAbstractPane pane = (UIWorkspaceAbstractPane) getComponentAt(i);
		return pane.getSelectedText();
	}

	public void setFontForAllEditors(Font font)
	{
		for (int i = 0; i < getTabCount(); ++i)
		{
			UIWorkspaceAbstractPane pane = (UIWorkspaceAbstractPane) getComponentAt(i);
			pane.setEditorFont(font);
		}
	}

	private int getTabIndexForFile(File file)
	{
		for (int i = 0; i < getTabCount(); ++i)
		{
			UIWorkspaceAbstractPane pane = (UIWorkspaceAbstractPane) getComponentAt(i);
			File f = pane.getFile();
			if (null != f && f.equals(file))
			{
				return i;
			}
		}

		return -1;
	}
}
