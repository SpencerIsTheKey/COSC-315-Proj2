#include <vector>
#include <pthread.h>
#include <semaphore.h>
#include <windows.h>
#include "Job.h"
#ifndef BUFFER_H
#define BUFFER_H

class Buffer{
private:
    int maxSize;
    int front;
    int rear;
    int bufLen;
    std::vector<Job> Q;
    sem_t lock;
    sem_t full;
    sem_t empty;
public:
    Buffer(int length);

    int getLength(){
        sem_wait(&lock);
        int tempBufLen = bufLen;
        sem_post(&lock);
        return tempBufLen;
    }
    bool isFull(){return bufLen == maxSize;}
    bool isEmpty(){return bufLen == 0;}


    void push(Job job);
    Job pull();
    void waitNotEmpty();
    void waitNotFull();
    void waitEmpty();

};
#endif
