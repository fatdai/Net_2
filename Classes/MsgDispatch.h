//
//  MsgDispatch.h
//  Net_1
//
//  Created by dai on 15/11/2.
//
//

#ifndef __Net_1__MsgDispatch__
#define __Net_1__MsgDispatch__

#include <stdio.h>
#include "cocos2d.h"
#include <vector>
using namespace cocos2d;
using namespace std;


class LoginHandler;
class GameHandler;
class SystemHandler;
class BroadcastHandler;
class Msg;
class MsgHandler;

class MsgDispatch{
    
    MsgDispatch();
    
public:
    ~MsgDispatch();
    static MsgDispatch* getInstance();
    
    void dispatchMsg(Msg* msg);
    
//    void registMsg(MsgHandler* handler);

private:
    
    static MsgDispatch* _dispatch;
    
    LoginHandler* _loginHandler;
    GameHandler* _gameHandler;
    SystemHandler* _systemHandler;
    BroadcastHandler* _broadcastHandler;
};

#endif /* defined(__Net_1__MsgDispatch__) */
