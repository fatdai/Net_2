//
//  CmdCode.h
//  Net_2
//
//  Created by dai on 15/11/2.
//
//

#ifndef Net_2_CmdCode_h
#define Net_2_CmdCode_h


// 定义一些 CmdCode
// 注意和服务端一致
// ------------------------------------------------------
// 请求的CmdCode,从200开始
// 登陆请求
const static short CMD_LOGIN = 200;



// ------------------------------------------------------
// 响应的CmdCode,从 1000 开始

// 新玩家登陆成功
const static short CMD_NEW_USER_LOGIN_SUCCESS = 1000;

// 老玩家登陆成功
const static short CMD_OLD_USER_LOGIN_SUCCESS = 1001;

// 玩家已存在
const static short CMD_USER_ALREADY_EXIST = 1002;


// ------------------------------------------------------
// 一些辅助消息  从 100 开始
const static short CMD_TEST_DELAY = 100;

#endif
