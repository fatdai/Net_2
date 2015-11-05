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
#include <vector>
using namespace cocos2d;
using namespace std;

class Msg;
class InfoLayer : public Layer{
    
public:

    CREATE_FUNC(InfoLayer);
    virtual void onEnter() override;
    
private:
    
    void addTouchEventListener();
    
    void sendTouchMsg(float dt);
    
private:
    
    bool touchBegan(Touch* touch,Event* event);
    void touchEnd(Touch* touch,Event* event);
    
    // for test
    void addkeyboardEventListener();
    void keyPressed(EventKeyboard::KeyCode keycode, Event* event);
    
    // 输入消息队列,每秒钟检查一次
    vector<Msg*> _touchArray;
    
};

#endif /* defined(__Net_2__InfoLayer__) */
