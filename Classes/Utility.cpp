//
//  Utility.cpp
//  Net_2
//
//  Created by dai on 15/11/3.
//
//

#include "Utility.h"
#include "GameConfig.h"

std::string& Trim(std::string &s)
{
    if (s.empty())
    {
        return s;
    }
    
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}


void ShowToast(const string& text,float time){
    
    auto curscene = Director::getInstance()->getRunningScene();
    
    auto label = Label::createWithSystemFont(text,"",30);
    label->setAnchorPoint(Point(0.5f,0.5f));
    label->setPosition(WINDOW_WIDTH/2,WINDOW_HEIGHT*3/4);
    curscene->addChild(label,99999);
    
    auto delay = DelayTime::create(time);
    auto cb = CallFuncN::create([](Node* node){
        node->removeFromParent();
    });
    auto seq = Sequence::create(delay,cb, NULL);
    label->runAction(seq);
    
}


Texture2D* GetTexture(const string& name){
    return Director::getInstance()->getTextureCache()->getTextureForKey(name);
}
