#include "Buffer.h"
#include "Consumer.h"
#include "Producer.h"
#include "global.h"
#include <iostream>
using namespace std;

int main(){
    int buffer_size;
    int max_job_length;
    cout << "Enter size of buffer:  ";
    cin >> buffer_size;
    cout << "Enter max job length:  ";
    cin >> max_job_length;

    //create a buffer of size given by user
    Buffer temp(buffer_size);
    //assign global_buffer to be the created and initialized buffer
    global_buffer = temp;

    Producer master(max_job_length);
    Consumer slaves[buffer_size];

    master.run();
    for(int i = 0; i < buffer_size; i++)
        slaves[i].run();

    return 0;
}