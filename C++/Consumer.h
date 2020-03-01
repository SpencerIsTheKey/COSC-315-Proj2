#include <pthread.h>
#include <unistd.h>
#include "Buffer.h"
#ifndef CONSUMER_H
#define CONSUMER_H
class Consumer{
    pthread_t thread;

    Consumer(){}

    void run(Buffer buffer);
    int GetJob(Buffer buffer);
};
#endif