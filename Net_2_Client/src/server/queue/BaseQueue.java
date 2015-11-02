package server.queue;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

public class BaseQueue<T> {
	
	// 消息队列
	private final BlockingQueue<T>  queue = new LinkedBlockingQueue<T>();
	
	// 如果不阻塞,立马返回
	public T take(){
		return queue.poll();
	}
	
	// 阻塞了,消息不能丢掉
	public void put(T t){
		try {
			queue.put(t);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	
	public int getQueueSize(){
		return queue.size();
	}
	
}
