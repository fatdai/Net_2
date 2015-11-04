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

void InfoLayer::onEnter(){
    
    Layer::onEnter();
    
    // 添加鼠标点击事件
    addTouchEventListener();
    addkeyboardEventListener();
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
        Game->getPlayer()->updatePosition();
    }else if (keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
        // 下
        Game->getPlayer()->moveDown();
        Game->getPlayer()->updatePosition();
    }else if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
        // 左
        Game->getPlayer()->moveLeft();
        Game->getPlayer()->updatePosition();
    }else if (keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
        // 右
        Game->getPlayer()->moveRight();
        Game->getPlayer()->updatePosition();
    }
}


bool InfoLayer::touchBegan(Touch* touch,Event* event){
    
    auto point = touch->getLocation();
    auto player = Game->getPlayer();
    
    // 角色移动到指定地方
    
    
    return true;
}

void InfoLayer::touchEnd(Touch* touch,Event* event){

}