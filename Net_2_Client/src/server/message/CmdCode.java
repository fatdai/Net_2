package server.message;

public class CmdCode {

	// ------------------------------------------------------
	// 请求的CmdCode,从200开始
	// 登陆请求
	public static final short CMD_LOGIN = 200;
	
	public static final short CMD_MOVE = 201;
	

	// ------------------------------------------------------
	// 响应的CmdCode,从 1000 开始
	
	// 新玩家登陆成功
	public static final short CMD_NEW_USER_LOGIN_SUCCESS = 1000;
	
	// 老玩家登陆成功
	public static final short CMD_OLD_USER_LOGIN_SUCCESS = 1001;
	
	// 玩家已存在
	public static final short CMD_USER_ALREADY_EXIST = 1002;
	
	// 移动
	public static final short CMD_MOVE_RES = 1003;
	
	// ------------------------------------------------------
	//
	// 一些辅助消息  从 100 开始
	public static final short CMD_TEST_DELAY = 100;
}
