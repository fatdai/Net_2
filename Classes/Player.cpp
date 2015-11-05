//
//  Player.cpp
//  Net_2
//
//  Created by dai on 15/11/4.
//
//

#include "Player.h"
#include "GameConfig.h"
#include "GameScene.h"
#include "GameMap.h"


enum{
    TAG_ACTION_MOVE,
};

Player::Player():
_mx(0),
_my(0),
_weight(0),
_nameLabel(nullptr),
_weightLabel(nullptr),
_speed(200),
_newSpeed(0),
_clientMove(false),
_serverMove(false)
{
    
}

Player::~Player(){
    CC_SAFE_RELEASE(_nameLabel);
    CC_SAFE_RELEASE(_weightLabel);
}

Player* Player::createPlayer(Texture2D* texture){
    auto bob = new Player;
    if (bob->initWithTexture(texture)) {
        bob->autorelease();
        return bob;
    }
    CC_SAFE_RELEASE(bob);
    return nullptr;
}


void Player::initData(const string& playerId,const string& name,float mx,float my,int weight){
    
    _playerId = playerId;
    _name = name;
    _mx = mx;
    _my = my;
    _weight = weight;
    
    // 将名字显示在角色的上面
    _nameLabel = Label::createWithSystemFont(_name,"",20);
    CC_SAFE_RETAIN(_nameLabel);
    _nameLabel->setAnchorPoint(Point(0.5f,0));
    _nameLabel->setPosition(getContentSize().width/2,getContentSize().height);
    addChild(_nameLabel);
    
    // 将weight显示在中间
    sprintf(_buf,"%d",_weight);
    _weightLabel = Label::createWithSystemFont(_buf,"",20);
    CC_SAFE_RETAIN(_weightLabel);
    _weightLabel->setPosition(getContentSize().width/2, getContentSize().height/2);
    addChild(_weightLabel);
    
    auto size = getContentSize();
    _halfWidth = size.width/2;
    _halfHeight = size.height/2;
}

void Player::update(float dt){

    if (_clientMove) {
        _mx += _vx * dt;
        _my += _vy * dt;
        _elapseTime += dt;
        if (_elapseTime >= _moveTime) {
            _clientMove = false;
        }
    }
    
    
    if (_serverMove){
        _mx += _vx * dt;
        _my += _vy * dt;
        _elapseTime += dt;
        if (_elapseTime >= _moveTime) {
            _serverMove = false;
        }
    }
    
    updatePosition();
}

void Player::startClientMove(const Point& dir,float time){
    _clientMove = true;
    _serverMove = false;
    _vx = dir.x * _speed;
    _vy = dir.y * _speed;
    _moveTime = time;
    _elapseTime = 0;
}

void Player::startServerMove(const Point& dir,float time){
    log("_newSpeed : %f",_newSpeed);
    _serverMove = true;
    _clientMove = false;
    _vx = dir.x * _newSpeed;
    _vy = dir.y * _newSpeed;
    _moveTime = time;
    _elapseTime = 0;
}

void Player::moveUp(){
    
    if (_my + _speed >= Game->sMapHeight - _halfHeight) {
        _my = Game->sMapHeight - _halfHeight;
        return;
    }
    
    _my += _speed;
}

void Player::moveDown(){
    
    if (_my - _speed <= _halfHeight) {
        _my = _halfHeight;
        return;
    }
    
    _my -= _speed;
}
void Player::moveLeft(){
    
    if (_mx - _speed <= _halfWidth) {
        _mx = _halfWidth;
        return;
    }
    
    _mx -= _speed;
}

void Player::moveRight(){
    
    if (_mx + _speed >= Game->sMapWidth - _halfWidth) {
        _mx = Game->sMapWidth - _halfWidth;
        return;
    }
    _mx += _speed;
}

void Player::updatePosition(){
    
    // 先更新地图位置,再更新角色的位置
    float x = MAX(_mx,WINDOW_WIDTH/2);
    float y = MAX(_my,WINDOW_HEIGHT/2);
    
    x = MIN(x,Game->sMapWidth-WINDOW_WIDTH/2);
    y = MIN(y,Game->sMapHeight-WINDOW_HEIGHT/2);
    
    Point actualPoint(x,y);
    Point centerOfView(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
    Point viewpoint = centerOfView - actualPoint;
    
    // 设置 tmx 地图位置
    Game->getGameMap()->getTMXMap()->setPosition(viewpoint);
    
    // 设置 player 位置
    setPosition(viewpoint + Point(_mx,_my));
}

//void Player::moveTo(float dstx,float dsty,float time){
//    
//    // 取消之前的运动
//    auto oldmove = getActionByTag(TAG_ACTION_MOVE);
//    if (oldmove) {
//        getActionManager()->removeAction(oldmove);
//    }
//    
//    auto move = MoveTo::create(time,Point(dstx,dsty));
//    move->setTag(TAG_ACTION_MOVE);
//    runAction(move);
//}

