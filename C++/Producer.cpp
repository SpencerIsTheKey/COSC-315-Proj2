#include "Producer.h"

Producer::Producer(int max_job_length){
    maxJobLength = max_job_length;
}

Job Producer::CreateJob(){
    Job newJob((rand()%maxJobLength) + 1);
    return newJob;
}

void Producer::wait(){
    Sleep((rand()%10) + 1);
}

void Producer::run(){
    while(true){
        Job newJob = CreateJob();
        time_t created = time(0);
        cout << "Producer created job #" << newJob.getID << " at " << ctime(&created);
        global_buffer.push(newJob);
        wait();
    }
    //buffer.waitEmpty();
    //delete buffer;
    pthread_exit(NULL);
}