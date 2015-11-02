//
//  GameMap.h
//  Net_2
//
//  Created by dai on 15/11/2.
//
//

#ifndef __Net_2__GameMap__
#define __Net_2__GameMap__

#include <stdio.h>

#include "cocos2d.h"
using namespace cocos2d;

class GameMap : public Layer{
public:
    
    virtual bool init() override;
    CREATE_FUNC(GameMap);
    
};

#endif /* defined(__Net_2__GameMap__) */
