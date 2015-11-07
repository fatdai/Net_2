//
//  TestGame.cpp
//  Net_2
//
//  Created by dai on 15/11/6.
//
//

#include "TestGame.h"
#include "TestPlayer.h"
#include "GameConfig.h"

TestGame::TestGame(){
    tmxMap = nullptr;
    player = nullptr;
}

TestGame::~TestGame(){
    CC_SAFE_RELEASE(tmxMap);
    CC_SAFE_RELEASE(player);
}

bool TestGame::init(){
    if (!Layer::init()) {
        return false;
    }
    
    tmxMap = TMXTiledMap::create("maps/xinshoucun.tmx");
    CC_SAFE_RETAIN(tmxMap);
    addChild(tmxMap);
    
    player = TestPlayer::createPlayer("id-1",5);
    player->updatePosition();
    CC_SAFE_RETAIN(player);
    tmxMap->addChild(player);
    player->scheduleUpdate();
    
  //  addkeyboardListener();
    addTouchListener();
    
    scheduleUpdate();
    
    return true;
}

//void TestGame::addkeyboardListener(){
//    auto keyListener = EventListenerKeyboard::create();
//    keyListener->onKeyPressed = CC_CALLBACK_2(TestGame::keyPressed,this);
//    getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyListener,this);
//}

void TestGame::addTouchListener(){
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(TestGame::touchBegan,this);
    listener->onTouchEnded = CC_CALLBACK_2(TestGame::touchEnd,this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

bool TestGame::touchBegan(Touch* touch,Event* event){
    auto p = touch->getLocation();
    auto v = tmxMap->getAnchorPoint();
    auto pInScreen = player->getPosition() + tmxMap->getPosition();
    Vec2 dir;
    dir.x = p.x - pInScreen.x;
    dir.y = p.y - pInScreen.y;
    dir.normalize();
    
    float unit = M_PI/8.0f;
    float rad = atan2(dir.y,dir.x);
    float degress = CC_RADIANS_TO_DEGREES(rad);
    log("degress : %f",degress);
    if (fabs(rad) <= unit) {
        log("moveRight...");
        player->moveRight();
    }else if (fabs(rad) >= unit * 7){
        log("moveLeft...");
        player->moveLeft();
    }else if (rad > unit && rad < unit * 3){
        log("moveRightUp...");
        player->moveRightUp();
    }else if (rad >= 3 * unit && rad <= 5* unit){
        log("moveUp...");
        player->moveUp();
    }else if (rad > 5 * unit && rad < 7 * unit){
        log("moveLeftUp...");
        player->moveLeftUp();
    }else if (rad > -unit * 3 && rad < -unit){
        log("moveRightDown...");
        player->moveRightDown();
    }else if (rad >= -unit * 5 && rad <= -unit * 3){
        log("moveDown...");
        player->moveDown();
    }else if (rad >= -unit * 7 && rad <= -unit * 5){
        log("moveLeftDown...");
        player->moveLeftDown();
    }
    return true;
}

void TestGame::touchEnd(Touch* touch,Event* event){
    player->dir = NONE;
}

//void TestGame::keyPressed(EventKeyboard::KeyCode keycode, Event* event){
//    if (keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
//        // 上
//        player->moveUp();
//    }else if (keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
//        // 下
//        player->moveDown();
//    }else if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
//        // 左
//        player->moveLeft();
//    }else if (keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
//        // 右
//        player->moveRight();
//    }
//}

void TestGame::update(float dt){
    
    // 先更新地图位置,再更新角色的位置
    float x = MAX(player->getPositionX(),WINDOW_WIDTH/2);
    float y = MAX(player->getPositionY(),WINDOW_HEIGHT/2);
    
    x = MIN(x,TMXMAP_WIDTH - WINDOW_WIDTH/2);
    y = MIN(y,TMXMAP_HEIGHT - WINDOW_HEIGHT/2);
    
    Point actualPoint(x,y);
    Point centerOfView(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
    Point viewpoint = centerOfView - actualPoint;
    
    tmxMap->setPosition(viewpoint);
}



