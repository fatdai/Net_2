//
//  Player.cpp
//  Net_2
//
//  Created by dai on 15/11/4.
//
//

#include "Player.h"


Player::Player():
_mx(0),
_my(0),
_weight(0),
_nameLabel(nullptr),
_weightLabel(nullptr)
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


void Player::initData(const string& name,float mx,float my,int weight){
    
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
}



