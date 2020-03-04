#include "Consumer.h"
#include "global.h"
#include <cstdlib>

Consumer::Consumer(){
    Tid++;
}

FakeJob Consumer::GetFromQueue(){
    global_buffer.waitNotEmpty();
    FakeJob nextJob = global_buffer.pull();
    return nextJob;
}

void Consumer::run(){
    while(true){
        try{
            
            FakeJob currentJob = GetFromQueue();
            time_t start = time(0);
            std::cout << "Thread #" << getID() << " started job #" << currentJob.getID() << " at " << ctime(&start);
            sleep(currentJob.getLength());
            time_t end = time(0);
            std::cout << "Thread #" << getID() << " finished job #" << currentJob.getID() << " at " << ctime(&end);
        }catch(...){
            std::cout << "T"<< getID() << " exited";
            pthread_exit(NULL);
        }
        
    }
}
