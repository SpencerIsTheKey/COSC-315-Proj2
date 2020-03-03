#include <pthread.h>
#include <unistd.h>
#include <windows.h>
#include <ctime>
#include "Buffer.h"
#include "global.h"
#include <iostream>
#include <cstdlib>
using namespace std;
#ifndef PRODUCER_H
#define PRODUCER_H
class Producer{
    int numJobs;
    int maxJobLength;
    pthread_t thread;

    public:Producer(int max_job_length);


    void run();
    void wait();
    Job CreateJob();
};
#endif