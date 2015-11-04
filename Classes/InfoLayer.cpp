//
//  InfoLayer.cpp
//  Net_2
//
//  Created by dai on 15/11/2.
//
//

#include "InfoLayer.h"


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
    log("keypressed.....");
}


bool InfoLayer::touchBegan(Touch* touch,Event* event){
    auto point = touch->getLocation();
    log("touched :");
    return true;
}

void InfoLayer::touchEnd(Touch* touch,Event* event){

}