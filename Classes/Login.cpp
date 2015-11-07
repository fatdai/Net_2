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
#include "GameScene.h"
#include "MsgDispatch.h"
#include "GameConfig.h"
#include "Utility.h"
#include "Resources.h"
#include "msguser.pb.h"
#include "msgplayer.pb.h"
#include "TestGame.h"
using namespace proto;

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
    
    // 加载所有游戏资源
    auto cache = Director::getInstance()->getTextureCache();
    cache->addImage(IMG_player);
    cache->addImage(IMG_ball_1);
    cache->addImage(IMG_ball_2);
    cache->addImage(IMG_ball_3);
    cache->addImage(IMG_ball_4);
    cache->addImage(IMG_ball_5);
    cache->addImage(IMG_ball_6);
    cache->addImage(IMG_ball_7);
    
    
    if (NetEnable) {
        NetWorkManager::getInstance()->init();
    }
    
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
        
        if (NetEnable) {
            this->startLogin();
        }else{
            // 直接到GameScene
            auto scene = Scene::create();
            auto layer = TestGame::create();
            scene->addChild(layer);
            Director::getInstance()->replaceScene(scene);
        }
    });
    
    
    return true;
}

void Login::onReceiveMsg(Msg* msg){
    
    int cmdCode = msg->cmdCode;
    if (cmdCode == CMD_USER_ALREADY_EXIST) {
        delete msg;
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
            ShowToast("用户已存在!",3);
        });
        return;
    }
    
    if (cmdCode == CMD_NEW_USER_LOGIN_SUCCESS) {
        
        msgplayer p;
        if (!p.ParseFromArray(msg->data,msg->length)) {
            log("%s:%d, parse msgplayer error.",__FILE__,__LINE__);
            delete msg;
            return;
        }
        
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
            auto scene = GameScene::createGameScene(p);
            Director::getInstance()->replaceScene(scene);
            log("新用户登录成功,用户名为:%s",p.name().c_str());
        });
    }else if (cmdCode == CMD_OLD_USER_LOGIN_SUCCESS){
        
        msgplayer p;
        if (!p.ParseFromArray(msg->data,msg->length)) {
            log("%s:%d, parse msgplayer error.",__FILE__,__LINE__);
            delete msg;
            return;
        }
        
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
            log("老用户登录成功");
            auto scene = GameScene::createGameScene(p);
            Director::getInstance()->replaceScene(scene);
        });
    }else{
        char buf[64];
        sprintf(buf,"未处理的名字:%d\n",cmdCode);
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([=](){
            ShowToast(buf,3);
        });
        delete msg;
    }
}

void Login::startLogin(){
    
    Trim(_name);
    Trim(_pwd);
    
    if (_name.size() < 3) {
        ShowToast("username length < 3",3);
        return;
    }
    
    if (_pwd.size() < 3) {
        ShowToast("password length < 3",3);
        return;
    }
    
    // 准备发送数据给服务端
    msguser mu;
    mu.set_username(_name);
    mu.set_password(_pwd);

    // 构建一个消息准备发送出去
    auto msg = new Msg;
    msg->cmdCode = CMD_LOGIN;
    msg->length = mu.ByteSize();
    msg->alloc();
    mu.SerializeToArray(msg->data,msg->length);
    
    SocketManager::getInstance()->sendMsg(msg);
}

void Login::editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text){
    if (editBox == _editName) {
        _name = text;
    }else if (editBox == _editPassword){
        _pwd = text;
    }
}




