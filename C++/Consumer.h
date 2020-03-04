#include <pthread.h>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include "Buffer.h"
#include "global.h"
#ifndef CONSUMER_H
#define CONSUMER_H
class Consumer{
public:
    int Tid;
    pthread_t thread;
    Consumer(){Tid = -1;}
    Consumer(int id);

    void run();
    FakeJob GetFromQueue();
};
#endif