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

using namespace cocos2d;


MsgDispatch* MsgDispatch::_dispatch = nullptr;


MsgDispatch::MsgDispatch():
_handler(nullptr)
{
   
}

MsgDispatch::~MsgDispatch(){

}

MsgDispatch* MsgDispatch::getInstance(){
    if (_dispatch == nullptr) {
        _dispatch = new MsgDispatch;
    }
    return _dispatch;
}

void MsgDispatch::dispatchMsg(Msg* msg){
    _handler->onReceiveMsg(msg);
}


void MsgDispatch::regist(MsgHandler* handler){
    _handler = handler;
}


