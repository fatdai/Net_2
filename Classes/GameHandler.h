//
//  GameHandler.h
//  Net_2
//
//  Created by dai on 15/11/5.
//
//

#ifndef __Net_2__GameHandler__
#define __Net_2__GameHandler__

#include <stdio.h>

#include <stdio.h>
#include "MsgHandler.h"
#include "Msg.h"

class GameHandler : public MsgHandler{
    
public:
    
    virtual void onReceiveMsg(Msg* msg);
};


#endif /* defined(__Net_2__GameHandler__) */
