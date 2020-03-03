#include "Consumer.h"
#include "global.h"
#include <cstdlib>

int Consumer::GetFromQueue(){
    global_buffer.waitNotEmpty();
    int nextJob = global_buffer.pull();
    return nextJob;
}

void Consumer::run(){
    while(true){
        try{
            int currentJob = GetFromQueue();
            Sleep(currentJob);
        }catch(...){
            pthread_exit(NULL);
        }
        
    }
}
