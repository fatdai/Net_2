//
//  BaseSocket.cpp
//  Net_2
//
//  Created by dai on 15/11/1.
//
//

#include "BaseSocket.h"
#include "cocos2d.h"
#include <sys/ioctl.h>
using namespace cocos2d;

#define MAX_RECV_BUFFER_SIZE 65536

BaseSocket::BaseSocket(){
    _port = 0;
    _sock = -1;
    _connected = false;
}


BaseSocket::~BaseSocket(){
    this->close();
}

bool BaseSocket::create(){
    _sock = ::socket(AF_INET,SOCK_STREAM,0);
    if (_sock == -1) {
        log("%s:%d,create socket failed.",__FILE__,__LINE__);
        return false;
    }
    return true;
}

bool BaseSocket::connect(const char* host,int port){
    
  //
    _host = host;
    _port = port;
    
//    struct hostent* he = gethostbyname(_host.c_str());
//    if (he == nullptr) {
//        log("%s:%d,host addr error.",__FILE__,__LINE__);
//        this->close();
//        return false;
//    }
    
    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family = AF_INET;
    inet_aton(_host.c_str(),(struct in_addr*)&sin.sin_addr);
    sin.sin_port = htons(_port);
    
    if (::connect(_sock,(struct sockaddr*)&sin,sizeof(sin)) < 0) {
        printf("连接服务器失败,失败原因:%d\n",errno);
        this->close();
        return false;
    }
    
    int bufsize = MAX_RECV_BUFFER_SIZE;
    setsockopt(_sock,SOL_SOCKET,SO_RCVBUF,(char*)&bufsize,sizeof(bufsize));
    setsockopt(_sock,SOL_SOCKET,SO_SNDBUF,(char*)&bufsize,sizeof(bufsize));
    
    _connected = true;
    
    printf("连接服务器成功........\n");
    
    return true;
}


int BaseSocket::send(const char* buf,int buflen){
    if (_sock == -1) {
        log("%s:%d,_sock should not -1.",__FILE__,__LINE__);
        return -1;
    }
    
    int sended = 0;
    do{
        int len = (int)::send(_sock,buf + sended,buflen-sended,0);
        if (len < 0) {
            break;
        }
        sended += len;
    }while(sended < buflen);
    
    return sended;
}


int BaseSocket::recv(char* buf,int buflen){
    
    if (_sock == -1) {
        log("%s:%d,_sock should not -1.",__FILE__,__LINE__);
        return -1;
    }
    
    int len = (int)::recv(_sock,buf,buflen,0);
    return len;
}

void BaseSocket::close(){
    if (_sock != -1) {
        ::close(_sock);
        _sock = -1;
        _connected = false;
    }
}