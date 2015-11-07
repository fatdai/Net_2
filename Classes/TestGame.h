//
//  TestGame.h
//  Net_2
//
//  Created by dai on 15/11/6.
//
//

#ifndef __Net_2__TestGame__
#define __Net_2__TestGame__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class TestPlayer;
class TestGame : public Layer{
    
    TestGame();
public:
    
    ~TestGame();
    CREATE_FUNC(TestGame);
    virtual bool init() override;
    virtual void update(float dt) override;
    
private:
    
    void addkeyboardListener();
  //  void keyPressed(EventKeyboard::KeyCode keycode, Event* event);
    
    void addTouchListener();
    bool touchBegan(Touch* touch,Event* event);
    void touchEnd(Touch* touch,Event* event);
    
private:
    
    TMXTiledMap* tmxMap;
    TestPlayer* player;
};

#endif /* defined(__Net_2__TestGame__) */
