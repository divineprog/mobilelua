package mosync.lualiveeditor;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.Writer;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Arrays;

import mosync.lualiveeditor.MessageQueue.Message;

public class Server
{
	// Commands in the binary client/server protocol.
	public static final int COMMAND_RESET = 1;
	public static final int COMMAND_REPLY = 2;
	public static final int COMMAND_EVAL_LUA = 3;
	public static final int COMMAND_EVAL_JAVASCRIPT = 4;
	public static final int COMMAND_STORE_BINARY_FILE = 5;

	// Instance variables.
	private UIMainWindow mMainWindow;
	private boolean mRunning = false;
	private ArrayList<ClientConnection> mClientConnections;
	private ClientAcceptor mClientAcceptor;
	private MessageQueue mServerInBox;
	private FileTracker mFileTracker;

	public Server(UIMainWindow mainWindow)
	{
		mMainWindow = mainWindow;
		mRunning = false;
	}

	public void startServer()
	{
		if (!mRunning)
		{
			mRunning = true;

			mClientConnections = new ArrayList<ClientConnection>();

			// Thread that handles messages to the server.
			// Acts as a mediator that passes on messages.
			mServerInBox = new MessageQueue(new Runnable()
			{
				@Override
				public void run()
				{
					serverMessageLoop();
				}
			});
			mServerInBox.start();

			mClientAcceptor = new ClientAcceptor(mServerInBox);
			mClientAcceptor.start();

			mMainWindow.showMessage("Server is running");
		}
	}

	public void postMessage(Message message)
	{
		mServerInBox.postMessage(message);
	}

	private void stopServer()
	{
		if (mRunning)
		{
			for (ClientConnection connection : mClientConnections)
			{
				//connection.postMessage(
				//	new Message("CommandCloseClientConnection", message.getObject()));
				connection.close();
			}
			mRunning = false;
			mClientAcceptor.close();
			mMainWindow.showMessage("Server stopped");
		}
	}

	private void serverMessageLoop()
	{
		while (mRunning)
		{
			Message message = mServerInBox.waitForMessage();

			if ("ClientConnectionCreated".equals(message.getMessage()))
			{
				// Get connection object.
				ClientConnection connection = (ClientConnection) message.getObject();

				// Inform user that a new connection is opened.
				mMainWindow.showMessage("Client connected: " + connection.getHostName());

				// Add connection.
				mClientConnections.add(connection);

				// Start connection thread.
				connection.start();
			}
			else if ("ClientConnectionClosed".equals(message.getMessage()))
			{
				ClientConnection connection = (ClientConnection) message.getObject();
				mClientConnections.remove(connection);

				// Inform user that a client connection is closed.
				mMainWindow.showMessage("Client has disconnected: " + connection.getHostName());
			}
			else if ("CommandRun".equals(message.getMessage()))
			{
				File runFile = (File) message.getObject();
				String runFilePath = FileData.unixPath(runFile);
				String rootPath = FileData.basePath(runFilePath);

				Log.i("runFilePath: " + runFilePath);
				Log.i("rootPath: " + rootPath);

				// If there is no FileTracker, or if the root path has
				// changed, we create a new FileTracker.
				if ((null == mFileTracker) ||
					(!rootPath.equals(mFileTracker.getRootPath())))
				{
					mFileTracker = new FileTracker(rootPath);
				}

				// Get updated files.
				ArrayList<String> updatedFiles = mFileTracker.getUpdatedFiles();
				mMainWindow.showMessage("Sending " + updatedFiles.size() + " updated file(s)");
				Log.i("Number of updated files: " + updatedFiles.size());

				// Send update message.
				for (ClientConnection connection : mClientConnections)
				{
					//Log.i("Sending CommandRun to client connection: " + connection);
					connection.postMessage(
						new Message(
							"CommandRun",
							new FileData(
								runFilePath,
								updatedFiles)));
				}
			}
			else if ("CommandEvalLua".equals(message.getMessage()))
			{
				for (ClientConnection connection : mClientConnections)
				{
					connection.postMessage(
						new Message("CommandEvalLua", message.getObject()));
				}
			}
			else if ("CommandEvalJavaScript".equals(message.getMessage()))
			{
				for (ClientConnection connection : mClientConnections)
				{
					connection.postMessage(
						new Message("CommandEvalJavaScript", message.getObject()));
				}
			}
			else if ("CommandResetFileTracker".equals(message.getMessage()))
			{
				mFileTracker = null;
			}
			// CommandResetClient not used for now.
			else if ("CommandResetClient".equals(message.getMessage()))
			{
				for (ClientConnection connection : mClientConnections)
				{
					connection.postMessage(
						new Message("CommandResetClient", message.getObject()));
				}
			}
			else if ("MessageFromClient".equals(message.getMessage()))
			{
				mMainWindow.showMessage(message.getObject().toString());
			}
			else if ("CommandServerStop".equals(message.getMessage()))
			{
				stopServer();
			}
			// TODO: How is this used?
			else if("ServerAddressReceived".equals(message.getMessage()))
			{
				Log.i("ServerAddressReceived: " + message.getObject());
				mMainWindow.showMessage(message.getObject().toString());
			}
		}
	}

