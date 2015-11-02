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
    
public:
    
    static NetWorkManager* getInstance();
    void init();
    
    
};

#endif /* defined(__Net_1__NetWorkManager__) */
