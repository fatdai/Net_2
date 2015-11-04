//
//  NetWorkManager.h
//  Net_1
//
//  Created by dai on 15/11/2.
//
//

#ifndef __Net_1__NetWorkManager__
#define __Net_1__NetWorkManager__

#include <stdio.h>

class NetWorkManager{
    
    static NetWorkManager* _networkManager;
    
    NetWorkManager();
    
public:
    
    static NetWorkManager* getInstance();
    void init();
    
    void setDelay(float t){
        _delay = t;
    };
    
    float getDelay(){
        return _delay;
    }
    
    // 发送条对时消息
    void sendCurTime();
    
    void calculateDelay();
    
private:
    
    // 延迟,每分钟计算一次
    float _delay;
    
    long _lastTime;
};

#endif /* defined(__Net_1__NetWorkManager__) */
