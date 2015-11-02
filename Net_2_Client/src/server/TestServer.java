package server;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import server.codec.MsgDecoder;
import server.codec.MsgEncoder;
import server.game.Logic;
import server.queue.MsgQueue;
import io.netty.bootstrap.ServerBootstrap;
import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelInitializer;
import io.netty.channel.ChannelOption;
import io.netty.channel.EventLoopGroup;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.SocketChannel;
import io.netty.channel.socket.nio.NioServerSocketChannel;
import io.netty.handler.logging.LogLevel;
import io.netty.handler.logging.LoggingHandler;

public class TestServer implements Runnable {

	public void bind(int port) {
		EventLoopGroup boss = new NioEventLoopGroup();
		EventLoopGroup group = new NioEventLoopGroup();

		ServerBootstrap b = new ServerBootstrap();
		b.group(boss, group).channel(NioServerSocketChannel.class)
				.option(ChannelOption.SO_BACKLOG, 1024)
				.option(ChannelOption.SO_KEEPALIVE, true)
				.handler(new LoggingHandler(LogLevel.INFO))
				.childHandler(new ChannelInitializer<SocketChannel>() {

					protected void initChannel(SocketChannel ch)
							throws Exception {
						ch.pipeline().addLast(new MsgDecoder());
						ch.pipeline().addLast(new MsgEncoder());
						ch.pipeline().addLast(new MyHandler());
					}
				});

		// ---------
		try {
			ChannelFuture future = b.bind(port).sync();
			future.channel().closeFuture().sync();
		} catch (InterruptedException e) {
			e.printStackTrace();
		} finally {
			boss.shutdownGracefully();
			group.shutdownGracefully();
		}
	}

	public void run() {
		int port = 8888;
		this.bind(port);
	}

	public static void main(String[] args) {

		ExecutorService service = Executors.newCachedThreadPool();
		service.execute(new Logic(MsgQueue.getInstance()));
		service.execute(new TestServer());
		
	}

}
