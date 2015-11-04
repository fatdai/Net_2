//
//  Utility.h
//  Net_2
//
//  Created by dai on 15/11/3.
//
//

#ifndef __Net_2__Utility__
#define __Net_2__Utility__

#include <stdio.h>
#include <string>
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;

std::string& Trim(std::string &s);

void ShowToast(const string& text,float time);

Texture2D* GetTexture(const string& name);

// 返回的是毫秒数
long Now();

#endif /* defined(__Net_2__Utility__) */
