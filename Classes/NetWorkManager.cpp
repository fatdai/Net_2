//
//  NetWorkManager.cpp
//  Net_1
//
//  Created by dai on 15/11/2.
//
//

#include "NetWorkManager.h"
#include "SocketManager.h"
#include <string>
#include "Utility.h"
#include "Msg.h"
#include "CmdCode.h"

NetWorkManager* NetWorkManager::_networkManager = nullptr;

NetWorkManager::NetWorkManager():
_delay(0){
    _lastTime = Now();
}

NetWorkManager* NetWorkManager::getInstance(){
    if (_networkManager == nullptr) {
        _networkManager = new NetWorkManager;
    }
    return _networkManager;
}

void NetWorkManager::init(){
    string host = "127.0.0.1";
    int port = 8888;
    
    SocketManager::getInstance()->connect(host.c_str(),port);
    SocketManager::getInstance()->startThread();
}

void NetWorkManager::sendCurTime(){
    
    _lastTime = Now();
    
    // 构造一个这样的消息
    auto msg = new Msg;
    msg->cmdCode = CMD_TEST_DELAY;
    msg->length = 0;
    SocketManager::getInstance()->sendMsg(msg);
}

void NetWorkManager::calculateDelay(){
    _delay = (Now() - _lastTime)/2000.0f;
    log("_delay is : %f",_delay);
}


