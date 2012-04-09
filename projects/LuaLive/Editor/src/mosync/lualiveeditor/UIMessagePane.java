package mosync.lualiveeditor;

import java.awt.BorderLayout;

import javax.swing.Box;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.SwingUtilities;

@SuppressWarnings("serial")
public class UIMessagePane extends JComponent
{
	private JTextArea mMessagePane;
	private JLabel mStatusLabel;

	public UIMessagePane()
	{
		// Text area to display error messages in.
		mMessagePane = new JTextArea(4, 30);
		mMessagePane.setAlignmentX(JTextArea.LEFT_ALIGNMENT);
		mMessagePane.setText("");
		mMessagePane.setEditable(false);
		JScrollPane scroller = new JScrollPane();
		scroller.setViewportView(mMessagePane);
		scroller.setAlignmentX(JScrollPane.LEFT_ALIGNMENT);

		this.setLayout(new BorderLayout());

		// Panel for buttons.
		Box labelPane = Box.createHorizontalBox();
		//buttonPanel.setBackground(new Color(200,200,255));
		labelPane.setAlignmentX(LEFT_ALIGNMENT);

		// Add label with host address.
		JLabel label = new JLabel();
		label.setText("File To Run: (None Selected)");
		label.setAlignmentX(LEFT_ALIGNMENT);

		mStatusLabel = label;

		// Add components.
		labelPane.add(label);
		this.add(labelPane, BorderLayout.NORTH);
		this.add(scroller, BorderLayout.CENTER);
	}

	public void showMessage(final String message)
	{
		SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				mMessagePane.setText(mMessagePane.getText() + message + "\n");
			}
		});
	}

	public void setStatusMessage(final String message)
	{
		SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				mStatusLabel.setText(message);
			}
		});
	}
}
