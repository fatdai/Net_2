//
//  InfoLayer.h
//  Net_2
//
//  Created by dai on 15/11/2.
//
//

#ifndef __Net_2__InfoLayer__
#define __Net_2__InfoLayer__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class InfoLayer : public Layer{
    
public:

    CREATE_FUNC(InfoLayer);
    virtual void onEnter() override;
    
private:
    
    void addTouchEventListener();
    
private:
    
    bool touchBegan(Touch* touch,Event* event);
    void touchEnd(Touch* touch,Event* event);
    
    // for test
    void addkeyboardEventListener();
    void keyPressed(EventKeyboard::KeyCode keycode, Event* event);
    
};

#endif /* defined(__Net_2__InfoLayer__) */
