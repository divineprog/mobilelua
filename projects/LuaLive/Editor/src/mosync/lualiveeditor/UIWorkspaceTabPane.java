package mosync.lualiveeditor;

import java.awt.Font;
import java.io.File;

import javax.swing.JFileChooser;
import javax.swing.JTabbedPane;

@SuppressWarnings("serial")
public class UIWorkspaceTabPane extends JTabbedPane
{
	private UIMainWindow mMainUI;

	public UIWorkspaceTabPane(UIMainWindow mainWindow)
	{
		mMainUI = mainWindow;
	}

	public void openPlayspace()
	{
		UIWorkspacePane editor = new UIWorkspacePane(mMainUI);
		this.addTab("Playspace", editor);
		int tabIndex = this.getTabCount() - 1;
		setSelectedIndex(tabIndex);

		editor.setText(""
			+ "---------------------------------------------------\n"
			+ "-- Welcome to the Wonderful World of Mobile Lua! --\n"
			+ "---------------------------------------------------\n" + "\n"
			+ "-- Run this code to display a coloured rectangle.\n"
			+ "mosync.Screen:SetColor(255, 255, 255)\n"
			+ "mosync.Screen:Fill()\n" + "mosync.Screen:SetColor(200, 0, 0)\n"
			+ "mosync.Screen:FillRect(0, 0, 300, 300)\n"
			+ "mosync.Screen:Update()\n");
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
				UIWorkspacePane editor = new UIWorkspacePane(mMainUI);
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
		UIWorkspacePane pane = (UIWorkspacePane) getComponentAt(i);
		Log.i("saveCurrentFile pane = " + pane);
		pane.save();
	}

	public void saveCurrentFileAs()
	{
		int i = getSelectedIndex();
		UIWorkspacePane pane = (UIWorkspacePane) getComponentAt(i);
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
			UIWorkspacePane pane = (UIWorkspacePane) getComponentAt(i);
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
		UIWorkspacePane pane = (UIWorkspacePane) getComponentAt(i);
		return pane.getSelectedText();
	}

	public void setFontForAllEditors(Font font)
	{
		for (int i = 0; i < getTabCount(); ++i)
		{
			UIWorkspacePane pane = (UIWorkspacePane) getComponentAt(i);
			pane.setEditorFont(font);
		}
	}

	private int getTabIndexForFile(File file)
	{
		for (int i = 0; i < getTabCount(); ++i)
		{
			UIWorkspacePane pane = (UIWorkspacePane) getComponentAt(i);
			File f = pane.getFile();
			if (null != f && f.equals(file))
			{
				return i;
			}
		}

		return -1;
	}
}
