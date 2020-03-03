#include <pthread.h>
#include <unistd.h>
#include <windows.h>
#include <ctime>
#include <iostream>
#include "Buffer.h"
#include "global.h"
#ifndef CONSUMER_H
#define CONSUMER_H
class Consumer{
    pthread_t thread;
    static int Tid;

public:
    Consumer(){Tid++;}

    void run();
    Job GetFromQueue();
    int getID(){return Tid;}
};
#endif