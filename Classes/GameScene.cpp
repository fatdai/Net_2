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
#include "Player.h"
#include "Resources.h"
#include "Utility.h"
#include "CmdCode.h"
#include "Msg.h"
#include "InfoLayer.h"
#include "NetWorkManager.h"
#include "GameConfig.h"
#include "msgmoveRes.pb.h"

GameScene* GameScene::_gameScene = nullptr;

GameScene::GameScene():
_player(nullptr),
_gameMap(nullptr),
_infoLayer(nullptr)
{
    
}

GameScene::~GameScene(){
    CC_SAFE_RELEASE(_player);
    CC_SAFE_RELEASE(_gameMap);
    CC_SAFE_RELEASE(_infoLayer);
}

GameScene* GameScene::createGameScene(const msgplayer& mp){
    
    auto bob = new GameScene;
    
    if (bob->init()) {
        
        bob->_player = Player::createPlayer(GetTexture(IMG_player));
        bob->_player->initData(mp.name(),mp.x(),mp.y(),mp.weight());
        CC_SAFE_RETAIN(bob->_player);
        bob->addChild(bob->_player);
        
        bob->autorelease();
        
        return bob;
    }
    
    CC_SAFE_RELEASE(bob);
    return nullptr;
}


bool GameScene::init(){
    
    if (!Scene::init()) {
        return false;
    }
    
    _gameScene = this;
    
    MsgDispatch::getInstance()->registMsg(this);
    
    _gameMap = GameMap::create();
    CC_SAFE_RETAIN(_gameMap);
    addChild(_gameMap);
    
    auto size = _gameMap->getTMXMap()->getContentSize();
    sMapWidth = size.width;
    sMapHeight = size.height;
    
    _infoLayer = InfoLayer::create();
    CC_SAFE_RETAIN(_infoLayer);
    addChild(_infoLayer);
    
    // 1分钟对时一次
    NetWorkManager::getInstance()->sendCurTime();
    schedule(schedule_selector(GameScene::updateDelay),60);
    
    return true;
}

void GameScene::updateDelay(float t){
    NetWorkManager::getInstance()->sendCurTime();
}

void GameScene::onEnter(){
    Scene::onEnter();
    _player->scheduleUpdate();
}


void GameScene::onReceiveMsg(Msg* msg){
    int cmdCode = msg->cmdCode;
    if (cmdCode == CMD_MOVE_RES) {
        msgmoveRes mmr;
        if (!mmr.ParseFromArray(msg->data,msg->length)) {
            log("%s:%d, Parse msgmoveRes Error.",__FILE__,__LINE__);
            delete msg;
            return;
        }
        delete msg;
        
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
            // 让player在 规定时间内移动到目标位置
            Vec2 dir(mmr.dstx()-_player->getMx(),mmr.dsty()-_player->getMy());
            _player->setNewSpeed(dir.length()/mmr.time());
            dir.normalize();
            _player->startServerMove(dir,mmr.time());
            log("serverTime:%f",mmr.time());
        });
    }
}

