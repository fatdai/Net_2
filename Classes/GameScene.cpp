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
#include "SocketManager.h"
#include "msgmoveRes.pb.h"
#include "msgdelay.pb.h"
using namespace proto;

GameScene* GameScene::_gameScene = nullptr;

GameScene::GameScene():
_player(nullptr),
_gameMap(nullptr),
_infoLayer(nullptr),
_gameStarted(false)
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
        bob->_player->initData(mp.playerid(),mp.name(),mp.x(),mp.y(),mp.weight());
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
    
    schedule(schedule_selector(GameScene::checkeGameStart),0.02f);
    
    return true;
}

void GameScene::checkeGameStart(float t){
    if (NetWorkManager::getInstance()->getDelay() > 0.0001) {
        unschedule(schedule_selector(GameScene::checkeGameStart));
        _gameStarted = true;
        
        // 告诉服务端,当前的延迟是多少
        msgdelay md;
        md.set_playerid(_player->getPlayerId());
        md.set_delay(NetWorkManager::getInstance()->getDelay());
        
        auto msg = new Msg;
        msg->cmdCode = CMD_DELAY;
        msg->length = md.ByteSize();
        msg->alloc();
        md.SerializeToArray(msg->data,msg->length);
        
        SocketManager::getInstance()->sendMsg(msg);
        
        ShowToast("游戏开始....",3);
    }
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
        return;
    }else if(cmdCode == CMD_BC_NEW_PLAYER_JOIN){
        
        msgplayer mp;
        if (!mp.ParseFromArray(msg->data,msg->length)) {
            log("%s:%d, Parse msgplayer Error.",__FILE__,__LINE__);
            delete msg;
            return;
        }
        delete msg;
        
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
            auto newplayer = Player::createPlayer(GetTexture(IMG_player));
            newplayer->initData(mp.playerid(),mp.name(),mp.x(),mp.y(),mp.weight());
            Game->addChild(newplayer);
            newplayer->scheduleUpdate();
            _otherPlayers.push_back(newplayer);
        });
        
        return;
    }else if(cmdCode == CMD_RES_OTHERPLAYERS){
        log("----收到CMD_RES_OTHERPLAYERS........");
    }else{
        char buf[64];
        sprintf(buf,"未处理的名字:%d\n",cmdCode);
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
            ShowToast(buf,3);
        });
        delete msg;
    }
}

