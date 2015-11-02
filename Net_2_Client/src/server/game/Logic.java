package server.game;

import java.util.concurrent.TimeUnit;

import com.google.protobuf.InvalidProtocolBufferException;

import proto.Player.player;
import server.entity.MsgEntity;
import server.message.CmdCode;
import server.queue.BaseQueue;

public class Logic implements Runnable{

	private BaseQueue<MsgEntity> INSTANCE;
	
	public Logic(BaseQueue<MsgEntity> INSTANCE) {
		this.INSTANCE = INSTANCE;
	}
	
	public void run() {
		
		while (true) {
			
			processMsg();
			
			try {
				TimeUnit.MILLISECONDS.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}

	private void processMsg() {
		while (INSTANCE.getQueueSize() > 0) {
			MsgEntity msg = INSTANCE.take();
			if (null != msg) {
				handleMsg(msg);
			}
		}
	}

	// 先处理消息,处理消息后 如果需要回复,则进行发送消息
	private void handleMsg(MsgEntity msg) {
		if (msg.getCmdCode() == CmdCode.CMD_LOGIN) {
			// 回复一个登录成功的消息回去
			try {
				player p = player.parseFrom(msg.getData());
				String name = p.getName();
				System.out.println(name + "  成功登录游戏.");
				
				MsgEntity resMsg = new MsgEntity();
				resMsg.setCmdCode(CmdCode.LOGIN_SUCCESS);
				resMsg.setLength(0);
				resMsg.setChannel(msg.getChannel());
				msg.getChannel().writeAndFlush(resMsg);
				
			} catch (InvalidProtocolBufferException e) {
				e.printStackTrace();
			}
		}
	}
}
