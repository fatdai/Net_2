//
//  ZCButton.cpp
//  Bubble
//
//  Created by user on 14-10-16.
//
//

#include "ZCButton.h"

ZCButton::ZCButton():
_normalTex(nullptr),
_clickedTex(nullptr),
_normalFrame(nullptr),
_clickedFrame(nullptr),
_listeren(nullptr),
_btnType(EBtn_Type::ENone),
_auX(0.0f),
_auY(0.0f)
{
    
}

ZCButton::~ZCButton(){
    CC_SAFE_RELEASE(_listeren);
}

ZCButton* ZCButton::createZCButton(Texture2D* normalTex,Texture2D* clickedTex)
{
    ZCButton* btn = new ZCButton;
    btn->_normalTex = normalTex;
    btn->_clickedTex = clickedTex;
    btn->_btnType = EBtn_Type::ETexture;
    if (btn->initWithTexture(normalTex)) {
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return NULL;
}

ZCButton* ZCButton::createZCButton(const string& normal,const string& clicked)
{
    ZCButton* btn = new ZCButton;
    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
    btn->_normalFrame = cache->getSpriteFrameByName(normal);
    btn->_clickedFrame = cache->getSpriteFrameByName(clicked);
    btn->_btnType = EBtn_Type::ESpriteFrame;
    if (btn->initWithSpriteFrame(btn->_normalFrame)) {
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return NULL;
}

ZCButton* ZCButton::createZCButton(Texture2D* texture)
{
    ZCButton* btn = new ZCButton;
    btn->_btnType = EBtn_Type::ETextureSingle;
    btn->_normalTex = texture;
    if (btn->initWithTexture(texture)) {
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return NULL;
}

ZCButton* ZCButton::createZCButton(const string& normalSpriteFrameName){
    
    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
    ZCButton* btn = new ZCButton;
    btn->_normalFrame = cache->getSpriteFrameByName(normalSpriteFrameName);
    btn->_btnType = EBtn_Type::ESpriteFrameSingle;
    if (btn->initWithSpriteFrame(btn->_normalFrame)) {
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return NULL;

}

void ZCButton::addClickListener(const std::function<void(ZCButton*)> click){
    
    removeClickListener();
    
    _listeren = EventListenerTouchOneByOne::create();
    CC_SAFE_RETAIN(_listeren);
    _listeren->setSwallowTouches(true);
    
    _listeren->onTouchBegan = [=](Touch* touch, Event* event){
        Point point = touch->getLocation();
        Vec2 locationInNode = this->convertToNodeSpace(point);
        Rect rect = this->getBoundingBox();
        rect.origin.x = rect.origin.y = 0.0f;
        if (rect.containsPoint(locationInNode) && this->isVisible() ) {
            
            if (this->_btnType == EBtn_Type::ETexture){
                setTexture(_clickedTex);
            }else if (this->_btnType == EBtn_Type::ESpriteFrame){
                this->setDisplayFrame(this->_clickedFrame);
            }else if (this->_btnType == EBtn_Type::ETextureSingle ||
                      this->_btnType == EBtn_Type::ESpriteFrameSingle){
                this->setColor(Color3B::GRAY);
            }
            return true;
        }
        return false;
    };
    
    _listeren->onTouchEnded = [=](Touch* touch,Event* event)
    {
        Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
        Rect rect = this->getBoundingBox();
        rect.origin.x = rect.origin.y = 0.0f;
        
        if (rect.containsPoint(locationInNode) && this->isVisible()) {
            if (this->_btnType == EBtn_Type::ETexture){
                this->setTexture(_normalTex);
            }else if (this->_btnType == EBtn_Type::ESpriteFrame){
                this->setDisplayFrame(_normalFrame);
            }else if (this->_btnType == EBtn_Type::ETextureSingle ||
                      this->_btnType == EBtn_Type::ESpriteFrameSingle){
                this->setColor(Color3B::WHITE);
            }


            if (click) {
                click(this);
            }
            
        }else{
            
            if (this->_btnType == EBtn_Type::ETexture){
                this->setTexture(_normalTex);
            }else if (this->_btnType == EBtn_Type::ESpriteFrame){
                this->setDisplayFrame(_normalFrame);
            }else if (this->_btnType == EBtn_Type::ETextureSingle ||
                      this->_btnType == EBtn_Type::ESpriteFrameSingle){
                this->setColor(Color3B::WHITE);
            }
        }
    };
    
    _listeren->onTouchCancelled = [=](Touch* touch,Event* event)
    {
        if (this->_btnType == EBtn_Type::ETexture){
            this->setTexture(_normalTex);
        }else if (this->_btnType == EBtn_Type::ESpriteFrame){
            this->setDisplayFrame(_normalFrame);
        }else if (this->_btnType == EBtn_Type::ETextureSingle ||
                  this->_btnType == EBtn_Type::ESpriteFrameSingle){
            this->setColor(Color3B::WHITE);
        }
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listeren,this);
}

void ZCButton::removeClickListener(){
    if (_listeren) {
        _eventDispatcher->removeEventListener(_listeren);
        CC_SAFE_RELEASE_NULL(_listeren);
    }
}




