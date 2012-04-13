package mosync.lualiveeditor;

import java.awt.Color;
import java.awt.Font;
import java.io.File;

import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

import org.fife.ui.rsyntaxtextarea.RSyntaxTextArea;
import org.fife.ui.rsyntaxtextarea.Style;
import org.fife.ui.rsyntaxtextarea.SyntaxConstants;
import org.fife.ui.rsyntaxtextarea.SyntaxScheme;
import org.fife.ui.rsyntaxtextarea.Token;
import org.fife.ui.rtextarea.RTextScrollPane;


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

/**
 * Editor area.
 */
@SuppressWarnings("serial")
class UIEditor extends RTextScrollPane
{
	private UIEditor mScrollPane;
	private RSyntaxTextArea mEditor;
	private File mFile;
	// Flag to keep track of edit changes.
	private String mOriginalContent = "";

	public UIEditor()
	{
		mScrollPane = this;
		mScrollPane.setLineNumbersEnabled(true);

		mEditor = new RSyntaxTextArea();
		mEditor.setHighlightCurrentLine(false);
		mEditor.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 18));
		mEditor.setRoundedSelectionEdges(false);
		SyntaxScheme syntaxSceheme = mEditor.getDefaultSyntaxScheme();
		syntaxSceheme.setStyle(
			Token.SEPARATOR,
			new Style(Color.BLACK, null));
		syntaxSceheme.setStyle(
			Token.LITERAL_STRING_DOUBLE_QUOTE,
			new Style(new Color(0, 0, 175), null));
		syntaxSceheme.setStyle(
			Token.LITERAL_CHAR,
			new Style(new Color(0, 0, 175), null));
		mEditor.setSyntaxScheme(syntaxSceheme);

		mScrollPane.setViewportView(mEditor);

		// Listener that tracks updates.
		//createDocumentListener();

		// TODO: Make dynamic based on file extension.
		mEditor.setSyntaxEditingStyle(SyntaxConstants.SYNTAX_STYLE_LUA);
	}

	public void setText(String text)
	{
		mOriginalContent = text;
		mEditor.setText(text);
	}

	public String getSelectedText()
	{
		return mEditor.getSelectedText();
	}

	public void openFile(File file)
	{
		// TODO: Add syntax setting based on file name extension.
		mFile = file;
		String data = Server.FileData.readFileAsString(file);
		if (null != data)
		{
			setText(data);
		}
		else
		{
			setText("Could not open file.");
		}
	}

	public void save(boolean forceSave)
	{
		String data = mEditor.getText();
		boolean updated = ! mOriginalContent.equals(data);
		if (null != mFile && (updated || forceSave))
		{
			Server.FileData.writeFileAsString(mFile, data);
			mOriginalContent = data;
			Log.i("Saved file");
		}
	}
	
	public void saveAsFile(File file)
	{
		mFile = file;
		save(true);
	}

	public File getFile()
	{
		return mFile;
	}

	public void setEditorFont(Font font)
	{
		mEditor.setFont(font);
	}
}