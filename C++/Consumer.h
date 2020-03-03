#include <pthread.h>
#include <unistd.h>
#include <windows.h>
#include "Buffer.h"
#include "global.h"
#ifndef CONSUMER_H
#define CONSUMER_H
class Consumer{
    pthread_t thread;

    public:Consumer(){}

    void run();
    int GetFromQueue();
};
#endif