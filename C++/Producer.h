#include <pthread.h>
#include <unistd.h>
#include <ctime>
#include "Buffer.h"
#include "global.h"
#include <iostream>
#include <cstdlib>
using namespace std;
#ifndef PRODUCER_H
#define PRODUCER_H
class Producer{
private:
    int maxJobLength;


public:
    pthread_t thread;
    Producer(int max_job_length);

    void run();
    void wait();
    FakeJob CreateJob();

    int getMaxLength(){return maxJobLength;}
};
#endif