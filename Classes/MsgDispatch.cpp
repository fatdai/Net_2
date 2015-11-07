//
//  MsgDispatch.cpp
//  Net_1
//
//  Created by dai on 15/11/2.
//
//

#include "MsgDispatch.h"
#include "Msg.h"
#include "MsgHandler.h"
#include "CmdCode.h"
#include "cocos2d.h"
#include "NetWorkManager.h"
#include "LoginHandler.h"
#include "GameHandler.h"
#include "SystemHandler.h"
#include "BroadcastHandler.h"
using namespace cocos2d;


MsgDispatch* MsgDispatch::_dispatch = nullptr;


MsgDispatch::MsgDispatch()
{
    _loginHandler = new LoginHandler;
    _systemHandler = new SystemHandler;
    _broadcastHandler = new BroadcastHandler;
}

MsgDispatch::~MsgDispatch(){
    if (_loginHandler) {
        delete _loginHandler;
        _loginHandler = nullptr;
    }
    
    if (_systemHandler) {
        delete _systemHandler;
        _systemHandler = nullptr;
    }
    
    if (_broadcastHandler) {
        delete _broadcastHandler;
        _broadcastHandler = nullptr;
    }
}

MsgDispatch* MsgDispatch::getInstance(){
    if (_dispatch == nullptr) {
        _dispatch = new MsgDispatch;
    }
    return _dispatch;
}

void MsgDispatch::dispatchMsg(Msg* msg){
    
    int cmdCode = msg->cmdCode;
    
    // 1-200 为整个游戏系统相关的消息
    if (cmdCode < 200) {
        _systemHandler->onReceiveMsg(msg);
    }else if(cmdCode < 400){
        _gameHandler->onReceiveMsg(msg);
    }
    
//    
//    if (cmdCode == CMD_TEST_DELAY) {
//        NetWorkManager::getInstance()->calculateDelay();
//        return;
//    }
//    
//    if (_handler == nullptr) {
//        log("%s:%d,No Handlers.",__FILE__,__LINE__);
//        return;
//    }
//    _handler->onReceiveMsg(msg);
}

//void MsgDispatch::registMsg(MsgHandler* handler){
//    _handler = handler;
//}


//void MsgDispatch::registMsg(MsgHandler* handler){
//    for (int i = 0; i < _handlers.size(); ++i) {
//        if (_handlers[i] == handler) {
//            log("%s:%d,already regist!",__FILE__,__LINE__);
//            return;
//        }
//    }
//    
//    _handlers.push_back(handler);
//}