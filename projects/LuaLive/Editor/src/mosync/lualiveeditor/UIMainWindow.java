package mosync.lualiveeditor;

import java.awt.BorderLayout;
import java.awt.Desktop;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.io.File;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.URI;
import java.net.UnknownHostException;
import java.util.Collections;
import java.util.Enumeration;

import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JSplitPane;
import javax.swing.KeyStroke;

import mosync.lualiveeditor.MessageQueue.Message;

@SuppressWarnings("serial")
public class UIMainWindow extends JFrame
{
	/**
	 * Default directory for the file open/save dialog.
	 */
	static File sDefaultDirectory = new File("./examples");

	private UIMainWindow mMainUI;
	private Server mServer;
	private UIMessagePane mMessagePane;
	private UIFileTree mFileTree;
	private UIWorkspaceTabbedContainer mWorkspaceTabPane;
	//private File mRunFile; // File to run (reload)
	private File mLastFile = sDefaultDirectory;

	public UIMainWindow()
	{
		mMainUI = this;

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		createUI();

		// Create and start a new server.
		mServer = new Server(this);
		mServer.startServer();
	}

	public File getLastFile()
	{
		return mLastFile;
	}

	public void saveFile()
	{
		mWorkspaceTabPane.saveCurrentFile();
	}

	public void openFile(File file)
	{
		mWorkspaceTabPane.openFile(file);
	}

	public void closeCurrentTab()
	{
		mWorkspaceTabPane.closeCurrentTab();
	}
/*
	public void selectFileToRun()
	{
		File file = null != mRunFile ? mRunFile : sDefaultDirectory;
		JFileChooser fc = new JFileChooser(file);
		fc.setCurrentDirectory(file);
		fc.showOpenDialog(mMainUI);
		File selectedFile = fc.getSelectedFile();
		if (null == selectedFile)
		{
			return;
		}

		// Sets window title to show the filename.
		mMainUI.setRunFile(selectedFile);
	}
*/
	public void evalFile(File file)
	{
		Log.i("Eval File");
		
		mWorkspaceTabPane.saveAll();

		String code = Server.FileData.readFileAsString(file);
		if (null != code)
		{
			mServer.postMessage(new Message("CommandEvalLua", code));
		}
	}
	
	public void sendFile(File file)
	{
		Log.i("Send File");
		mWorkspaceTabPane.saveAll();
		mServer.postMessage(new Message("CommandSendFile", file));
	}
/*
	public void runFile(File file)
	{
		mWorkspaceTabPane.saveAll();
		mServer.postMessage(new Message("CommandRun", file));
	}
	
	public void setRunFile(File file)
	{
		try
		{
			mRunFile = file;

			String fileName = Server.FileData.unixPath(file.getCanonicalPath());
			mMessagePane.setStatusMessage("Run File: " + fileName);
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
	}
*/
	public void showMessage(final String message)
	{
		mMessagePane.showMessage(message);
	}

	private void createUI()
	{
		// Create the menu bar.
		createMenuBar();

		// Workspace pane.
		mWorkspaceTabPane = new UIWorkspaceTabbedContainer(this);

		// Open initial "playspace" tab.
		mWorkspaceTabPane.openPlayspace();

		// File list pane.
	    mFileTree = new UIFileTree("/", this);
	    JComponent fileTreeComponent = mFileTree.embedInScrollPane();

		// Message pane.
		mMessagePane = new UIMessagePane();
		mMessagePane.showMessage(getIpAddressHelpText());

		// Split pane for the FileTree and the WorkspacePane.
		JSplitPane horizontalSplitPane = new JSplitPane(
            JSplitPane.HORIZONTAL_SPLIT,
            fileTreeComponent,
            mWorkspaceTabPane);
		horizontalSplitPane.setOneTouchExpandable(true);
		horizontalSplitPane.setDividerLocation(200); // Hide = 0

        // Split pane for the MainPane and the ToolPane.
		JSplitPane verticalSplitPane = new JSplitPane(
            JSplitPane.VERTICAL_SPLIT,
            horizontalSplitPane,
            mMessagePane);
		verticalSplitPane.setOneTouchExpandable(true);
		verticalSplitPane.setDividerLocation(500);
		verticalSplitPane.setResizeWeight(1.0);

		add(verticalSplitPane, BorderLayout.CENTER);

		// Set window size and show the window.
		setSize(1000, 700);
		setVisible(true);

		setTitle("LuaLive - " + getIpAddressHelpText());
	}

