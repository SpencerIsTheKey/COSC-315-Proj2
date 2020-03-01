#include "Consumer.h"

int Consumer::GetJob(Buffer buffer){
    buffer.waitNotEmpty();
    int nextJob = buffer.pull();
    return nextJob;
}

void Consumer::run(Buffer buffer){
    while(true){
        try{
            int currentJob = GetJob(buffer);
            sleep(currentJob);
        }catch(...){
            pthread_exit(NULL);
        }
        
    }
}
