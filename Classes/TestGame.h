//
//  TestGame.h
//  Net_2
//
//  Created by dai on 15/11/6.
//
//

#ifndef __Net_2__TestGame__
#define __Net_2__TestGame__

#include <stdio.h>
#include "cocos2d.h"
#include "GameConfig.h"
#include "a-star.h"
using namespace cocos2d;

class TestPlayer;
class TestGame : public Layer{
    
    TestGame();
public:
    
    ~TestGame();
    CREATE_FUNC(TestGame);
    virtual bool init() override;
    virtual void update(float dt) override;

private:
    bool isCollidable(int tileX,int tileY);
    void genMapData();
    
    void setMoveDir(const Point& p);
    
    void addkeyboardListener();
  //  void keyPressed(EventKeyboard::KeyCode keycode, Event* event);
    
    void addTouchListener();
    bool touchBegan(Touch* touch,Event* event);
    void touchMove(Touch* touch,Event* event);
    void touchEnd(Touch* touch,Event* event);
    
    void startSearch(int sx,int sy,int ex,int ey);
    Point getPointInMapByTileXY(int tiledx,int tiledy);
    
private:
    
    TMXTiledMap* tmxMap;
    TMXLayer* roadblock;
    TestPlayer* player;
    
    char mapdata[TMX_W][TMX_H];
    
    pf::AStar aStar;
    pf::AStar::Param pfparam;
};

#endif /* defined(__Net_2__TestGame__) */
