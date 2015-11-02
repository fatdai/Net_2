package server.queue;

import server.entity.MsgEntity;

public class MsgQueue extends BaseQueue<MsgEntity>{
	
	private static final MsgQueue INSTANCE = new MsgQueue();
	
	public static MsgQueue getInstance(){
		return INSTANCE;
	}
	
}
