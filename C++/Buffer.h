#include <vector>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include "FakeJob.h"
#ifndef BUFFER_H
#define BUFFER_H

class Buffer{
private:
    int maxSize;
    int front;
    int rear;
    int bufLen;
    std::vector<FakeJob> Q;
    sem_t lock;
    sem_t full;
    sem_t empty;
public:
    Buffer(){}
    Buffer(int length);

    int getLength(){
        sem_wait(&lock);
        int tempBufLen = bufLen;
        sem_post(&lock);
        return tempBufLen;
    }
    bool isFull(){return bufLen == maxSize;}
    bool isEmpty(){return bufLen == 0;}


    void push(FakeJob job);
    FakeJob pull();

};
#endif
