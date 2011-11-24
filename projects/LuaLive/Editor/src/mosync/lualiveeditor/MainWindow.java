package mosync.lualiveeditor;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.net.InetAddress;
import java.net.UnknownHostException;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTextArea;
import javax.swing.JTree;
import javax.swing.KeyStroke;
import javax.swing.SwingUtilities;

import mosync.lualiveeditor.MessageThread.Message;

import org.fife.ui.rsyntaxtextarea.RSyntaxTextArea;
import org.fife.ui.rsyntaxtextarea.Style;
import org.fife.ui.rsyntaxtextarea.SyntaxConstants;
import org.fife.ui.rsyntaxtextarea.SyntaxScheme;
import org.fife.ui.rsyntaxtextarea.Token;
import org.fife.ui.rtextarea.RTextScrollPane;

@SuppressWarnings("serial")
public class MainWindow extends JFrame
{
	/**
	 * Default directory for the file open/save dialog.
	 */
	static String sDefaultDirectory = "./examples";

	Server mServer;
	Editor mEditor;
	JTextArea mMessagePane;
	JTextArea mCodeArea;
	MainWindow mSelf;
	String mCurrentFileName;
	JTree mFileTree;

	public MainWindow()
	{
		mSelf = this;

		setCurrentFileName("NoName.lua");

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		createUI();

		// Create and start a new server.
		mServer = new Server(this);
		mServer.startServer();
	}

