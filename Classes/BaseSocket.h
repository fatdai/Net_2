//
//  BaseSocket.h
//  Net_2
//
//  Created by dai on 15/11/1.
//
//

#ifndef __Net_2__BaseSocket__
#define __Net_2__BaseSocket__

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <string>
#include "MyAlias.h"
using namespace std;

using SOCKET = int;
class BaseSocket{
    
public:
    
    BaseSocket();
    
    ~BaseSocket();
    
    bool create();
    
    bool connect(const char* host,int port);
    
    bool isConnected(){
        return _connected;
    }
    
    void close();
    
    int send(const char* buf,int buflen);
    
    int recv(char* buf,int buflen);
    
    SOCKET getSock(){
        return _sock;
    };
    
protected:
    
    string _host;
    
    int _port;
    
    SOCKET _sock;
    
    bool _connected;
};

#endif /* defined(__Net_2__BaseSocket__) */
