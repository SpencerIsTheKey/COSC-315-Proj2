#include "Consumer.h"
#include "global.h"
#include <cstdlib>

Consumer::Consumer(int id){
    Tid = id;
}

FakeJob Consumer::GetFromQueue(){
    FakeJob nextJob = global_buffer.pull();
    return nextJob;
}

void Consumer::run(){
    while(true){
        FakeJob currentJob = GetFromQueue();
        time_t start = time(0);
        std::cout << "Thread #" << Tid << " started job #" << currentJob.getID() << " at " << ctime(&start);
        sleep(currentJob.getLength());
        time_t end = time(0);
        std::cout << "Thread #" << Tid << " finished job #" << currentJob.getID() << " at " << ctime(&end);
    }
}