	private void createMenuBar()
	{
		// Create the menu bar.
		JMenuBar menuBar = new JMenuBar();

		// Create the File menu.
		JMenu fileMenu = new JMenu("File");

		JMenuItem openItem = fileMenu.add("Open File...");
		openItem.setAccelerator(KeyStroke.getKeyStroke(
			KeyEvent.VK_O, InputEvent.CTRL_MASK));
		openItem.addActionListener(new CommandOpenFile());

		JMenuItem saveItem = fileMenu.add("Save File");
		saveItem.setAccelerator(KeyStroke.getKeyStroke(
			KeyEvent.VK_S, InputEvent.CTRL_MASK));
		saveItem.addActionListener(new CommandSaveFile());

		JMenuItem saveAsItem = fileMenu.add("Save File As...");
		saveAsItem.addActionListener(new CommandSaveFileAs());

		fileMenu.addSeparator();

		JMenuItem playspaceItem = fileMenu.add("New Playspace Tab");
		playspaceItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				mWorkspaceTabPane.openPlayspace();
			}
		});

		fileMenu.addSeparator();

		JMenuItem closeItem = fileMenu.add("Close Current Tab");
		closeItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				mWorkspaceTabPane.closeCurrentTab();
			}
		});

		fileMenu.addSeparator();

		JMenuItem startServerItem = fileMenu.add("Start Server");
		startServerItem.addActionListener(new CommandServerStart());

		JMenuItem stopServerItem = fileMenu.add("Stop Server");
		stopServerItem.addActionListener(new CommandServerStop());

		fileMenu.addSeparator();

		JMenuItem exitItem = fileMenu.add("Exit");
		exitItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				System.exit(0);
			}
		});

		// Create the Run menu.
		JMenu runMenu = new JMenu("Eval");

		JMenuItem evalLuaItem = runMenu.add("Eval Selection");
		evalLuaItem.setAccelerator(KeyStroke.getKeyStroke(
			KeyEvent.VK_E, InputEvent.CTRL_MASK));
		evalLuaItem.addActionListener(new CommandEvalLua());
        
		JMenuItem mMenuItemRun = runMenu.add("Eval All (Run)");
		mMenuItemRun.setAccelerator(KeyStroke.getKeyStroke(
			KeyEvent.VK_R, InputEvent.CTRL_MASK));
		mMenuItemRun.addActionListener(new CommandEvalLuaAll());
/*
		runMenu.addSeparator();

		JMenuItem runTabItem = runMenu.add("Open Eval All Button Tab");
		runTabItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				mWorkspaceTabPane.openRunButtonTab();
			}
		});

		JMenuItem runFileSelectItem = runMenu.add("Select File To Run...");
		runFileSelectItem.addActionListener(new CommandSelectFileToRun());

		JMenuItem clearFileTrackerItem = runMenu.add("Reset File Tracker");
		clearFileTrackerItem.addActionListener(new CommandResetFileTracker());

		runMenu.addSeparator();

		JMenuItem evalJavaScriptItem = runMenu.add("Eval JavaScript");
		evalJavaScriptItem.setAccelerator(KeyStroke.getKeyStroke(
			KeyEvent.VK_J, InputEvent.CTRL_MASK));
		evalJavaScriptItem.addActionListener(new CommandEvalJavaScript());
*/
		// Create the Font menu.
		JMenu fontMenu = new JMenu("Font");
		for (int fontSize = 12; fontSize <= 30; fontSize += 2)
		{
			JMenuItem fontItem = fontMenu.add("" + fontSize + " Normal");
			fontItem.addActionListener(
				new CommandSetFontSize(
					new Font(Font.MONOSPACED, Font.PLAIN, fontSize)));
		}
		for (int fontSize = 12; fontSize <= 30; fontSize += 2)
		{
			JMenuItem fontItem = fontMenu.add("" + fontSize + " Bold");
			fontItem.addActionListener(
				new CommandSetFontSize(
					new Font(Font.MONOSPACED, Font.BOLD, fontSize)));
		}

		// Create the Help menu.
		JMenu helpMenu = new JMenu("Help");

		JMenuItem docItem = helpMenu.add("MobileLua Documentation Wiki...");
		docItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				openWebBrowser("https://github.com/divineprog/mobilelua/wiki");
			}
		});

		JMenuItem projectItem = helpMenu.add("MobileLua Project Site...");
		projectItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				openWebBrowser("https://github.com/divineprog/mobilelua/");
			}
		});

		JMenuItem mosyncItem = helpMenu.add("MoSync Web Site...");
		mosyncItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				openWebBrowser("http://mosync.com");
			}
		});

		JMenuItem aboutItem = helpMenu.add("About...");
		aboutItem.addActionListener(new ActionListener()
		{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				JOptionPane.showMessageDialog(
					null,
					"<html>LuaLive Editor, 2013-03-30<br/>"
					+ "Built with MoSync Technology<br/>"
					+ "Author: Mikael Kindborg<br/>",
					"About",
					JOptionPane.INFORMATION_MESSAGE);
			}
		});

		// Add menus to the menu bar.
		menuBar.add(fileMenu);
		menuBar.add(runMenu);
		menuBar.add(fontMenu);
		menuBar.add(helpMenu);

		// Show menu bar.
		setJMenuBar(menuBar);
	}

	private void openWebBrowser(String url)
	{
		try
		{
			if (Desktop.isDesktopSupported())
			{
				Desktop.getDesktop().browse(new URI(url));
			}
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
	}

	private String getIpAddressHelpText()
	{
		String ipAddress = getIpAddress();

		if (null == ipAddress)
		{
			ipAddress = "127.0.0.1";
		}

		return
			"IP-address: " + ipAddress +
			" (use 10.0.2.2 for localhost in Android emulator)";
	}

	public String getIpAddress()
	{
		String ipAddress = "unknown";
		try
		{
			for (NetworkInterface networkInterface : Collections.list(
					NetworkInterface.getNetworkInterfaces()))
			{
				if (networkInterface.isUp() && !networkInterface.isLoopback())
				{
		 	        for (InetAddress inetAddress : Collections.list(
		 	        		networkInterface.getInetAddresses())) 
		 	        {
		 	        	if (inetAddress.isSiteLocalAddress())
		 	        	{
							ipAddress = inetAddress.getHostAddress();
							break;
		 	        	}
		 	        }
		 	    }
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
        return ipAddress;
    }
/*
	public String OLD_getIpAddress()
	{
		String ipAddress = null;
		try
		{
			String hostName;
			hostName = InetAddress.getLocalHost().getHostName();
			InetAddress addresses[] = InetAddress.getAllByName(hostName);
			for (InetAddress address : addresses)
			{
				Log.i("address.getHostName " + address.getHostName());
				Log.i("address.getHostAddress " + address.getHostAddress());
				if (!address.isLoopbackAddress()
					&& address.isSiteLocalAddress())
				{
					ipAddress = address.getHostAddress();
					//break;
				}
			}
		}
		catch (UnknownHostException e)
		{
			e.printStackTrace();
		}
		return ipAddress;
	}
*/
	class CommandServerStart implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			if (null == mServer)
			{
				mServer = new Server(mMainUI);
				mServer.startServer();
			}
		}
	}

	class CommandServerStop implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			if (null != mServer)
			{
				mServer.postMessage(new Message("CommandServerStop", null));
				mServer = null;
			}
		}
	}
