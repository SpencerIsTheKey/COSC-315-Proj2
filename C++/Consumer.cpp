#include "Consumer.h"
#include "global.h"
#include <cstdlib>

Consumer::Consumer(int id){
    Tid = id;
}

void Consumer::run(){
    while(true){
        setThreadJob(global_buffer.pull());
        time_t start = time(0);
        std::cout << "Thread #" << getTID() << " started job #" << getThreadJob().getID() << " at " << ctime(&start);
        sleep(getThreadJob().getLength());
        time_t end = time(0);
        std::cout << "Thread #" << getTID() << " finished job #" << getThreadJob().getID() << " at " << ctime(&end);
    }
}
