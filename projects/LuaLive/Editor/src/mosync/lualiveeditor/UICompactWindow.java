package mosync.lualiveeditor;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.io.File;
import java.net.InetAddress;
import java.net.UnknownHostException;

import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.KeyStroke;
import javax.swing.SwingUtilities;

/**
 * This class is NOT USED!
 */
@SuppressWarnings("serial")
public class UICompactWindow extends JFrame
{
	/**
	 * Default directory for the file open/save dialog.
	 */
	static String sDefaultDirectory = "./examples";

	Server mServer;
	JTextArea mMessagePane;
	UICompactWindow mSelf;
	String mCurrentFileName;
	JLabel mFileNameLabel;

	public UICompactWindow()
	{
		mSelf = this;

		setCurrentFileName(" No file selected");

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		createUI();

		// Create and start a new server.
		//mServer = new Server(this);
		//mServer.startServer();
	}

	private void createUI()
	{
		// Create the menu bar.
		JMenuBar menuBar = new JMenuBar();

		// Create the File menu.
		JMenu fileMenu = new JMenu("File");
		JMenuItem openItem = fileMenu.add("Select main file...");
		openItem.addActionListener(new CommandSelectFile());
		openItem.setAccelerator(KeyStroke.getKeyStroke(
			KeyEvent.VK_O, InputEvent.CTRL_MASK));

		fileMenu.addSeparator();

		JMenuItem runProgramItem = fileMenu.add("Reload");
		runProgramItem.addActionListener(new CommandReload());
		runProgramItem.setAccelerator(KeyStroke.getKeyStroke(
			KeyEvent.VK_R, InputEvent.CTRL_MASK));

		fileMenu.addSeparator();

		JMenuItem startServerItem = fileMenu.add("Start server");
		startServerItem.addActionListener(new CommandServerStart());

		JMenuItem stopServerItem = fileMenu.add("Stop server");
		stopServerItem.addActionListener(new CommandServerStop());

		// Add menu to the menu bar.
		menuBar.add(fileMenu);

		// Show menu bar.
		setJMenuBar(menuBar);

		// Text area to display error messages in.
		mMessagePane = new JTextArea(4, 30);
		mMessagePane.setAlignmentX(LEFT_ALIGNMENT);
		mMessagePane.setText("");
		mMessagePane.setEditable(false);
		JScrollPane messageScrollPane = new JScrollPane();
		messageScrollPane.setViewportView(mMessagePane);
		messageScrollPane.setAlignmentX(LEFT_ALIGNMENT);

		// Create components.
		JButton button = new JButton("Reload");
		button.addActionListener(new CommandReload());
		button.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 26));
		button.setSize(300, 300);

		mFileNameLabel = new JLabel();

		// Label with host address.
		JLabel ipAddressLabel = new JLabel();
		String ipAddress = getServerIpAddress();
		if (null != ipAddress)
		{
			ipAddressLabel.setText(
				"Host address: " + ipAddress +
				" (use 10.0.2.2 for localhost in Android emulator)");
		}
		else
		{
			ipAddressLabel.setText(
				"No Internet connection (use 127.0.0.1 for localhost" +
				" or 10.0.2.2 in Android emulator)");
		}

        // Add components.
        this.add(button, BorderLayout.NORTH);
        this.add(mMessagePane, BorderLayout.CENTER);
        this.add(ipAddressLabel, BorderLayout.SOUTH);

		// Set window size and show the window.
		setSize(500, 400);
		setVisible(true);
	}

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
		setTitle("Reload: " + mCurrentFileName);
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
				//mServer = new Server(mSelf);
				//mServer.startServer();
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
				//mServer.postMessage(new Message("CommandServerStop", null));
				//mServer = null;
			}
		}
	}

	class CommandReload implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandReload");
			//String file = mEditor.getText();
			//mServer.postMessage(new Message("CommandReload", file));
		}
	}

	class CommandSelectFile implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			Log.i("CommandSelectFile");
			JFileChooser fc = new JFileChooser(new File(sDefaultDirectory));
			fc.setCurrentDirectory(new File(sDefaultDirectory));
			fc.showOpenDialog(mSelf);
			File selectedFile = fc.getSelectedFile();
			if (null == selectedFile)
			{
				return;
			}

			// Sets window title to show the filename.
			mSelf.setCurrentFileName(selectedFile.getName());
		}
	}
}