	private void createUI()
	{
		// Create the menu bar.
		JMenuBar menuBar = new JMenuBar();

		// Create the File menu.
		JMenu fileMenu = new JMenu("File");
		JMenuItem openItem = fileMenu.add("Open");
		openItem.addActionListener(new CommandLoad());
		openItem.setAccelerator(KeyStroke.getKeyStroke(
			KeyEvent.VK_O, InputEvent.CTRL_MASK));

		JMenuItem saveItem = fileMenu.add("Save");
		saveItem.addActionListener(new CommandSave());
		saveItem.setAccelerator(KeyStroke.getKeyStroke(
			KeyEvent.VK_S, InputEvent.CTRL_MASK));

		fileMenu.addSeparator();

		JMenuItem startServerItem = fileMenu.add("Start server");
		startServerItem.addActionListener(new CommandServerStart());

		JMenuItem stopServerItem = fileMenu.add("Stop server");
		stopServerItem.addActionListener(new CommandServerStop());

		// Create the Run menu.
		JMenu runMenu = new JMenu("Run");

		JMenuItem runProgramItem = runMenu.add("Run all");
		runProgramItem.addActionListener(new CommandRunProgram());
		runProgramItem.setAccelerator(KeyStroke.getKeyStroke(
			KeyEvent.VK_R, InputEvent.CTRL_MASK));

		JMenuItem runSelectionItem = runMenu.add("Run selection");
		runSelectionItem.addActionListener(new CommandRunSelection());
		runSelectionItem.setAccelerator(KeyStroke.getKeyStroke(
			KeyEvent.VK_D, InputEvent.CTRL_MASK));

		// Create the Font menu.
		JMenu fontMenu = new JMenu("Font");
		for (int fontSize = 12; fontSize <= 30; fontSize += 2)
		{
			JMenuItem fontItem = fontMenu.add("" + fontSize + " normal");
			fontItem.addActionListener(
				new CommandSetFontSize(
					new Font(Font.MONOSPACED, Font.PLAIN, fontSize)));
			fontItem = fontMenu.add("" + fontSize + " bold");
			fontItem.addActionListener(
				new CommandSetFontSize(
					new Font(Font.MONOSPACED, Font.BOLD, fontSize)));
		}

		// Add menus to the menu bar.
		menuBar.add(fileMenu);
		menuBar.add(runMenu);
		menuBar.add(fontMenu);

		// Show menu bar.
		setJMenuBar(menuBar);

		// Panel for buttons and message pane.
		Box toolPanel = Box.createVerticalBox();
		// toolPanel.setBackground(new Color(200,200,255));
		toolPanel.setAlignmentX(LEFT_ALIGNMENT);

		// Panel for buttons.
		Box buttonPanel = Box.createHorizontalBox();
		// buttonPanel.setBackground(new Color(200,200,255));
		buttonPanel.setAlignmentX(LEFT_ALIGNMENT);
		toolPanel.add(buttonPanel);

		// Text area to display error messages in.
		mMessagePane = new JTextArea(4, 30);
		mMessagePane.setAlignmentX(LEFT_ALIGNMENT);
		mMessagePane.setText("");
		mMessagePane.setEditable(false);
		JScrollPane messageScrollPane = new JScrollPane();
		messageScrollPane.setViewportView(mMessagePane);
		messageScrollPane.setAlignmentX(LEFT_ALIGNMENT);
		toolPanel.add(messageScrollPane);

		// Create buttons.
		JButton button;

		button = new JButton("Run all");
		button.addActionListener(new CommandRunProgram());
		button.setAlignmentX(LEFT_ALIGNMENT);
		buttonPanel.add(button);

		button = new JButton("Run selection");
		button.addActionListener(new CommandRunSelection());
		button.setAlignmentX(LEFT_ALIGNMENT);
		buttonPanel.add(button);

		button = new JButton("Reset client");
		button.addActionListener(new CommandResetClient());
		button.setAlignmentX(LEFT_ALIGNMENT);
		// buttonPanel.add(button);

		button = new JButton("Load...");
		button.addActionListener(new CommandLoad());
		button.setAlignmentX(LEFT_ALIGNMENT);
		// buttonPanel.add(button);

		button = new JButton("Save...");
		button.addActionListener(new CommandSave());
		button.setAlignmentX(LEFT_ALIGNMENT);
		// buttonPanel.add(button);

		button = new JButton("Start server");
		button.addActionListener(new CommandServerStart());
		button.setAlignmentX(LEFT_ALIGNMENT);
		// buttonPanel.add(button);

		button = new JButton("Stop server");
		button.addActionListener(new CommandServerStop());
		button.setAlignmentX(LEFT_ALIGNMENT);
		// buttonPanel.add(button);

		// Add label with host address.
		JLabel label = new JLabel();
		String ipAddress = getServerIpAddress();
		if (null != ipAddress)
		{
			label.setText(
				"  Host address: " + ipAddress +
				"  (use 10.0.2.2 for localhost in Android emulator)");
		}
		else
		{
			label.setText("No Internet connection");
		}
		label.setAlignmentX(LEFT_ALIGNMENT);
		buttonPanel.add(label);

		// Editor view.
		mEditor = new Editor();
		mEditor.setSyntaxEditingStyle(SyntaxConstants.SYNTAX_STYLE_LUA);
		mEditor.setHighlightCurrentLine(false);
		mEditor.setText(""
			+ "---------------------------------------------------\n"
			+ "-- Welcome to the Wonderful World of Mobile Lua! --\n"
			+ "---------------------------------------------------\n"
			+ "\n"
			+ "-- Run this code to display a coloured rectangle.\n"
			+ "Screen:SetColor(255, 255, 255)\n"
			+ "Screen:Fill()\n"
			+ "Screen:SetColor(200, 0, 0)\n"
			+ "Screen:Fill(0, 0, 300, 300)\n"
			+ "Screen:Update()\n");
		mEditor.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 18));
		mEditor.setRoundedSelectionEdges(false);
		SyntaxScheme syntaxSceheme = mEditor.getDefaultSyntaxScheme();
		syntaxSceheme.setStyle(Token.SEPARATOR, new Style(Color.BLACK, null));
		syntaxSceheme.setStyle(Token.LITERAL_STRING_DOUBLE_QUOTE, new Style(
			new Color(0, 0, 175), null));
		syntaxSceheme.setStyle(Token.LITERAL_CHAR, new Style(new Color(0, 0,
			175), null));
		mEditor.setSyntaxScheme(syntaxSceheme);
		RTextScrollPane scrollPane = new RTextScrollPane(mEditor);
		scrollPane.setLineNumbersEnabled(true);

		Container mainEditor = new Container();
		mainEditor.setLayout(new BoxLayout(mainEditor, BoxLayout.PAGE_AXIS));
		mainEditor.add(scrollPane, BorderLayout.CENTER);

		// Tabbed panes?
//		JTabbedPane tabbedPane = new JTabbedPane();
//        tabbedPane.addTab("Custom properties", null, propertyUI,
//                "Custom properties");
//        tabbedPane.addTab("Widget editor", null, widgetEditor,
//                "Custom properties");

