package mosync.lualiveeditor;

import java.awt.Font;
import java.io.File;

import javax.swing.JComponent;

@SuppressWarnings("serial")
public class UIWorkspaceAbstractPane  extends JComponent
{
	protected UIMainWindow mMainUI;

	public UIWorkspaceAbstractPane(UIMainWindow mainUI)
	{
		mMainUI = mainUI;
	}

	public void setText(String data)
	{
	}

	public void openFile(File file)
	{
	}

	public void save()
	{
	}

	public void saveAsFile(File file)
	{
	}

	public File getFile()
	{
		return null;
	}

	public String getSelectedText()
	{
		return null;
	}

	public void setEditorFont(Font font)
	{
	}
}
