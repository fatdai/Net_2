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

NetWorkManager* NetWorkManager::_networkManager = nullptr;

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