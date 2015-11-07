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


class Msg;
class MsgHandler;

class MsgDispatch{
    
    MsgDispatch();
    
public:
    
    ~MsgDispatch();
    
    static MsgDispatch* getInstance();
    
    void dispatchMsg(Msg* msg);
    
    void regist(MsgHandler* handler);
    
private:
    
    static MsgDispatch* _dispatch;
    
    MsgHandler* _handler;
};

#endif /* defined(__Net_1__MsgDispatch__) */
