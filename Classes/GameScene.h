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
#include "msgplayer.pb.h"
using namespace proto;


#define Game GameScene::getGameScene()

class Player;
class InfoLayer;
class GameMap;
class GameScene : public Scene,public MsgHandler{
    
    GameScene();
    static GameScene* _gameScene;
public:
    
    ~GameScene();
    
    virtual bool init() override;
    virtual void onEnter() override;
    
    static GameScene* createGameScene(const msgplayer& mp);
    
    static GameScene* getGameScene(){
        return _gameScene;
    }
    
    virtual void onReceiveMsg(Msg* msg);
    
private:
    
    void updateDelay(float t);
    
public:
    
    GameMap* getGameMap(){
        return _gameMap;
    }
    
    Player* getPlayer(){
        return _player;
    }
    
    InfoLayer* getInfoLayer(){
        return _infoLayer;
    }
    
private:
    
    Player* _player;
    GameMap* _gameMap;
    InfoLayer* _infoLayer;
    
public:
    
    // 本来可以设置成全局变量,为了方便使用
    float sMapWidth;
    float sMapHeight;
};

#endif /* defined(__Net_2__GameScene__) */
