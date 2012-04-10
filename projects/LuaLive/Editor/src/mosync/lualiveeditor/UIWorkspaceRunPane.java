package mosync.lualiveeditor;

import java.awt.BorderLayout;
import java.awt.Font;

import javax.swing.JButton;

@SuppressWarnings("serial")
public class UIWorkspaceRunPane extends UIWorkspaceAbstractPane
{
	public UIWorkspaceRunPane(UIMainWindow mainUI)
	{
		super(mainUI);
		createUI();
	}

	private void createUI()
	{
		JButton button = new JButton("Run");
		button.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 100));
        button.addActionListener(mMainUI.new CommandRunSelected());
		this.setLayout(new BorderLayout());
        this.add(button, BorderLayout.CENTER);
	}
}
