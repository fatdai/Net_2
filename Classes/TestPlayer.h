//
//  TestPlayer.h
//  Net_2
//
//  Created by dai on 15/11/6.
//
//

#ifndef __Net_2__TestPlayer__
#define __Net_2__TestPlayer__

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include <vector>

using namespace cocos2d;
using namespace std;

typedef enum{
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    LEFT_UP,
    RIGHT_UP,
    LEFT_DOWN,
    RIGHT_DOWN
}Dir;

class TestPlayer : public Sprite{
    
public:
    
 
    
    TestPlayer();
    ~TestPlayer();
    static TestPlayer* createPlayer(const string& playerId,int weight,float speed = 100);
    
public:
    
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void moveRightUp();
    void moveLeftUp();
    void moveRightDown();
    void moveLeftDown();
    
    void updatePosition();
    
    
    
    virtual void update(float dt) override;
    
public:
    
    int weight;
    float speed;
    string playerId;
    vector<TestPlayer*> others;
    
    // 在地图里面的索引,左上角为参考点
    int gridX;
    int gridY;
    
    Dir dir;
    
    // 速度
    float vx,vy;
};

#endif /* defined(__Net_2__TestPlayer__) */
