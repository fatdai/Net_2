//
//  ZCButton.h
//  Bubble
//
//  Created by user on 14-10-16.
//
//

#ifndef __Bubble__ZCButton__
#define __Bubble__ZCButton__

#include <iostream>
#include "cocos2d.h"
#include <string>
using namespace cocos2d;
using namespace std;




class ZCButton : public Sprite{
    
protected:
    
    ZCButton();
    
public:
    
    virtual ~ZCButton();
    
    ///////////////////////////////////////////////////

    
    static ZCButton* createZCButton(Texture2D* normalTex,Texture2D* clickedTex);
    
    static ZCButton* createZCButton(Texture2D* texture);
    
    

    static ZCButton* createZCButton(const string& normalSpriteFrameName);
    
    static ZCButton* createZCButton(const string& normal,const string& clicked);
    
    enum class EBtn_Type{
        ENone,  //
        ETexture,  //
        ETextureSingle, //
        ESpriteFrame,   //
        ESpriteFrameSingle, // 
    };
    
public:
    
    void addClickListener(const std::function<void(ZCButton*)> click);
    void removeClickListener();
    
protected:
    

    Texture2D* _normalTex ;
    Texture2D* _clickedTex ;
    SpriteFrame* _normalFrame ;
    SpriteFrame* _clickedFrame ;
    
    EventListenerTouchOneByOne* _listeren ;
    
    EBtn_Type _btnType;
    
public:
    float _auX;
    float _auY;
};



#endif /* defined(__Bubble__ZCButton__) */
