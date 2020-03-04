#include "Producer.h"

Producer::Producer(int max_job_length){
    maxJobLength = max_job_length;
}

FakeJob Producer::CreateJob(){
    FakeJob newJob((rand()%getMaxLength()) + 1);
    return newJob;
}

void Producer::wait(){
    int sleepPeriod = (rand()%sleepT) + 1;
    cout << "Producer going to sleep for " << sleepPeriod << " seconds" << endl;
    sleep(sleepPeriod);
}

void Producer::run(){
    while(true){
        FakeJob newJob = CreateJob();
        time_t created = time(0);
        cout << "Producer created job #" << newJob.getID() << " with length " << newJob.getLength() << " at " << ctime(&created);
        global_buffer.push(newJob);
        wait();
    }
}