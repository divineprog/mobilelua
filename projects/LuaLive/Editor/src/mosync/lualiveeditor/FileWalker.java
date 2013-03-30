package mosync.lualiveeditor;

import java.io.File;
import java.util.ArrayList;

/**
 * Class that walks the file tree and collects files
 * in all subdirectories if a directory is specified
 * as root path.
 */
public class FileWalker
{
	// File to start walking from (if directory).
	String mRootPath;
	
	// Collected files.
	ArrayList<String> mFiles;

	public FileWalker()
	{
	}
	
	public ArrayList<String> collectFiles(String path)
	{
		mFiles = new ArrayList<String>();
		File file = new File(path);
		walkFiles(file);
		return mFiles;
	}

	private void walkFiles(File file)
	{
		try
		{
			if (file.isDirectory())
			{
				for (File f : file.listFiles())
				{
					walkFiles(f);
				}
			}
			else
			{
				String path = Server.FileData.unixPath(file);
				mFiles.add(path);
			}
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
	}
}
