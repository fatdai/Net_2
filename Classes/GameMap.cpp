//
//  GameMap.cpp
//  Net_2
//
//  Created by dai on 15/11/2.
//
//

#include "GameMap.h"
#include "GameConfig.h"

bool GameMap::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    // 加载 tmx
    auto tmxtiledMap = TMXTiledMap::create("maps/xinshoucun.tmx");
    addChild(tmxtiledMap);
    
    return true;
}