package mosync.lualiveeditor;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Class that walks the file tree and checks for
 * updated files.
 */
public class FileTracker
{
	HashMap<String,FileStatus> mFileStatus = new HashMap<String,FileStatus>();
	String mRootPath;

	public FileTracker(String rootPath)
	{
		mRootPath = rootPath;
	}

	public String getRootPath()
	{
		return mRootPath;
	}

	public ArrayList<String> getUpdatedFiles()
	{
		File dir = new File(mRootPath);
		walkFilesAndUpdateStatus(dir, mFileStatus);

		return buildUpdatedFileList(mFileStatus);
	}

	private ArrayList<String> buildUpdatedFileList(
		HashMap<String,FileStatus> fileStatus)
	{
		ArrayList<String> filePaths = new ArrayList<String>();

		for (FileStatus status : fileStatus.values())
		{
			Log.i("Checking status 2 of " + status.mPath);
			if (status.mUpdated)
			{
				// Save name and reset updated flag.
				filePaths.add(status.mPath);
				status.mUpdated = false;
			}
		}

		return filePaths;
	}

	private void walkFilesAndUpdateStatus(
		File dir,
		HashMap<String,FileStatus> fileStatus)
	{
		try
		{
			Log.i("Walking files in: " + dir.getCanonicalPath());
			for (File file : dir.listFiles())
			{
				if (file.isDirectory())
				{
					walkFilesAndUpdateStatus(file, fileStatus);
				}
				else
				{
					FileStatus status = fileStatus.get(file.getCanonicalPath());
					Log.i("Checking status of " + file.getCanonicalPath());
					if (null != status)
					{
						status.updateModified(file.lastModified());
					}
					else
					{
						fileStatus.put(
							file.getCanonicalPath(),
							new FileStatus(
								file.getCanonicalPath(),
								file.lastModified()));
					}
				}
			}
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
	}

	static class FileStatus
	{
		String mPath;
		long mLastModified;
		boolean mUpdated = true;

		public FileStatus(String path, long lastModified)
		{
			mPath = path;
			mLastModified = lastModified;
		}

		public void updateModified(long lastModified)
		{
			Log.i(" lastModified: " + lastModified);
			Log.i(" mLastModified: " + mLastModified);

			if (lastModified > mLastModified)
			{
				mLastModified = lastModified;
				mUpdated = true;
			}
			else
			{
				mUpdated = false;
			}
		}
	}
}
