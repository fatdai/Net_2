//
//  TestPlayer.cpp
//  Net_2
//
//  Created by dai on 15/11/6.
//
//

#include "TestPlayer.h"
#include "Resources.h"
#include "Utility.h"
#include "GameConfig.h"


TestPlayer::TestPlayer(){
    weight = 0;
    speed = 0;
    gridX = 5;
    gridY = 5;
    dir = NONE;
}

TestPlayer::~TestPlayer(){

}

TestPlayer* TestPlayer::createPlayer(const string& playerId,int weight,float speed){
    auto bob = new TestPlayer;
    bob->playerId = playerId;
    bob->weight = weight;
    bob->speed = speed;
    if (bob && bob->initWithTexture(GetTexture(IMG_player))) {
        bob->autorelease();
        return bob;
    }
    CC_SAFE_DELETE(bob);
    return nullptr;
}

void TestPlayer::updatePosition(){
    float x = TILED_WIDTH * gridX + TILED_WIDTH / 2;
    float y = TMXMAP_HEIGHT - gridY * TILED_HEIGHT - TILED_HEIGHT/2;
    setPosition(x,y);
}

void TestPlayer::update(float dt){
    if (dir != NONE) {
        float x = getPositionX() + dt * vx;
        float y = getPositionY() + dt * vy;
        
        setPosition(x,y);
        
        //还需要计算出当前的 gridx gridy
        gridX = x/TILED_WIDTH;
        gridY = (TMXMAP_HEIGHT - y)/TILED_HEIGHT;
    }
}

void TestPlayer::moveUp(){
    
    if (gridY <= 0) {
        dir = NONE;
        return;
    }
   
    vx = 0;
    vy = speed;
    dir = UP;
}
void TestPlayer::moveDown(){
    
    if (gridY >= TMX_H - 1) {
        dir = NONE;
        return;
    }
    
    vx = 0;
    vy = -speed;
    dir = DOWN;
}
void TestPlayer::moveLeft(){
    
    if (gridX <= 0) {
        dir = NONE;
        return;
    }
    
    vx = -speed;
    vy = 0;
    dir = LEFT;
}
void TestPlayer::moveRight(){
    
    if (gridX >= TMX_W - 1) {
        dir = NONE;
        return;
    }
    
    vx = speed;
    vy = 0;
    dir = RIGHT;
}

void TestPlayer::moveRightUp(){

    if (gridY <= 0) {
        if (gridX >= TMX_W - 1) {
            dir = NONE;
            return;
        }
        moveRight();
    }else{
        if (gridX >= TMX_W - 1) {
            moveUp();
        }else{
            dir = RIGHT_UP;
            vx = speed * sin(M_PI/4);
            vy = speed * cos(M_PI/4);
        }
    }
}
void TestPlayer::moveLeftUp(){
    if (gridX <= 0) {
        if (gridY >= TMX_H - 1) {
            dir = NONE;
            return;
        }
        moveUp();
    }else{
        if (gridY >= TMX_H - 1) {
            moveLeft();
        }else{
            dir = LEFT_UP;
            vx = -speed * sin(M_PI/4);
            vy = speed * cos(M_PI/4);
        }
    }
}
void TestPlayer::moveRightDown(){
    
    if (gridY >= TMX_H - 1) {
        if (gridX >= TMX_W - 1) {
            dir = NONE;
            return;
        }
        moveRight();
    }else{
        if (gridX >= TMX_W - 1) {
            moveDown();
            return;
        }else{
            dir = RIGHT_DOWN;
            vx = speed * sin(M_PI/4);
            vy = -speed * sin(M_PI/4);
        }
    }
}
void TestPlayer::moveLeftDown(){
    if (gridX >= TMX_W - 1) {
        if (gridY >= TMX_H - 1) {
            dir = NONE;
            return;
        }
        moveDown();
    }else{
        if (gridY >= TMX_H - 1) {
            moveLeft();
        }else{
            dir = LEFT_DOWN;
            vx = -speed * sin(M_PI/4);
            vy = -speed * cos(M_PI/4);
        }
    }
}

