package mosync.lualiveeditor;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.io.IOException;

import javax.swing.JComponent;
import javax.swing.JMenuItem;
import javax.swing.JPopupMenu;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.event.TreeModelListener;
import javax.swing.tree.TreeModel;
import javax.swing.tree.TreePath;

/**
 * Component that displays a tree of files.
 * @author Mikael Kindborg
 */
@SuppressWarnings("serial")
public class UIFileTree extends JTree
{
	JTree mFileTree;
	JPopupMenu mPopupMenu;
	UIMainWindow mMainUI;
	TreePath mSelectedTreePath;

	public UIFileTree(String path, UIMainWindow mainUI)
	{
		// Create file tree view.
		mMainUI = mainUI;
		mFileTree = this;
		FileTreeModel model = new FileTreeModel(new FileModel(path));
	    mFileTree.setModel(model);
	    mFileTree.addMouseListener(new FileTreeMouseListener());

	    // Create popup menu.
	    mPopupMenu = new JPopupMenu();
	    JMenuItem menuItem = new JMenuItem("Open");
	    menuItem.addActionListener(new ActionListener()
	    {
			@Override
			public void actionPerformed(ActionEvent e)
			{
				FileModel model =
					(FileModel) mSelectedTreePath.getLastPathComponent();
				if (model.isFile())
				{
					mMainUI.openFile(model.getFile());
				}
			}
	    });
	    mPopupMenu.add(menuItem);

	    menuItem = new JMenuItem("Select To Run");
	    menuItem.addActionListener(new ActionListener()
	    {
			@Override
			public void actionPerformed(ActionEvent e)
			{
				Log.i("Select To Run");
				FileModel model =
					(FileModel) mSelectedTreePath.getLastPathComponent();
				if (model.isFile())
				{
					mMainUI.setRunFile(model.getFile());
				}
			}
	    });
	    mPopupMenu.add(menuItem);

	    menuItem = new JMenuItem("Run");
	    menuItem.addActionListener(new ActionListener()
	    {
			@Override
			public void actionPerformed(ActionEvent e)
			{
				Log.i("Run");
				FileModel model =
					(FileModel) mSelectedTreePath.getLastPathComponent();
				if (model.isFile())
				{
					mMainUI.runFile(model.getFile());
				}
			}
	    });
	    mPopupMenu.add(menuItem);
	}

	public JComponent embedInScrollPane()
	{
	    JScrollPane scrollPane = new JScrollPane(this);
		return scrollPane;
	}

	public void setSelectedThreePath(TreePath treePath)
	{
		mSelectedTreePath = treePath;
	}

	/**
	 * Model for the list of files.
	 */
	class FileTreeModel implements TreeModel
	{
		FileModel mRoot;

		public FileTreeModel(FileModel root)
		{
			mRoot = root;
		}

		@Override
		public Object getRoot()
		{
			return mRoot;
		}

		@Override
		public boolean isLeaf(Object node)
		{
			return ((FileModel) node).isFile();
		}

		@Override
		public int getChildCount(Object parent)
		{
			return ((FileModel) parent).getChildCount();
		}

		@Override
		public Object getChild(Object parent, int index)
		{
			return ((FileModel) parent).getChild(index);
		}

		@Override
		public int getIndexOfChild(Object parent, Object child)
		{
			return ((FileModel) parent).getIndexOfChild((FileModel) child);
		}

		@Override
		public void addTreeModelListener(TreeModelListener arg0)
		{
		}

		@Override
		public void removeTreeModelListener(TreeModelListener arg0)
		{
		}

		@Override
		public void valueForPathChanged(TreePath arg0, Object arg1)
		{
		}
	}

	class FileModel
	{
		private File mFile;

		public FileModel(String path)
		{
			mFile = new File(path);
		}

		public boolean isFile()
		{
			return mFile.isFile();
		}

		public String getPath()
		{
			try
			{
				return Server.FileData.unixPath(mFile.getCanonicalPath());
			}
			catch (IOException ex)
			{
				ex.printStackTrace();
				return null;
			}
		}

		public File getFile()
		{
			return mFile;
		}

		public int getChildCount()
		{
			File[] children = mFile.listFiles();
			return null != children ? children.length : 0;
		}

		public FileModel getChild(int index)
		{
			try
			{
				File[] children = mFile.listFiles();
				if ((null == children) || (index >= children.length))
				{
					return null;
				}
				else
				{
					return new FileModel(children[index].getCanonicalPath());
				}
			}
			catch (IOException e)
			{
				e.printStackTrace();
				return null;
			}
		}

		public int getIndexOfChild(FileModel child)
		{
			int childCount = getChildCount();
			for (int i = 0; i < childCount; ++i)
			{
				if (getChild(i) == child)
				{
					return i;
				}
			}
			return -1;
		}

		@Override
		public String toString()
		{
			String name = mFile.getName();
			return (null == name || name.length() <= 0) ? "FileSystem" : name;
		}
	}

	class FileTreeMouseListener extends MouseAdapter
	{
		@Override
		public void mouseReleased(MouseEvent e)
		{
			if (e.isPopupTrigger())
			{
				int x = e.getX();
				int y = e.getY();
				TreePath treePath = mFileTree.getPathForLocation(x, y);
				if (null != treePath)
				{
					Log.i("Show menu on: " + treePath);

					setSelectedThreePath(treePath);

					if (e.isPopupTrigger())
					{
			            mPopupMenu.show(
			            	e.getComponent(),
			                e.getX(),
			                e.getY());
			        }

					// Perhaps useful for something.
					//if (mFileTree.isExpanded(treePath)) ...
				}
			}
		}
	}
}
