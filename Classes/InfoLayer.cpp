//
//  InfoLayer.cpp
//  Net_2
//
//  Created by dai on 15/11/2.
//
//

#include "InfoLayer.h"
#include "GameScene.h"
#include "Player.h"
#include "Msg.h"
#include "SocketManager.h"
#include "msgmove.pb.h"
#include "CmdCode.h"
#include "GameMap.h"
#include "NetWorkManager.h"


void InfoLayer::onEnter(){
    
    Layer::onEnter();
    
    // 添加鼠标点击事件
    addTouchEventListener();
    addkeyboardEventListener();
    
    schedule(schedule_selector(InfoLayer::sendTouchMsg),1);
}

void InfoLayer::sendTouchMsg(float dt){
    if (_touchArray.size() > 0) {
        
        for (int i = 0;i < _touchArray.size() - 1; ++i) {
            delete _touchArray[i];
        }
        
        // 只发送最后一个touch
        auto lastMsg = _touchArray[_touchArray.size() - 1];
        SocketManager::getInstance()->sendMsg(lastMsg);
        
        _touchArray.clear();
    }
}

void InfoLayer::addTouchEventListener(){
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(InfoLayer::touchBegan,this);
    listener->onTouchEnded = CC_CALLBACK_2(InfoLayer::touchEnd,this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void InfoLayer::addkeyboardEventListener(){
    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(InfoLayer::keyPressed,this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyListener,this);
}

void InfoLayer::keyPressed(EventKeyboard::KeyCode keycode, Event* event){
    
    if (keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
        // 上
        Game->getPlayer()->moveUp();
    }else if (keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
        // 下
        Game->getPlayer()->moveDown();
    }else if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
        // 左
        Game->getPlayer()->moveLeft();
    }else if (keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
        // 右
        Game->getPlayer()->moveRight();
    }
}


bool InfoLayer::touchBegan(Touch* touch,Event* event){
    
    auto point = touch->getLocation();
    auto dstPoinInTmxMap = point - Game->getGameMap()->getTMXMap()->getPosition();
    auto player = Game->getPlayer();
    
    msgmove mm;
    mm.set_sx(player->getMx());
    mm.set_sy(player->getMy());
    mm.set_ex(dstPoinInTmxMap.x);
    mm.set_ey(dstPoinInTmxMap.y);
    mm.set_speed(player->getSpeed());
    mm.set_delay(NetWorkManager::getInstance()->getDelay());
    
    // 角色移动到指定地方
    Msg* msg = new Msg;
    msg->cmdCode = CMD_MOVE;
    msg->length = mm.ByteSize();
    msg->alloc();
    mm.SerializeToArray(msg->data,msg->length);
    
    _touchArray.push_back(msg);
    
    //-------------客户端立马运动-----
    Vec2 dir(dstPoinInTmxMap.x - player->getMx(),dstPoinInTmxMap.y - player->getMy());
    float time = dir.length()/player->getSpeed();
    dir.normalize();
    player->startClientMove(dir,time);

    return true;
}

void InfoLayer::touchEnd(Touch* touch,Event* event){

}