	static class ClientAcceptor extends Thread
	{
		private MessageQueue mServerInBox;
		private ServerSocket mServerSocket;

		public ClientAcceptor(MessageQueue queue)
		{
			mServerInBox = queue;
		}

		@Override
		public void run()
		{
			try
			{
				mServerSocket = new ServerSocket(55555);

				//Enumeration adapters = NetworkInterface.getNetworkInterfaces();
				//String a = "";
			    //if(adapters.hasMoreElements()) {
				//	a = adapters.nextElement().toString();
	     		//}

				//mServer.postMessage(
				//		new Message("ServerAddressReceived", a));

				while (true)
				{
					Socket socket = mServerSocket.accept();
					ClientConnection clientConnection = new ClientConnection(
						socket,
						mServerInBox);
					mServerInBox.postMessage(
						new Message("ClientConnectionCreated", clientConnection));
				}
			}
			catch (IOException ex)
			{
				// This will happen when closing the server socket.
				ex.printStackTrace();
			}
		}

		/**
		 * Call close to terminate the thread.
		 */
		public void close()
		{
			if (null != mServerSocket)
			{
				try
				{
					mServerSocket.close();
				}
				catch (IOException ex)
				{
					ex.printStackTrace();
				}
			}
		}
	}

	static class ClientConnection
	{
		private Socket mSocket;
		private MessageQueue mServerInBox;
		private MessageQueue mClientOutBox;
		private Thread mClientInBox;
		private boolean mRunning;
		private String mHostName;
		private ClientConnection mClientConnection = this;

		public ClientConnection(Socket socket, MessageQueue queue)
		{
			mSocket = socket;
			mServerInBox = queue;
			mRunning = true;
			mHostName = socket.getInetAddress().getHostName();

			// Thread that handles outgoing messages.
			mClientOutBox = new MessageQueue(new Runnable()
			{
				@Override
				public void run()
				{
					try
					{
						// Start outgoing communication loop.
						outgoingMessageLoop();
					}
					catch (IOException ex)
					{
						ex.printStackTrace();
					}
				}
			});

			// Thread that handles incoming messages.
			mClientInBox = new Thread()
			{
				@Override
				public void run()
				{
					try
					{
						// Start incoming communication loop.
						incomingMessageLoop();
					}
					catch (Exception ex)
					{
						ex.printStackTrace();
					}
					finally
					{
						mRunning = false;

						// Post dummy message to out box to ensure the blocking
						// call to the queue returns and the loop is exited.
						mClientOutBox.postMessage(
							new Message("DummyMessage", mClientConnection));

						// Post connection closed message to server.
						mServerInBox.postMessage(
							new Message("ClientConnectionClosed", mClientConnection));
					}
				}
			};
		}

		public String getHostName()
		{
			return mHostName;
		}

		public void start()
		{
			mClientInBox.start();
			mClientOutBox.start();
		}

		public void close()
		{
			try
			{
				mSocket.close();
			}
			catch (Exception ex)
			{
				ex.printStackTrace();
			}
			mRunning = false;
		}

		public void postMessage(Message message)
		{
			mClientOutBox.postMessage(message);
		}

