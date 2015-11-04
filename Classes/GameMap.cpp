//
//  GameMap.cpp
//  Net_2
//
//  Created by dai on 15/11/2.
//
//

#include "GameMap.h"
#include "GameConfig.h"

GameMap::GameMap():
_tmxMap(nullptr)
{
    
}

GameMap::~GameMap(){
    CC_SAFE_RELEASE(_tmxMap);
}

bool GameMap::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    // 加载 tmx
    _tmxMap = TMXTiledMap::create("maps/xinshoucun.tmx");
    CC_SAFE_RETAIN(_tmxMap);
    addChild(_tmxMap);
    
    return true;
}