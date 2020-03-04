#include <pthread.h>
#include <unistd.h>
#include <ctime>
#include <iostream>
#include "Buffer.h"
#include "global.h"
#include "FakeJob.h"
#ifndef CONSUMER_H
#define CONSUMER_H
class Consumer{
private:
    int Tid;
    FakeJob threadJob;

public:
    pthread_t thread;
    Consumer(){Tid = -1;}
    Consumer(int id);

    void run();

    int getTID(){return Tid;}
    void setTID(int id){Tid=id;}
    FakeJob getThreadJob(){return threadJob;}
    void setThreadJob(FakeJob job){threadJob = job;}
};
#endif
