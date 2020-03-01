#include "Producer.h"
#include <cstlib>

Producer::Producer(int number_of_jobs, int max_job_length){
    numJobs = number_of_jobs;
    maxJobLength = max_job_length;
}

int Producer::CreateJob(){
    return (rand()%maxJobLength) + 1;
}

void Producer::wait(){
    sleep((rand()%10) + 1);
}

void Producer::run(Buffer buffer){
    for(int i = 0; i < numJobs; i++){
        int newJob = CreateJob();
        buffer.push(newJob);
        wait();
    }
    //buffer.waitEmpty();
    //delete buffer;
    pthread_exit(NULL);
}