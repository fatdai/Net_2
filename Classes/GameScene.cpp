//
//  GameScene.cpp
//  Net_2
//
//  Created by dai on 15/11/2.
//
//

#include "GameScene.h"
#include "MsgDispatch.h"
#include "GameMap.h"

bool GameScene::init(){
    if (!Scene::init()) {
        return false;
    }
    
    MsgDispatch::getInstance()->registMsg(this);
    
    auto gamemap = GameMap::create();
    addChild(gamemap);
    
    return true;
}


void GameScene::onReceiveMsg(Msg* msg){
    
}