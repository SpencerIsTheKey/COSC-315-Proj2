#include <pthread.h>
#include <unistd.h>
#include "Buffer.h"
#ifndef PRODUCER_H
#define PRODUCER_H
class Producer{
    int numJobs;
    int maxJobLength;
    pthread_t thread;

    Producer(int number_of_jobs, int max_job_length);


    void run(Buffer buffer);
    void wait();
    int CreateJob();
};
#endif