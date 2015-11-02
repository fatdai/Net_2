//
//  GameScene.h
//  Net_2
//
//  Created by dai on 15/11/2.
//
//

#ifndef __Net_2__GameScene__
#define __Net_2__GameScene__

#include <stdio.h>
#include "cocos2d.h"
#include "MsgHandler.h"
using namespace cocos2d;

class GameScene : public Scene,public MsgHandler{
    
public:
    
    virtual bool init() override;
    CREATE_FUNC(GameScene);
    
    virtual void onReceiveMsg(Msg* msg);
    
};

#endif /* defined(__Net_2__GameScene__) */
