package mosync.lualiveeditor;

import java.util.concurrent.LinkedBlockingQueue;

@SuppressWarnings("unchecked")
public class MessageQueue extends Thread
{
	private InternalMessageQueue mQueue = new InternalMessageQueue();
	private Runnable mWorker;

	public MessageQueue()
	{
	}

	public MessageQueue(Runnable worker)
	{
		setWorker(worker);
	}

	public void setWorker(Runnable worker)
	{
		mWorker = worker;
	}

	public void postMessage(Message message)
	{
		mQueue.postMessage(message);
	}

	public Message waitForMessage()
	{
		return mQueue.nextMessage();
	}

	@Override
	public void run()
	{
		mWorker.run();
	}

	public static class Message
	{
		String mMessage;
		Object mObject;

		public Message(String message, Object object)
		{
			mMessage = message;
			mObject = object;
		}

		public String getMessage()
		{
			return mMessage;
		}

		public Object getObject()
		{
			return mObject;
		}
	}

	private static class InternalMessageQueue
	{
		private LinkedBlockingQueue mInternalQueue = new LinkedBlockingQueue();

		public void postMessage(Message message)
		{
			mInternalQueue.offer(message);
		}

		public Message nextMessage()
		{
			try
			{
				return (Message) mInternalQueue.take();
			}
			catch (InterruptedException e)
			{
				return null;
			}
		}
	}
}
