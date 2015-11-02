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
    
    // for test add layercolor
    auto bg = LayerColor::create(Color4B(255, 255, 0, 255),WINDOW_WIDTH,WINDOW_HEIGHT);
    addChild(bg);
    
    return true;
}