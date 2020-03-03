#include <pthread.h>
#include <unistd.h>
#include <windows.h>
#include "Buffer.h"
#include "global.h"
#ifndef PRODUCER_H
#define PRODUCER_H
class Producer{
    int numJobs;
    int maxJobLength;
    pthread_t thread;

    public:Producer(int max_job_length);


    void run();
    void wait();
    int CreateJob();
};
#endif