#include "Buffer.h"
#include "Consumer.h"
#include "Producer.h"
#include "global.h"
#include <iostream>
using namespace std;

Buffer global_buffer;

int Consumer::Tid = 0;
int FakeJob::id = 0;

void *masterThread(void *arg){
    Producer * master = static_cast<Producer *>(arg);
    cout << &master;
    return;
}
void *slaveThread(void *arg){
    Consumer * slave = static_cast<Consumer *>(arg);
    return;
}





int main(){
    int buffer_size;
    int max_job_length;
    cout << "Enter size of buffer:  ";
    cin >> buffer_size;
    cout << "Enter max job length:  ";
    cin >> max_job_length;

    //create a buffer of size given by users
    Buffer temp(buffer_size);
    //assign global_buffer to be the created and initialized buffer
    global_buffer = temp;

    Producer master(max_job_length);
    Consumer slaves[buffer_size];

    cout << &master;

    int ret;
    ret = pthread_create(&master.thread, NULL, &masterThread, &master);
    if(ret!=0)  cout << "Creating master thread failed" << endl;


    for(int i = 0; i < buffer_size; i++){
        ret = pthread_create(&slave[i].thread, NULL, &slaveThread, &slave[i]);
        if(ret!=0)  cout << "Creating master thread failed" << endl;
    }

    return 0;
}