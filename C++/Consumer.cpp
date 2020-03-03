#include "Consumer.h"
#include "global.h"
#include <cstdlib>

Job Consumer::GetFromQueue(){
    global_buffer.waitNotEmpty();
    Job nextJob = global_buffer.pull();
    return nextJob;
}

void Consumer::run(){
    while(true){
        try{
            Job currentJob = GetFromQueue();
            time_t start = time(0);
            std::cout << "Thread #" << getID() << " started job #" << currentJob.getID() << " at " << ctime(&start);
            Sleep(currentJob.getLength);
            time_t end = time(0);
            std::cout << "Thread #" << getID() << " finished job #" << currentJob.getID() << " at " << ctime(&end);
        }catch(...){
            pthread_exit(NULL);
        }
        
    }
}
