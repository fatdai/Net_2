//
//  SystemHandler.h
//  Net_2
//
//  Created by dai on 15/11/5.
//
//

#ifndef __Net_2__SystemHandler__
#define __Net_2__SystemHandler__

#include <stdio.h>


#include <stdio.h>
#include "MsgHandler.h"
#include "Msg.h"

class SystemHandler : public MsgHandler{
    
public:
    
    virtual void onReceiveMsg(Msg* msg);
};

#endif /* defined(__Net_2__SystemHandler__) */
