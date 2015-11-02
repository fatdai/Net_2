//
//  Login.cpp
//  Net_2
//
//  Created by dai on 15/10/30.
//
//

#include "Login.h"
#include "ZCButton.h"
#include "NetWorkManager.h"
#include "SocketManager.h"
#include "Msg.h"
#include "CmdCode.h"
#include "player.pb.h"
#include "GameScene.h"
#include "MsgDispatch.h"

Login::Login():
_editName(nullptr),
_editPassword(nullptr)
{
    
}

Login::~Login(){
    CC_SAFE_RELEASE(_editName);
    CC_SAFE_RELEASE(_editPassword);
}

bool Login::init(){
    
    if (!Layer::init()) {
        return false;
    }
    
    MsgDispatch::getInstance()->registMsg(this);
    NetWorkManager::getInstance()->init();
    
    // top
    Size editBoxSize(300,60);
    _editName = EditBox::create(editBoxSize,Scale9Sprite::create("images/green_edit.png"));
    CC_SAFE_RETAIN(_editName);
    _editName->setFontSize(40);
    _editName->setPosition(Vec2(240, 240));
    _editName->setFontColor(Color3B::RED);
    _editName->setPlaceHolder("Name:");
    _editName->setPlaceholderFontColor(Color3B::WHITE);
    _editName->setMaxLength(12);
    _editName->setReturnType(EditBox::KeyboardReturnType::DONE);
    _editName->setDelegate(this);
    addChild(_editName);
    
    
    // middle
    _editPassword = EditBox::create(editBoxSize,Scale9Sprite::create("images/orange_edit.png"));
    CC_SAFE_RETAIN(_editPassword);
    _editPassword->setPosition(Vec2(240, 160));
    _editPassword->setFontColor(Color3B::GREEN);
    _editPassword->setMaxLength(12);
    _editPassword->setPlaceHolder("Password:");
    _editPassword->setPlaceholderFontColor(Color3B::WHITE);
    _editPassword->setInputFlag(EditBox::InputFlag::PASSWORD);
    _editPassword->setInputMode(EditBox::InputMode::SINGLE_LINE);
    _editPassword->setDelegate(this);
    addChild(_editPassword);
    
    // btn
    auto loginTex = Director::getInstance()->getTextureCache()->addImage("login.png");
    auto login = ZCButton::createZCButton(loginTex);
    login->setPosition(240,80);
    addChild(login);
    login->addClickListener([=](ZCButton* btn){
        log("name:%s",_name.c_str());
        log("pwd:%s",_pwd.c_str());

        this->startLogin();
    });
    
    
    
    return true;
}

void Login::onReceiveMsg(Msg* msg){
    if (msg->cmdCode == LOGIN_SUCCESS) {
        log("----收到登录成功的消息-----");
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([](){
            auto scene = GameScene::create();
            Director::getInstance()->replaceScene(scene);
        });
    }
}

void Login::startLogin(){
    
//    if (_name.size() < 1) {
//        return;
//    }
//    
//    if (_pwd.size() < 1) {
//        return;
//    }
    
    // data
    player p;
    p.set_name("zhangsan");
    
    // 构建一个消息准备发送出去
    auto msg = new Msg;
    msg->cmdCode = CMD_LOGIN;
    msg->length = p.ByteSize();
    msg->alloc();
    p.SerializeToArray(msg->data,msg->length);
    
    SocketManager::getInstance()->sendMsg(msg);
}

void Login::editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text){
    if (editBox == _editName) {
        _name = text;
    }else if (editBox == _editPassword){
        _pwd = text;
    }
}


