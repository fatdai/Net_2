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
#include "cocos2d.h"
using namespace cocos2d;


MsgDispatch* MsgDispatch::_dispatch = nullptr;


MsgDispatch* MsgDispatch::getInstance(){
    if (_dispatch == nullptr) {
        _dispatch = new MsgDispatch;
    }
    return _dispatch;
}

void MsgDispatch::dispatchMsg(Msg* msg){
    
    if (_handler == nullptr) {
        log("%s:%d,No Handlers.",__FILE__,__LINE__);
        return;
    }
    _handler->onReceiveMsg(msg);
}

void MsgDispatch::registMsg(MsgHandler* handler){
    _handler = handler;
}


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