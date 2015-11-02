//
//  Msg.h
//  TestThread
//
//  Created by dai on 15/11/1.
//  Copyright (c) 2015年 dai. All rights reserved.
//

#ifndef __TestThread__Msg__
#define __TestThread__Msg__

#include <stdio.h>
#include "MyAlias.h"
#include <assert.h>
#include <iostream>
using namespace std;

class Msg{
    
public:
    
    Msg():data(nullptr),
    length(0),
    cmdCode(0)
    {
    
    }
    
    ~Msg(){
        if (data) {
            delete [] data;
            data = nullptr;
        }
    }
    
    void alloc(){
        if (length > 0) {
            data = new byte[length];
        }
    }
    
    void print(){
        cout << "cmdCode:" << cmdCode << endl;
        cout << "length:" << length << endl;
    }
    
public:
    
    short cmdCode;
    byte* data;
    
    // 表示的是 data 的长度
    int length;
};


#endif /* defined(__TestThread__Msg__) */
