#include "Producer.h"
#include <cstdlib>

Producer::Producer(int max_job_length){
    maxJobLength = max_job_length;
}

int Producer::CreateJob(){
    return (rand()%maxJobLength) + 1;
}

void Producer::wait(){
    Sleep((rand()%10) + 1);
}

void Producer::run(){
    while(true){
        int newJob = CreateJob();
        global_buffer.push(newJob);
        wait();
    }
    //buffer.waitEmpty();
    //delete buffer;
    pthread_exit(NULL);
}