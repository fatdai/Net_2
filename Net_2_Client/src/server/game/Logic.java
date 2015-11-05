package server.game;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

import com.google.protobuf.InvalidProtocolBufferException;

import proto.Msgmove.msgmove;
import proto.MsgmoveRes.msgmoveRes;
import proto.Msgplayer.msgplayer;
import proto.Msguser.msguser;
import server.entity.MsgEntity;
import server.entity.Player;
import server.entity.User;
import server.message.CmdCode;
import server.queue.BaseQueue;
import server.utils.Vector2f;

public class Logic implements Runnable {

	private BaseQueue<MsgEntity> INSTANCE;

	private ArrayList<Player> players = new ArrayList<Player>();

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
		
		int cmdCode = msg.getCmdCode();
		if (cmdCode == CmdCode.CMD_LOGIN) {
			processLogin(msg);
		}else if (cmdCode == CmdCode.CMD_TEST_DELAY) {
			System.out.println("------收到一个计算 delay 请求");
			// 返回一个空消息
			MsgEntity resMsgEntity = new MsgEntity();
			resMsgEntity.setCmdCode(CmdCode.CMD_TEST_DELAY);
			msg.getChannel().writeAndFlush(resMsgEntity);
		}else if (cmdCode == CmdCode.CMD_MOVE) {
			// 计算影子的位置, 然后广播出去
			msgmove mm = toMsgMove(msg.getData());
			
			// 由于延迟,检查是否到了目标位置
			Vector2f vec = new Vector2f(mm.getEx() - mm.getSx(),mm.getEy() - mm.getSy());
			float dis = vec.len();
			float totalTime = dis/mm.getSpeed();
			if (totalTime <= mm.getDelay() * 2) {
				// 直接移动到目标位置,并且广播出去
				for (int i = 0; i < players.size(); i++) {
					// 广播出去
					msgmoveRes.Builder b = msgmoveRes.newBuilder();
					b.setDstX(mm.getEx());
					b.setDstY(mm.getEy());
					b.setTime(mm.getDelay());
					msgmoveRes mmr = b.build();
					
					MsgEntity res = new MsgEntity();
					res.setCmdCode(CmdCode.CMD_MOVE_RES);
					res.setData(mmr.toByteArray());
					players.get(i).getChannel().writeAndFlush(res);
				}
			}else {
				// 剩下的时间移动到
				float restTime = totalTime - mm.getDelay() * 2;
				
				for (int i = 0; i < players.size(); i++) {
					// 广播出去
					msgmoveRes.Builder b = msgmoveRes.newBuilder();
					b.setDstX(mm.getEx());
					b.setDstY(mm.getEy());
					b.setTime(restTime);
					msgmoveRes mmr = b.build();
					
					MsgEntity res = new MsgEntity();
					res.setCmdCode(CmdCode.CMD_MOVE_RES);
					res.setData(mmr.toByteArray());
					players.get(i).getChannel().writeAndFlush(res);
				}
			}
		}
	}

	// 处理登陆消息
	private void processLogin(MsgEntity msg) {
		// 进行检查
		msguser mu = toMsgUser(msg.getData());

		User user = readUser("data/" + mu.getUsername());
		if (null == user) {
			newUserLoginSuccess(mu, msg);
			return;
		}

		if (user.getUsername().equals(mu.getUsername())
				&& user.getPassord().equals(mu.getPassword())) {
			// 是老玩家,则加载老玩家数据,返回给客户端
			msgplayer p = readMsgPlayer("player/" + user.getUsername());
			Player newPlayer = buildFromMsgPlayer(p);
			newPlayer.setChannel(msg.getChannel());
			players.add(newPlayer);
			MsgEntity resMsgEntity = new MsgEntity();
			resMsgEntity.setCmdCode(CmdCode.CMD_OLD_USER_LOGIN_SUCCESS);
			resMsgEntity.setData(p.toByteArray());
			msg.getChannel().writeAndFlush(resMsgEntity);

			// 其实还应该广播给其他用户,暂时省略
			
			return;
		} else {
			// 检查是否已经存在这样一个用户名,如果存在则返回 用户名已存在,否则当建立新用户
			if (isUserExist(user.getUsername())) {

				MsgEntity resMsgEntity = new MsgEntity();
				resMsgEntity.setCmdCode(CmdCode.CMD_USER_ALREADY_EXIST);
				msg.getChannel().writeAndFlush(resMsgEntity);
				return;
			} else {
				// 当一个新用户创建
				newUserLoginSuccess(mu, msg);
				return;
			}
		}
	}

	// -----------------------------------------
	static msguser toMsgUser(byte[] data) {
		try {
			return msguser.parseFrom(data);
		} catch (InvalidProtocolBufferException e) {
			e.printStackTrace();
		}
		return null;
	}

	static msgplayer toMsgPlayer(byte[] data) {
		try {
			return msgplayer.parseFrom(data);
		} catch (InvalidProtocolBufferException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	static msgmove toMsgMove(byte[] data){
		try {
			return msgmove.parseFrom(data);
		} catch (InvalidProtocolBufferException e) {
			e.printStackTrace();
		}
		return null;
	}

	static User readUser(String filepath) {
		try {
			msguser u = msguser.parseFrom(new FileInputStream(filepath));
			User user = new User();
			user.setUsername(u.getUsername());
			user.setPassord(u.getPassword());
			return user;
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println("====readUser called====");
		return null;
	}

	static msgplayer readMsgPlayer(String filepath) {
		try {
			return msgplayer.parseFrom(new FileInputStream(filepath));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	// 测试将一个username password 写到文件里面去,然后读出来
	static void write(String filepath, byte[] bytes) {

		try {
			DataOutputStream dop = new DataOutputStream(
					new BufferedOutputStream(new FileOutputStream(filepath)));
			dop.write(bytes);
			dop.flush();
			dop.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	static Player newPlayer(String name) {
		Player p = new Player();
		p.setX(220);
		p.setY(110);
		p.setName(name);
		p.setWeight(5);
		return p;
	}

	static msgplayer buildMsgPlayer(Player player) {
		msgplayer.Builder b = msgplayer.newBuilder();
		b.setX(player.getX());
		b.setY(player.getY());
		b.setName(player.getName());
		b.setWeight(player.getWeight());
		return b.build();
	}

	static Player buildFromMsgPlayer(msgplayer msgp) {
		Player p = new Player();
		p.setX(msgp.getX());
		p.setY(msgp.getY());
		p.setName(msgp.getName());
		p.setWeight(msgp.getWeight());
		return p;
	}

	static boolean isUserExist(String name) {
		File file = new File("data/" + name);
		if (file.exists()) {
			return true;
		}
		return false;
	}

	void newUserLoginSuccess(msguser mu, MsgEntity msg) {

		// 是新用户,创建一个用户,并且存储起来
		User user = new User();
		user.setUsername(mu.getUsername());
		user.setPassord(mu.getPassword());
		write("data/" + mu.getUsername(), mu.toByteArray());

		// 并且创建一个 player 返回给客户端
		Player newPlayer = newPlayer(mu.getUsername());
		newPlayer.setChannel(msg.getChannel());
		players.add(newPlayer);
		
		// 还需要在本地先创建一个文件存储player相关信息
		msgplayer mp = buildMsgPlayer(newPlayer);
		write("player/"+mp.getName(), mp.toByteArray());
		
		MsgEntity resMsgEntity = new MsgEntity();
		resMsgEntity.setCmdCode(CmdCode.CMD_NEW_USER_LOGIN_SUCCESS);
		resMsgEntity.setData(mp.toByteArray());
		msg.getChannel().writeAndFlush(resMsgEntity);

		// 其实还应该广播给其他用户,暂时省略
	}
}