// TODO: Add the split pane for the file tree.
//		// File list pane.
//	    mFileTree = new FileTreeComponent(sDefaultDirectory);
//	    JScrollPane fileListScrollPane = new JScrollPane(mFileTree);
//
//		// Split pane.
//		JSplitPane splitPane = new JSplitPane(
//            JSplitPane.HORIZONTAL_SPLIT,
//            fileListScrollPane,
//            mainEditor);
//        splitPane.setOneTouchExpandable(true);
//        splitPane.setDividerLocation(200);
//
//        // Add components.
//        this.add(toolPanel, BorderLayout.SOUTH);
//        this.add(splitPane, BorderLayout.CENTER);

        this.add(toolPanel, BorderLayout.SOUTH);
        this.add(mainEditor, BorderLayout.CENTER);

		// Set window size and show the window.
		setSize(1000, 700);
		setVisible(true);
	}

	/*
	 * For jedit-syntax private void createEditor() { JEditTextArea textArea =
	 * new JEditTextArea(); textArea.setTokenMarker(new JavaTokenMarker());
	 * textArea.setText(text); textArea.recalculateVisibleLines();
	 * textArea.setFirstLine(0); textArea.setElectricScroll(0);
	 * textArea.getPainter().setSelectionColor(
	 * UIManager.getColor("TextArea.selectionBackground"));
	 *
	 * SyntaxStyle[] styles = SyntaxUtilities.getDefaultSyntaxStyles();
	 * styles[Token.COMMENT1] = new SyntaxStyle(Color.GRAY,true,false);
	 * styles[Token.KEYWORD1] = new SyntaxStyle(new Color(0x000080),false,true);
	 * styles[Token.KEYWORD2] = new SyntaxStyle(new Color(0x000080),false,true);
	 * styles[Token.KEYWORD3] = new SyntaxStyle(new Color(0x000080),false,true);
	 * styles[Token.LITERAL1] = new SyntaxStyle(new Color(0x008000),false,true);
	 * styles[Token.LITERAL2] = new SyntaxStyle(new Color(0x000080),false,true);
	 *
	 * textArea.getPainter().setStyles(styles); }
	 */

	private String getServerIpAddress()
	{
		String ipAddress = null;
		try
		{
			String hostName;
			hostName = InetAddress.getLocalHost().getHostName();
			InetAddress addresses[] = InetAddress.getAllByName(hostName);
			for (InetAddress address : addresses)
			{
				if (!address.isLoopbackAddress()
					&& address.isSiteLocalAddress())
				{
					ipAddress = address.getHostAddress();
					break;
				}
			}
		}
		catch (UnknownHostException e)
		{
			e.printStackTrace();
		}
		return ipAddress;
	}

	public void setCurrentFileName(String fileName)
	{
		mCurrentFileName = fileName;
		setTitle("MobileLua Live Editor - " + mCurrentFileName);
	}

	public void showMessage(final String message)
	{
		SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				mMessagePane.setText(mMessagePane.getText() + "\n" + message);
			}
		});
	}

	class CommandServerStart implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandServerStart");
			if (null == mServer)
			{
				mServer = new Server(mSelf);
				mServer.startServer();
			}
		}
	}

	class CommandServerStop implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandServerStop");
			if (null != mServer)
			{
				mServer.postMessage(new Message("CommandServerStop", null));
				mServer = null;
			}
		}
	}

	class CommandRunProgram implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandRunProgram");
			String code = mEditor.getText();
			mServer.postMessage(new Message("CommandRunProgram", code));
		}
	}

	class CommandRunSelection implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandRunSelection");
			String code = mEditor.getSelectedText();
			if (null != code)
			{
				mServer.postMessage(new Message("CommandRunSelection", code));
			}
		}
	}

	class CommandResetClient implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandResetClient");
			mServer.postMessage(new Message("CommandResetClient", 0));
		}
	}

	class CommandLoad implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandLoad");
			JFileChooser fc = new JFileChooser(new File(sDefaultDirectory));
			fc.setCurrentDirectory(new File(sDefaultDirectory));
			fc.showOpenDialog(mSelf);
			File selectedFile = fc.getSelectedFile();
			if (null == selectedFile)
			{
				return;
			}

			StringBuffer contents = new StringBuffer();
			try
			{
				BufferedReader reader = new BufferedReader(new FileReader(
					selectedFile));
				String text;
				// Repeat until all lines is read
				while ((text = reader.readLine()) != null)
				{
					contents.append(text).append(
						System.getProperty("line.separator"));
				}
				reader.close();
			}
			catch (Exception ex)
			{
				ex.printStackTrace();
				return;
			}

			// Set the content of the editor to the new file.
			mEditor.setText(contents.toString());

			// Sets window title to show the filename.
			mSelf.setCurrentFileName(selectedFile.getName());
		}
	}

	class CommandSave implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandSave");
			JFileChooser fc = new JFileChooser(sDefaultDirectory);
			fc.setSelectedFile(new File(mCurrentFileName));
			fc.showSaveDialog(mSelf);
			File selectedFile = fc.getSelectedFile();
			if (null == selectedFile)
			{
				return;
			}

			try
			{
				// Write file.
				Writer output = new BufferedWriter(new FileWriter(selectedFile));
				output.write(mEditor.getText());
				output.close();

				// Sets window title to show the filename.
				mSelf.setCurrentFileName(selectedFile.getName());
			}
			catch (IOException ex)
			{
				ex.printStackTrace();
			}
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
			mEditor.setFont(mFont);
		}
	}

	/**
	 * TODO: Consider moving initialization of the editor here.
	 */
	static class Editor extends RSyntaxTextArea
	{
	}
}
