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
    
    void initData(const string& name,float mx,float my,int weight);
    
private:
    
    float _mx,_my;
    int _weight;
    string _name;
    
    char _buf[32];
    
    Label* _nameLabel;
    Label* _weightLabel;
};

#endif /* defined(__Net_2__Player__) */
