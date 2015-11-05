//
//  BroadcastHandler.h
//  Net_2
//
//  Created by dai on 15/11/5.
//
//

#ifndef __Net_2__BroadcastHandler__
#define __Net_2__BroadcastHandler__

#include <stdio.h>

#include <stdio.h>
#include "MsgHandler.h"
#include "Msg.h"

class BroadcastHandler : public MsgHandler{
    
public:
    
    virtual void onReceiveMsg(Msg* msg);
};

#endif /* defined(__Net_2__BroadcastHandler__) */
