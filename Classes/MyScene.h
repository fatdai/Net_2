//
//  MyScene.h
//  Net_2
//
//  Created by dai on 15/11/7.
//
//

#ifndef __Net_2__MyScene__
#define __Net_2__MyScene__

#include <stdio.h>
#include "cocos2d.h"
#include "MsgHandler.h"
using namespace  cocos2d;

// 一个 scene 管理所有的东西
// 包括登陆界面,游戏失败界面 等
//

class MyScene : public Scene,public MsgHandler{
    
public:
    
    virtual bool init() override;
    CREATE_FUNC(MyScene);
    
private:
    
    virtual void onReceiveMsg(Msg* msg);
    
    Scheduler* scheduler;
};

#endif /* defined(__Net_2__MyScene__) */
