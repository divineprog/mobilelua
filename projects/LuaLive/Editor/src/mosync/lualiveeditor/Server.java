package mosync.lualiveeditor;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

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
	private MainWindow mMainWindow;
	private boolean mRunning = false;
	private ArrayList<ClientConnection> mClientConnections;
	private ClientAcceptor mClientAcceptor;
	private MessageQueue mServerInBox;

	public Server(MainWindow mainWindow)
	{
		mMainWindow = mainWindow;
		mRunning = false;
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
		mClientAcceptor = new ClientAcceptor(mServerInBox);
	}

	public void startServer()
	{
		if (!mRunning)
		{
			mRunning = true;
			mServerInBox.start();
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
		if (!mRunning)
		{
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

			Log.i("Server got message: " + message.getMessage());

			if ("ClientConnectionCreated".equals(message.getMessage()))
			{
				// Get connection object.
				ClientConnection connection = (ClientConnection) message.getObject();

				// Inform user that a new connection is opened.
				mMainWindow.showMessage("Client connected: " + connection.getHostName());

				// Add connection.
				Log.i("Client connected: " + connection.getHostName());
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
				for (ClientConnection connection : mClientConnections)
				{
					Log.i("Sending CommandRun to client connection: " + connection);
					connection.postMessage(
						new Message("CommandRun", message.getObject()));
				}
			}
			else if ("CommandEvalLua".equals(message.getMessage()))
			{
				for (ClientConnection connection : mClientConnections)
				{
					Log.i("Sending CommandEvalLua to client connection: " + connection);
					connection.postMessage(
						new Message("CommandEvalLua", message.getObject()));
				}
			}
			else if ("CommandResetClient".equals(message.getMessage()))
			{
				for (ClientConnection connection : mClientConnections)
				{
					Log.i("Sending CommandResetClient to client connection: " + connection);
					connection.postMessage(
						new Message("CommandResetClient", message.getObject()));
				}
			}
			else if ("MessageFromClient".equals(message.getMessage()))
			{
				Log.i("MessageFromClient: " + message.getObject());
				mMainWindow.showMessage(message.getObject().toString());
			}
			else if ("CommandServerStop".equals(message.getMessage()))
			{
				for (ClientConnection connection : mClientConnections)
				{
					Log.i("Sending CommandCloseClientConnection to client connection: " + connection);
					connection.postMessage(
						new Message("CommandCloseClientConnection", message.getObject()));
				}
				stopServer();
			}
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
					Log.i("Waiting for client connection");
					Socket socket = mServerSocket.accept();
					Log.i("Client connection accepted");
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
					catch (IOException ex)
					{
						ex.printStackTrace();
					}
					finally
					{
						mRunning = false;

						// Post dummy message to out box to ensure the blocking
						// call to the queue returns and the loop is exited.
						mClientOutBox.postMessage(
							new Message("DummyMessage", this));

						// Post connection closed message to server.
						mServerInBox.postMessage(
							new Message("ClientConnectionClosed", this));
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
				Log.i("ClientConnectionMessage: " + message.getMessage());

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
					// Send files to client, then send run command.
					// iterate over updates files ...

					FileData fileData = (FileData) message.getObject();

					// Write command integer.
					writeIntToStream(out, COMMAND_STORE_BINARY_FILE);

					// Write path length and path name.
					String path = fileData.getPath();
					writeStringToStream(out, path);

					byte[] data = fileData.getData();
					writeBytesToStream(out, data);

					out.flush();
				}
				else if ("CommandEvalLua".equals(message.getMessage()))
				{
					writeIntToStream(out, COMMAND_EVAL_LUA);

					String string = message.getObject().toString();
					writeStringToStream(out, string);

					out.flush();
				}
				else if ("CommandEvalJavaScript".equals(message.getMessage()))
				{
					writeIntToStream(out, COMMAND_EVAL_JAVASCRIPT);

					String string = message.getObject().toString();
					writeStringToStream(out, string);

					out.flush();
				}
				else if ("CommandCloseClientConnection".equals(message.getMessage()))
				{
					// This will trigger an IOException and close the connection.
					mSocket.close();
					mRunning = false;
				}

			} // while
		}

		private void incomingMessageLoop() throws IOException
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

				Log.i("ClientConnection: in dataSize: " + dataSize);
				Log.i("ClientConnection: in messageSize: " + messageSize);
				Log.i("ClientConnection: in command: " + command);

				switch (command)
				{
					case COMMAND_REPLY:
						// Read reply string. The reply starts at byte 8.
						String data = new String(buffer, 8, dataSize, "ISO-8859-1");

						Log.i(
							"numRead: " + numBytesRead +
							" data: " + data);

						// Post result message to server.
						mServerInBox.postMessage(new Message("MessageFromClient", data));

						break;
				}
			} // while
		}

		/**
		 * Write string data to stream.
		 */
		private void writeStringToStream(OutputStream out, String str)
			throws IOException
		{

			byte[] bytes = str.getBytes("ISO-8859-1");
			writeBytesToStream(out, bytes);
		}

		/**
		 * Write byte data to stream. First write size of data
		 * then the data itself.
		 */
		private void writeBytesToStream(OutputStream out, byte[] data)
			throws IOException
		{
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
}


