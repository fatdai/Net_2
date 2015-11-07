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
    roadblock = tmxMap->getLayer("roadblock");
    CC_SAFE_RETAIN(tmxMap);
    addChild(tmxMap);
    
    genMapData();
    
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

void TestGame::genMapData(){
  //  memset(mapdata,0,sizeof(char) * TMX_W * TMX_H);
    
    for (int i = 0; i < TMX_H; ++i) {
        for (int j = 0; j < TMX_W; ++j) {
            if (isCollidable(j,i)) {
                mapdata[j][i] = 1;
            }else{
                mapdata[j][i] = 0;
            }
        }
    }
    
    // for test
    for (int i = 0; i < TMX_H; ++i) {
        for (int j = 0; j < TMX_W; ++j){
            printf("%d  ",mapdata[j][i]);
        }
        printf("\n");
    }
    
    pfparam.width = TMX_W;
    pfparam.height = TMX_H;
    pfparam.allow_corner = true;
    pfparam.is_canreach = [&](const pf::AStar::Vec2 &pos)->bool
    {
        return mapdata[pos.x][pos.y] == 0;
    };
}

void TestGame::startSearch(int sx,int sy,int ex,int ey){
    log("开始位置:%d,%d; 目标位置:%d,%d",sx,sy,ex,ey);
    pfparam.start = pf::AStar::Vec2(sx,sy);
    pfparam.end = pf::AStar::Vec2(ex,ey);
    auto path = aStar.search(pfparam);
    if (path.empty()) {
        log("路径未找到.....");
    }else{
        log("找到路径.....,路径为");
        
        auto oldAction = player->getActionByTag(111);
        if (oldAction) {
            player->getActionManager()->removeAction(oldAction);
        }
        
        Vector<FiniteTimeAction*> moveActions;
        for (int i = 0; i < path.size(); ++i) {
            auto& v = path[i];
            //            log("x:%d,y:%d",v.x,v.y);
            
            auto move = MoveTo::create(0.2f,getPointInMapByTileXY(v.x,v.y));
            moveActions.pushBack(move);
        }
        
        // 运动过去
        
        auto cb = CallFuncN::create([](Node* node){
            auto p = (TestPlayer*)node;
            p->gridX = node->getPositionX()/TILED_WIDTH;
            p->gridY = (TMXMAP_HEIGHT - node->getPositionY())/TILED_HEIGHT;
        });
        moveActions.pushBack(cb);
        auto seq = Sequence::create(moveActions);
        seq->setTag(111);
        player->runAction(seq);
    }
}

Point TestGame::getPointInMapByTileXY(int tiledx,int tiledy){
    float x = TILED_WIDTH * tiledx + TILED_WIDTH / 2;
    float y = TMXMAP_HEIGHT - tiledy * TILED_HEIGHT - TILED_HEIGHT/2;
    return Point(x,y);
}

bool TestGame::isCollidable(int tileX,int tileY){
    uint32_t gid = roadblock->getTileGIDAt(Vec2(tileX,tileY));
    if (gid) {
        auto value = tmxMap->getPropertiesForGID(gid);
        if (!value.isNull()) {
            auto& valueMap = value.asValueMap();
            if (valueMap["collision"].asString() == "true") {
                return true;
            }
        }
    }
    return false;
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
    listener->onTouchMoved = CC_CALLBACK_2(TestGame::touchMove,this);
    listener->onTouchEnded = CC_CALLBACK_2(TestGame::touchEnd,this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void TestGame::setMoveDir(const Point& p){
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
}

bool TestGame::touchBegan(Touch* touch,Event* event){
    
    player->gridX = player->getPositionX()/TILED_WIDTH;
    player->gridY = (TMXMAP_HEIGHT - player->getPositionY())/TILED_HEIGHT;
    
    // for test
    auto p = touch->getLocation() - tmxMap->getPosition();
    int ex = (int)(p.x/TILED_WIDTH);
    int ey = (int)((TMXMAP_HEIGHT - p.y)/TILED_HEIGHT);
    
    startSearch(player->gridX,player->gridY,ex,ey);
    
    //setMoveDir(touch->getLocation());
    return true;
}

void TestGame::touchMove(Touch* touch,Event* event){
    //setMoveDir(touch->getLocation());
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



