//
//  Player.h
//  Net_2
//
//  Created by dai on 15/11/4.
//
//

#ifndef __Net_2__Player__
#define __Net_2__Player__

#include <stdio.h>

#include "cocos2d.h"
#include <string>
using namespace cocos2d;
using namespace std;

class Player : public Sprite{
    
    Player();
public:
    
    ~Player();
    static Player* createPlayer(Texture2D* texture);
    
    void initData(const string& playerId,const string& name,float mx,float my,int weight);
    
    virtual void update(float dt) override;
    
public:
    
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    
    void updatePosition();
    
    float getMx(){
        return _mx;
    }
    float getMy(){
        return _my;
    }
    
    const string& getPlayerId(){
        return _playerId;
    }
    
    float getSpeed(){
        return _speed;
    }
    
    void setNewSpeed(float newSpeed){
        _newSpeed = newSpeed;
    }
    
    /**
     *  按照 dir 方向,移动 time 时间
     *
     *  @param dir  方向 (单位向量)
     *  @param time 需要时间
     */
    void startClientMove(const Point& dir,float time);
    
    void startServerMove(const Point& dir,float time);
    
    // 移动到某处
    //void moveTo(float dstx,float dsty,float time);
    
    
private:
    
    // 在地图里面的位置,左下角为原点
    float _mx,_my;
    string _playerId; // 唯一标识符
    int _weight;
    
    string _name;
    
    char _buf[32];
    
    // 移动速度
    float _speed;
    
    // 服务端返回后重新计算的速度
    float _newSpeed;
    
    Label* _nameLabel;
    Label* _weightLabel;
    
    float _halfWidth;
    float _halfHeight;
    
    // 是否是客户端进行模拟移动
    bool _clientMove;
    bool _serverMove;

    
    // 移动速度
    float _vx,_vy;
    
    // 需要移动的时间
    float _moveTime;
    
    // 已经移动的时间
    float _elapseTime;
    
};

#endif /* defined(__Net_2__Player__) */
