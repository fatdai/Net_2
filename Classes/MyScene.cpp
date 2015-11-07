//
//  MyScene.cpp
//  Net_2
//
//  Created by dai on 15/11/7.
//
//

#include "MyScene.h"
#include "NetWorkManager.h"
#include "MsgDispatch.h"
#include "Resources.h"
#include "Msg.h"
#include "CmdCode.h"

enum{
    TAG_LOGIN_LAYER,
};

enum{
    ZORDER_LOGIN_LAYER,
};


bool MyScene::init() {
    if (!Scene::init()) {
        return false;
    }
    
    // 加载所有游戏资源
    auto cache = Director::getInstance()->getTextureCache();
    cache->addImage(IMG_player);
    cache->addImage(IMG_ball_1);
    cache->addImage(IMG_ball_2);
    cache->addImage(IMG_ball_3);
    cache->addImage(IMG_ball_4);
    cache->addImage(IMG_ball_5);
    cache->addImage(IMG_ball_6);
    cache->addImage(IMG_ball_7);
    
    scheduler = Director::getInstance()->getScheduler();
    NetWorkManager::getInstance()->init();
    MsgDispatch::getInstance()->regist(this);
    
    // 开始Login界面
    auto login = Layer::create();
    addChild(login,ZORDER_LOGIN_LAYER,TAG_LOGIN_LAYER);
    
    return true;
}


void MyScene::onReceiveMsg(Msg* msg){
    
    //----------- 处理所有的 msg ----------------------
    short cmdCode = msg->cmdCode;
    
    if (cmdCode == CMD_LOGIN_SUCCESS) {
        // 登陆成功,解析数据
        
        
    }
    
    if (msg != nullptr) {
        delete msg;
    }
}