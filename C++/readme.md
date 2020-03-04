# COSC-335-Proj2

## Contributors

* **Spencer Ke** - 44343168

   - C++ Sempahores Version 
  
 
* **Mishal Hasan** - 20647160

    - Java Monitors Version 
    
*As we are only two people in our group, we split the work 50/50. One person did part 1 and the other did part 2. We worked on the logic together and helped each other with debugging. The monitors implementation was a lot easier than the semaphores implentation as pthreads was more complicated to use. The monitors implementation did not have as much thinking on the lock complexities, and thus was able to structure the code much easier. *

## Code Design
### Part 1: C++ Semaphores Implementation

The main method initalizes the buffer and the master and slave threads, then runs their processes.
First the user is asked for the number of threads/size of the buffer and the maximum job length. The threads run their singular ```run()``` method and use the ```pull()``` and ```push()``` methods of the ```global_buffer```. Once the master and slave threads are started, the ```main()``` function goes to sleep for 30 seconds to allow the threads to run. Afterwards, the ```main()``` function exits the program, killing all associated threads.

The ```pull()``` and ```push()``` methods of the ```Buffer``` class are designed to be synchronized to allow multiple threads to be working at the same time. To accomplish this, whenever the buffer is being manipulated a binary semaphore is called, denying access to any other thread until the current manipulation is complete.

To prevent the consumer threads from accessing jobs that arent there, the ```pull()``` method waits until the buffer is not empty. This is done via a binary semaphore that starts locked and unlocks when the ```push()``` method adds an job to the buffer while there is a thread waiting for the buffer to contain a job.

To prevent the producer thread from overwriting jobs in the buffer, the ```push()``` method waits until the buffer is not full. This is done via a binary semaphore that starts unlocked and locks if the buffer is full. This semaphore is unlocked when the ```pull()``` method takes a job from the buffer while the producer thread is waiting for a place in the buffer to place a job.

