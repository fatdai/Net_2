//
//  SocketManager.cpp
//  Net_1
//
//  Created by dai on 15/11/2.
//
//

#include "SocketManager.h"
#include "BaseSocket.h"
#include <thread>
#include "MsgDispatch.h"
#include "Msg.h"

//--------------------------------------------------
short byteToShort(byte* bys){
    return (short)(bys[0] & 0xff) << 8 | (bys[1] & 0xff);
}

short byteToShort(byte* bys,int offset){
    return (short)(bys[offset] & 0xff) << 8 | (bys[offset+1] & 0xff);
}

void shortToBytes(short s,byte* dst){
    dst[0] = (byte) (s >> 8);
    dst[1] = (byte) (s);
}

int byteToInt(byte* b){
    return ((b[0] & 0xff) << 24) | ((b[1] & 0xff) << 16)
    | ((b[2] & 0xff) << 8) | (b[3] & 0xff);
}

int byteToInt(byte* b,int offset){
    return ((b[offset] & 0xff) << 24) | ((b[offset+1] & 0xff) << 16)
    | ((b[offset+2] & 0xff) << 8) | (b[offset+3] & 0xff);
}

void intToBytes(int a,byte* b){
    b[0] = (byte) (a >> 24);
    b[1] = (byte) (a >> 16);
    b[2] = (byte) (a >> 8);
    b[3] = (byte) (a);
}

void intToBytes(int a,byte* b,int offset){
    b[offset] = (byte) (a >> 24);
    b[offset+1] = (byte) (a >> 16);
    b[offset+2] = (byte) (a >> 8);
    b[offset+3] = (byte) (a);
}

//--------------------------------------------------

void receiveHandler(SocketManager* sockManager){
    sockManager->recvHandler();
}

void bufferHandler(SocketManager* sockManager){
    sockManager->bufHandler();
}

//---------------------------------------------------

SocketManager* SocketManager::_socketManager = nullptr;

SocketManager* SocketManager::getInstance(){
    if (_socketManager == nullptr) {
        _socketManager = new SocketManager;
    }
    return _socketManager;
}


SocketManager::SocketManager()
{
    _baseSock = new BaseSocket;
    _baseSock->create();
}

void SocketManager::startThread(){
    thread t1(receiveHandler,this);
    t1.detach();
    
    thread t2(bufferHandler,this);
    t2.detach();
}

// 专门接受消息
// 暂时不使用 ByteBuffer 或者 RingBuffer 类实现
void SocketManager::recvHandler(){
    
    const int bufferSize = 1024;
    byte buf[bufferSize];
  //  byte tempbuf[bufferSize];
    int ret = 0;
    int head = sizeof(short) + sizeof(int);
    
    int offset = 0;
    int readed = 0;
    
    while (true) {
        
        if (readed >= head) {
            short cmdCode = byteToShort(buf);
            int length = byteToInt(buf,sizeof(short));
            
            while (readed < head + length) {
                int r = _baseSock->recv(buf + readed,bufferSize - readed);
                readed += r;
            }
            
            // 组成一条Msg
            auto msg = new Msg;
            msg->cmdCode = cmdCode;
            msg->length = length;
            msg->alloc();
            if (msg->length > 0) {
                memcpy(msg->data,buf + head, length);
            }
            
            _recvMutex.lock();
            _recvQueue.push(msg);
            _recvMutex.unlock();
            
            readed -= (head + length);
            offset = readed;
            memmove(buf,buf + head + length, readed);
            
//            memcpy(tempbuf,buf + head + length,readed);
//            offset = readed;
//            memcpy(buf,tempbuf,readed);
        }else{
            ret = _baseSock->recv(buf + offset,bufferSize - offset);
            readed += ret;
            offset += ret;
        }
    }
}

void SocketManager::bufHandler(){
    
    while (true) {
        
        // 处理接收队列
        if (_recvQueue.size() > 0) {
            _recvMutex.lock();
            while (_recvQueue.size() > 0) {
                auto msg = _recvQueue.front();
                _recvQueue.pop();
                MsgDispatch::getInstance()->dispatchMsg(msg);
            }
            _recvMutex.unlock();
        }
        
        // 处理发送队列
        if (_sendQueue.size() > 0) {
            _sendMutex.lock();
            while (_sendQueue.size() > 0) {
                auto msg = _sendQueue.front();
                _sendQueue.pop();
                realSend(msg);
            }
            _sendMutex.unlock();
        }
        
        this_thread::sleep_for(chrono::microseconds(50));
    }
}


void SocketManager::realSend(Msg* msg){
    
    // 将 msg 发送给 服务器
    int head = sizeof(short) + sizeof(int);
    int totalLen =  head + msg->length;
    byte buf[totalLen];
    shortToBytes(msg->cmdCode,buf);
    intToBytes(msg->length,buf,sizeof(short));
    memcpy(buf+head,msg->data,msg->length);
    delete msg;
    int sended = _baseSock->send(buf,totalLen);
    if (sended != totalLen) {
        log("%s:%d,有数据没发送完全,应该发送:%d,结果只发送:%d.",__FILE__,__LINE__,totalLen,sended);
    }
}

// 加入到 _sendMsgQueue 里面
void SocketManager::sendMsg(Msg* msg){
    _sendMutex.lock();
    _sendQueue.push(msg);
    _sendMutex.unlock();
}

SocketManager::~SocketManager(){
    if (_baseSock) {
        delete _baseSock;
        _baseSock = nullptr;
    }
}

void SocketManager::connect(const char* host,int port){
    _baseSock->connect(host,port);
}

bool SocketManager::isConnected(){
    return _baseSock->isConnected();
}
