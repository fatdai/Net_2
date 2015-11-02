//
//  MsgHandler.h
//  Net_1
//
//  Created by dai on 15/11/2.
//
//

#ifndef Net_1_MsgHandler_h
#define Net_1_MsgHandler_h

class Msg;
class MsgHandler{
    
public:

    virtual void onReceiveMsg(Msg* msg) = 0;
};

#endif
