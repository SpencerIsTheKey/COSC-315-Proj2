#include <pthread.h>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include "Buffer.h"
#include "global.h"
#ifndef CONSUMER_H
#define CONSUMER_H
class Consumer{
    static int Tid;
    

public:
    pthread_t thread;
    Consumer();

    void run();
    FakeJob GetFromQueue();
    int getID(){return Tid;}
};
#endif