package mosync.lualiveeditor;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;

import javax.swing.JMenuItem;
import javax.swing.JPopupMenu;
import javax.swing.JTree;
import javax.swing.event.TreeModelListener;
import javax.swing.tree.TreeModel;
import javax.swing.tree.TreePath;

/**
 * Component that displays a tree of files.
 * @author Mikael Kindborg
 */
@SuppressWarnings("serial")
public class FileTreeComponent extends JTree
{
	JTree mFileTree;
	JPopupMenu mPopupMenu;

	public FileTreeComponent(String path)
	{
		// Create file tree view.
		mFileTree = this;
	    Model model = new Model(new File(path));
	    mFileTree.setModel(model);
	    mFileTree.addMouseListener(new FileTreeMouseListener());

	    // Create popup menu.
	    mPopupMenu = new JPopupMenu();
	    JMenuItem menuItem = new JMenuItem("Transfer & Load");
	    menuItem.addActionListener(new ActionListener()
	    {
			@Override
			public void actionPerformed(ActionEvent e)
			{
				Log.i("Transfer & Load");
			}
	    });
	    mPopupMenu.add(menuItem);
	    menuItem = new JMenuItem("Transfer");
	    menuItem.addActionListener(new ActionListener()
	    {
			@Override
			public void actionPerformed(ActionEvent e)
			{
				Log.i("Transfer");
			}
	    });
	    mPopupMenu.add(menuItem);
	    mPopupMenu.add(menuItem);
	    menuItem = new JMenuItem("Open");
	    menuItem.addActionListener(new ActionListener()
	    {
			@Override
			public void actionPerformed(ActionEvent e)
			{
				Log.i("Open");
			}
	    });
	    mPopupMenu.add(menuItem);
	}

	/**
	 * Model for the list of files.
	 */
	class Model implements TreeModel
	{
		File mRoot;

		public Model(File root)
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
			return ((File) node).isFile();
		}

		@Override
		public int getChildCount(Object parent)
		{
			String[] children = ((File) parent).list();
			return null != children ? children.length : 0;
		}

		@Override
		public Object getChild(Object parent, int index)
		{
			String[] children = ((File) parent).list();
			if ((null == children) || (index >= children.length))
			{
				return null;
			}
			else
			{
				return new File((File) parent, children[index]);
			}
		}

		@Override
		public int getIndexOfChild(Object parent, Object child)
		{
			String[] children = ((File )parent).list();
			if (null == children)
			{
				return -1;
			}

			String childname = ((File) child).getName();
			for (int i = 0; i < children.length; ++i)
			{
				if (childname.equals(children[i]))
				{
					return i;
				}
			}

			return -1;
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

	class FileTreeMouseListener extends MouseAdapter
	{
		@Override
		public void mouseReleased(MouseEvent e)
		{
			if (e.isPopupTrigger())
			{
				int x = e.getX();
				int y = e.getY();
				TreePath path = mFileTree.getPathForLocation(x, y);
				if (null != path)
				{
					Log.i("Show menu on: " + path);
					if (e.isPopupTrigger())
					{
			            mPopupMenu.show(
			            	e.getComponent(),
			                e.getX(),
			                e.getY());
			        }
					//if (mFileTree.isExpanded(path))
						//m_action.putValue(Action.NAME, "Collapse");
					//else
						//m_action.putValue(Action.NAME, "Expand");
					//m_popup.show(m_tree, x, y);
					//m_clickedPath = path;
				}
			}
		}
	}
}
