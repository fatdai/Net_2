package server;

import server.entity.MsgEntity;
import server.queue.MsgQueue;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.SimpleChannelInboundHandler;

public class MyHandler extends SimpleChannelInboundHandler<MsgEntity>{

	@Override
	protected void messageReceived(ChannelHandlerContext ctx, MsgEntity msg)
			throws Exception {
		
		if (msg == null) {
			return;
		}
		
		// 解析出msg
		msg.setChannel(ctx.channel());
		MsgQueue.getInstance().put(msg);
	}

}
