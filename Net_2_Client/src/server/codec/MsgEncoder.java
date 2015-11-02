package server.codec;

import server.entity.MsgEntity;
import io.netty.buffer.ByteBuf;
import io.netty.channel.ChannelHandlerContext;
import io.netty.handler.codec.MessageToByteEncoder;

public class MsgEncoder extends MessageToByteEncoder<MsgEntity>{

	@Override
	protected void encode(ChannelHandlerContext ctx, MsgEntity msg, ByteBuf out)
			throws Exception {
		int dataLength = msg.getData() == null ? 0 : msg.getData().length;
		out.ensureWritable(2 + 4 + dataLength);
		out.writeShort(msg.getCmdCode());
		out.writeInt(dataLength);
		if (dataLength > 0) {
			out.writeBytes(msg.getData());
		}
	}

}