		private void outgoingMessageLoop() throws IOException
		{
			OutputStream out = mSocket.getOutputStream();

			while (mRunning)
			{
				// Wait for message to send in the outgoing box.
				Log.i("Waiting for outgoing message in client connection: " + getHostName());
				Message message = mClientOutBox.waitForMessage();

				if ("CommandResetClient".equals(message.getMessage()))
				{
					// Send reset request to client.

					// Write command integer.
					writeIntToStream(out, COMMAND_RESET);

					// Write the size of the data, this is 0 bytes,
					// since the message contains no data.
					writeIntToStream(out, 0);

					out.flush();
				}
				else if ("CommandRun".equals(message.getMessage()))
				{
					// Send files to client, then reload main file.
					sendUpdatedFilesAndRunFile(out, (FileData) message.getObject());
				}
				else if ("CommandEvalLua".equals(message.getMessage()))
				{
					String data = message.getObject().toString();
					sendEvalLua(out, data);
				}
				else if ("CommandEvalJavaScript".equals(message.getMessage()))
				{
					String data = message.getObject().toString();
					sendEvalJavaScript(out, data);
				}
				else if ("CommandCloseClientConnection".equals(message.getMessage()))
				{
					// This will trigger an IOException and close the connection.
					mSocket.close();
					mRunning = false;
				}

			} // while
		}

		private void sendEvalLua(OutputStream out, String data)
			throws IOException
		{
//			// Hack to make Lua return a value we can display.
//			// data must be a variable.
//			String s = data.trim();
//			boolean isExpr = 
//				s.contains(" ") || 
//				s.contains("=") || 
//				s.contains("(") || 
//				s.contains(")");
//			if (!isExpr)
//			{
//				data = "return (" + data + ")";
//			}
			writeIntToStream(out, COMMAND_EVAL_LUA);
			writeStringToStream(out, data);
			out.flush();
		}

		private void sendEvalJavaScript(OutputStream out, String data)
			throws IOException
		{
			writeIntToStream(out, COMMAND_EVAL_JAVASCRIPT);
			writeStringToStream(out, data);
			out.flush();
		}

		private void sendUpdatedFilesAndRunFile(OutputStream out, FileData fileData)
			throws IOException
		{
			String rootPath = fileData.getRootPath();

			// Write files onto device.
			for (String path : fileData.getUpdatedFiles())
			{
				String localPath = FileData.deviceLocalPath(rootPath, path);
				Log.i("Sending file localPath: " + localPath);
				sendFileData(out, path, localPath);
			}

			// Reload main file.
			String localPath = FileData.deviceLocalPath(
				rootPath,
				fileData.getRunFilePath());

			sendEvalLua(out, "LuaLive.LoadFile('" + localPath + "')");
		}

		private void sendFileData(OutputStream out, String filePath, String localPath)
			throws IOException
		{
			byte[] path = FileData.stringBytes(localPath);
			byte[] data = FileData.readFileData(new File(filePath));

			// Total size of the data we are sending (path + data).
			int totalSize =
				4 + // Size of path.
				4 + // Size of string.
				path.length +
				data.length;

			// Write command integer.
			writeIntToStream(out, COMMAND_STORE_BINARY_FILE);

			// Write total data size. This goes after the command.
			writeIntToStream(out, totalSize);

			// Write size of path.
			writeIntToStream(out, path.length);

			// Write size of data.
			writeIntToStream(out, data.length);

			// Write path.
			out.write(path);

			// Write data.
			out.write(data);

			out.flush();
		}

		private void incomingMessageLoop()
			throws IOException, StringIndexOutOfBoundsException
		{
			InputStream in = mSocket.getInputStream();

			while (mRunning)
			{
				// Wait for data to arrive on the socket.

				// TODO: Change to a dynamically allocated buffer.
				int bufSize = 100 * 1024;
				byte[] buffer = new byte[bufSize];
				int numBytesRead = 0;

				// Read data.
				numBytesRead += in.read(buffer);

				// Make sure that the header bytes are read.
				while (numBytesRead < 8)
				{
					numBytesRead += in.read(
						buffer,
						numBytesRead,
						bufSize - numBytesRead);
				}

				// Get total size of the message. The size of the data
				// is in the second integer.
				int dataSize = readIntFromByteBuffer(buffer, 4);
				int messageSize = 8 + dataSize;

				// Read remaining bytes.
				while (numBytesRead < messageSize)
				{
					numBytesRead += in.read(
						buffer,
						numBytesRead,
						bufSize - numBytesRead);
				}

				// First integer is the command.
				int command = readIntFromByteBuffer(buffer, 0);

				switch (command)
				{
					case COMMAND_REPLY:
						// Read reply string. The reply starts at byte 8.
						String data = new String(buffer, 8, dataSize, "ISO-8859-1");

						// Post result message to server.
						mServerInBox.postMessage(new Message("MessageFromClient", data));

						break;
				}
			} // while
		}

