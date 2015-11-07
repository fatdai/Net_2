//
//  Login.h
//  Net_2
//
//  Created by dai on 15/10/30.
//
//

#ifndef __Net_2__Login__
#define __Net_2__Login__

#include <stdio.h>
#include <string>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "MsgHandler.h"
using namespace cocos2d;
using namespace extension;
using namespace std;

class Login : public Layer,public EditBoxDelegate{

public:
    
    Login();
    ~Login();
    CREATE_FUNC(Login);
   
    virtual bool init() override;
    
    virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::extension::EditBox* editBox){};

private:
    
    void startLogin();
    
private:

    EditBox* _editName;
    EditBox* _editPassword;
    
    string _name;
    string _pwd;
};

#endif /* defined(__Net_2__Login__) */
