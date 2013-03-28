package mosync.lualiveeditor;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JComponent;

@SuppressWarnings("serial")
public class UIWorkspaceEditorPane extends UIWorkspaceAbstractPane
{
	private UIEditor mEditor;

	public UIWorkspaceEditorPane(UIMainWindow mainUI)
	{
		super(mainUI);
		createUI();
	}

	public void setText(String data)
	{
		mEditor.setText(data);
	}

	public void openFile(File file)
	{
		mEditor.openFile(file);
	}

	public void save()
	{
		mEditor.save(false);
	}

	public void saveAsFile(File file)
	{
		mEditor.saveAsFile(file);
	}

	public File getFile()
	{
		return mEditor.getFile();
	}

	public String getSelectedText()
	{
		return mEditor.getSelectedText();
	}

	public void setEditorFont(Font font)
	{
		mEditor.setEditorFont(font);
	}

	private void createUI()
	{
		mEditor = new UIEditor();
		mEditor.setText("Hello");

		JComponent buttonPanel = createButtonPanel();

		this.setLayout(new BorderLayout());
        this.add(mEditor, BorderLayout.CENTER);
		this.add(buttonPanel, BorderLayout.SOUTH);
	}

	private JComponent createButtonPanel()
	{
		// Panel for buttons.
		Box buttonPanel = Box.createHorizontalBox();
		buttonPanel.setAlignmentX(LEFT_ALIGNMENT);

		JButton button;

		button = new JButton("Eval Selection");
		button.addActionListener(mMainUI.new CommandEvalLua());
		button.setAlignmentX(LEFT_ALIGNMENT);
		buttonPanel.add(button);

		button = new JButton("Eval File");
		button.addActionListener(mMainUI.new CommandEvalLua());
		button.setAlignmentX(LEFT_ALIGNMENT);
		buttonPanel.add(button);
/*
		button = new JButton("Eval JS");
		button.addActionListener(mMainUI.new CommandEvalJavaScript());
		button.setAlignmentX(LEFT_ALIGNMENT);
		buttonPanel.add(button);

		button = new JButton("Select To Run");
		button.addActionListener(new CommandSelectToRun());
		button.setAlignmentX(LEFT_ALIGNMENT);
		buttonPanel.add(button);

		button = new JButton("Run Selected");
		button.addActionListener(mMainUI.new CommandRunSelected());
		button.setAlignmentX(LEFT_ALIGNMENT);
		buttonPanel.add(button);
*/
		button = new JButton("Close");
		button.addActionListener(new CommandClose());
		button.setAlignmentX(RIGHT_ALIGNMENT);
		buttonPanel.add(button);

		return buttonPanel;
	}

	class CommandClose implements ActionListener
	{
		@Override
		public void actionPerformed(ActionEvent arg0)
		{
			// Always auto-save before closing if there are changes.
			save();

			// Close this tab.
			mMainUI.closeCurrentTab();
		}
	}

	class CommandSelectToRun implements ActionListener
	{
		@Override
		public void actionPerformed(ActionEvent e)
		{
			if (null != getFile())
			{
				mMainUI.setRunFile(getFile());
			}
		}
	}
}
