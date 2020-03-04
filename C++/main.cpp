#include "Buffer.h"
#include "Consumer.h"
#include "Producer.h"
#include "global.h"
#include <iostream>
#include <pthread.h>
using namespace std;

Buffer global_buffer;

int FakeJob::num_jobs = 0;

void *masterThread(void *arg){
    //cast *arg to Producer *
    Producer * pointer = static_cast<Producer *>(arg);
    //retrieve data from address stored in *pointer to create intance of Producer
    Producer master = *pointer;
    master.run();
    return (void *)  "Done";
}
void *slaveThread(void *arg){
    //cast *arg to Consumer *
    Consumer * pointer = static_cast<Consumer *>(arg);
    //retrieve data from address stored in *pointer to create intance of Consumer
    Consumer slave = *pointer;
    slave.run();
    return (void *) "Done";
}

int main(){
    int buffer_size;
    int max_job_length;
    int exitTime;
    cout << "Enter size of buffer:  ";
    cin >> buffer_size;
    cout << "Enter max job length:  ";
    cin >> max_job_length;
    cout << "Enter time to exit:  ";
    cin >> exitTime;

    //create a buffer of size given by users
    Buffer temp(buffer_size);
    //assign global_buffer to be the created and initialized buffer
    global_buffer = temp;

    Producer master(max_job_length);
    Consumer slaves[buffer_size];


    //create the slave threads and give them their id
    for(int i = 0; i < buffer_size;i++)
        slaves[i].setTID(i+1);

    //create the master thread
    int ret;
    ret = pthread_create(&master.thread, NULL, &masterThread, &master);
    if(ret!=0)  cout << "Creating master thread failed" << endl;

    //create the slave threads
    for(int i = 0; i < buffer_size; i++){
        ret = pthread_create(&slaves[i].thread, NULL, &slaveThread, &slaves[i]);
        if(ret!=0)  cout << "Creating slave thread failed" << endl;
    }

    sleep(exitTime);

    return 0;
}