		/**
		 * Write string data to stream.
		 * Note: Writes size header.
		 * Be aware of byte alignment problems with 4-byte ints!
		 */
		private void writeStringToStream(OutputStream out, String str)
			throws IOException
		{
			byte[] data = str.getBytes("ISO-8859-1");
			writeIntToStream(out, data.length);
			out.write(data);
		}

		/**
		 * Write a 32-bit int to a stream.
		 */
		private void writeIntToStream(OutputStream out, int value)
			throws IOException
		{
			int b1 = (value) & 0xFF;
			int b2 = (value >> 8) & 0xFF;
			int b3 = (value >> 16) & 0xFF;
			int b4 = (value >> 24) & 0xFF;
			out.write(b1);
			out.write(b2);
			out.write(b3);
			out.write(b4);
		}

		/**
		 * Read a 32-bit int from a byte buffer.
		 */
		private int readIntFromByteBuffer(byte[] buffer, int index)
		{
			int i1 = buffer[index];
			int i2 = buffer[index + 1];
			int i3 = buffer[index + 2];
			int i4 = buffer[index + 3];
			return
				(i1) |
				(i2 << 8) |
				(i3 << 16) |
				(i4 << 24);
		}
	}

	/**
	 * Helper class used when running a remote file and
	 * sending file data.
	 */
	static class FileData
	{
		/**
		 * Utility method to get the base path of a file path.
		 * @param path Full path name
		 * @return The part of the path name that precedes the last slash.
		 */
		public static String basePath(String path)
		{
			int index = path.lastIndexOf("/");
			if (index < 0)
			{
				return "/";
			}
			return path.substring(0, index + 1);
		}

		/**
		 * Utility method to get the file name of a file path.
		 * @param path Full path name
		 * @return The part of the path name that follows the last slash.
		 */
		public static String fileName(String path)
		{
			int index = path.lastIndexOf("/");
			if (index < 0)
			{
				return path;
			}
			return path.substring(index + 1);
		}

		public static String unixPath(String path)
		{
			return path.replace("\\", "/");
		}

		public static String unixPath(File file)
		{
			try
			{
				return unixPath(file.getCanonicalPath());
			}
			catch (IOException ex)
			{
				ex.printStackTrace();
				return null;
			}
		}

		/**
		 * Get part of the path that is below root path.
		 * @param rootPath Full root path.
		 * @param path Full file path.
		 * @return Path local to root path.
		 */
		public static String deviceLocalPath(String rootPath, String path)
		{
			return path.substring(rootPath.length());
		}

		public static byte[] readFileData(File file)
		{
			try
			{
				byte [] data = new byte[(int)file.length()];
				DataInputStream in = new DataInputStream(new FileInputStream(file));
				in.readFully(data);
				in.close();

				return data;
			}
			catch (Exception ex)
			{
				ex.printStackTrace();
				return null;
			}
		}

		/**
		 * Get a byte array of the string data, plus one
		 * zero-terminating byte at the end.
		 * @param str
		 * @return The string byte buffer.
		 * @throws IOException
		 */
		public static byte[] stringBytes(String str)
			throws IOException
		{
			byte[] data = str.getBytes("ISO-8859-1");
			data = Arrays.copyOf(data, data.length + 1);
			return data;
		}

		public static String readFileAsString(File file)
		{
			StringBuffer contents = new StringBuffer();
			try
			{
				BufferedReader reader =
					new BufferedReader(new FileReader(file));
				String data;
				while ((data = reader.readLine()) != null)
				{
//					contents.append(data).append(
//						System.getProperty("line.separator"));
					contents.append(data).append("\n");
				}
				reader.close();
				return contents.toString();
			}
			catch (Exception ex)
			{
				ex.printStackTrace();
				return null;
			}
		}

		public static void writeFileAsString(File file, String data)
		{
			try
			{
				// Write file.
				Writer output = new BufferedWriter(new FileWriter(file));
				output.write(data);
				output.close();
			}
			catch (IOException ex)
			{
				ex.printStackTrace();
			}
		}

		private String mRunFilePath;
		private ArrayList<String> mUpdatedFiles;

		public FileData(String runFilePath, ArrayList<String> updatedFiles)
		{
			mRunFilePath = runFilePath;
			mUpdatedFiles = updatedFiles;
		}

		public String getRunFilePath()
		{
			return mRunFilePath;
		}

		public String getRootPath()
		{
			return FileData.basePath(mRunFilePath);
		}

		public ArrayList<String> getUpdatedFiles()
		{
			return mUpdatedFiles;
		}
	}
}