/*
	class CommandRunSelected implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			if (null == mRunFile)
			{
				selectFileToRun();
			}
			if (null != mRunFile)
			{
				runFile(mRunFile);
			}
		}
	}

	class CommandSelectFileToRun implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			selectFileToRun();
		}
	}

	class CommandResetFileTracker implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			mServer.postMessage(new Message("CommandResetFileTracker", null));
		}
	}
*/
	class CommandEvalLua implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandEvalLua");
			String code = mWorkspaceTabPane.getSelectedText();
			if (null != code)
			{
				mServer.postMessage(new Message("CommandEvalLua", code));
			}
		}
	}

	class CommandEvalLuaAll implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandEvalLuaAll");
			String code = mWorkspaceTabPane.getSelectedText();
			if (null != code)
			{
				mServer.postMessage(new Message("CommandEvalLuaAll", code));
			}
		}
	}
/*
	class CommandEvalJavaScript implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandEvalJavaScript");
			String code = mWorkspaceTabPane.getSelectedText();
			if (null != code)
			{
				mServer.postMessage(new Message("CommandEvalJavaScript", code));
			}
		}
	}
*/
	class CommandResetClient implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandResetClient");
			mServer.postMessage(new Message("CommandResetClient", 0));
		}
	}

	class CommandOpenFile implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			JFileChooser fc = new JFileChooser(mLastFile);
			fc.setCurrentDirectory(mLastFile);
			fc.showOpenDialog(mMainUI);
			File selectedFile = fc.getSelectedFile();
			if (null == selectedFile)
			{
				return;
			}

			mWorkspaceTabPane.openFile(selectedFile);
		}
	}

	class CommandSaveFile implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			mWorkspaceTabPane.saveCurrentFile();
		}
	}

	class CommandSaveFileAs implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			mWorkspaceTabPane.saveCurrentFileAs();
		}
	}

	class CommandSetFontSize implements ActionListener
	{
		Font mFont;

		public CommandSetFontSize(Font font)
		{
			mFont = font;
		}

		public void actionPerformed(ActionEvent e)
		{
			mWorkspaceTabPane.setFontForAllEditors(mFont);
		}
	}
}
