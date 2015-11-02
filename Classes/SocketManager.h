//
//  SocketManager.h
//  Net_1
//
//  Created by dai on 15/11/2.
//
//

#ifndef __Net_1__SocketManager__
#define __Net_1__SocketManager__

#include <stdio.h>
#include <queue>
#include <mutex>
using namespace std;



class BaseSocket;
class Msg;
class SocketManager{
    
    SocketManager();
    
public:
    
    ~SocketManager();
    static SocketManager* getInstance();
    
public:
    
    //-----------------------------------
    void startThread();
    void recvHandler();
    void bufHandler();
    
    
    // 加入到 _sendMsgQueue 里面
    void sendMsg(Msg* msg);
    
    void connect(const char* host,int port);
    
    bool isConnected();
    
private:
    
    void realSend(Msg* msg);
    
private:

    static SocketManager* _socketManager;
    
    BaseSocket* _baseSock;
    
    mutex _recvMutex;
    mutex _sendMutex;
    queue<Msg*> _recvQueue;
    queue<Msg*> _sendQueue;
    
};

#endif /* defined(__Net_1__SocketManager__) */
