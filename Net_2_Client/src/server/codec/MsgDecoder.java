package server.codec;

import java.nio.ByteOrder;

import server.entity.MsgEntity;
import io.netty.buffer.ByteBuf;
import io.netty.channel.ChannelHandlerContext;
import io.netty.handler.codec.LengthFieldBasedFrameDecoder;

public class MsgDecoder extends LengthFieldBasedFrameDecoder{

	
	/**
	 * @param byteOrder
	 * @param maxFrameLength
	 *            字节最大长度,大于此长度则抛出异常
	 * @param lengthFieldOffset
	 *            开始计算长度位置,这里使用0代表放置到最开始
	 * @param lengthFieldLength
	 *            描述长度所用字节数
	 * @param lengthAdjustment
	 *            长度补偿,这里由于命令码使用2个字节.需要将原来长度计算加2
	 * @param initialBytesToStrip
	 *            开始计算长度需要跳过的字节数
	 * @param failFast
	 */
	public MsgDecoder(ByteOrder byteOrder, int maxFrameLength,
			int lengthFieldOffset, int lengthFieldLength, int lengthAdjustment,
			int initialBytesToStrip, boolean failFast) {
		super(byteOrder, maxFrameLength, lengthFieldOffset, lengthFieldLength,
				lengthAdjustment, initialBytesToStrip, failFast);
	}
	
	public MsgDecoder() {
		this(ByteOrder.BIG_ENDIAN,100000,2,4,0,0, true);
	}
	
	
	@Override
	protected Object decode(ChannelHandlerContext ctx, ByteBuf in)
			throws Exception {
		ByteBuf frame = (ByteBuf) super.decode(ctx, in);
		if (frame == null) {
			return null;
		}
		
		// 先读取两个字节命令码
		short cmd = frame.readShort();
		
		// 再读取 length
		int length = frame.readInt();
		
		// 其它数据为实际数据
		byte[] data = new byte[frame.readableBytes()];
		frame.readBytes(data);
		
		MsgEntity msgVO = new MsgEntity();
		msgVO.setCmdCode(cmd);
		msgVO.setLength(length);
		msgVO.setData(data);
		
		return msgVO;
	}

}
