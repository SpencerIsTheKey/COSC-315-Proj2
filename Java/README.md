# COSC-335-Proj2

## Contributors

* **Spencer Ke** - 

   - C++ Sempahores Version 
  
 
* **Mishal Hasan** - 20647160

    - Java Monitors Version 
    
*As we are only two people in our group, we split the work 50/50. One person did part 1 and the other did part 2. We worked on the logic together and helped each other with debugging *

## Code Design 

### Part 1: Java Monitors Implementation 

The main method initializes the buffer and executes the threads. It asks the user the number of threads/size of the buffer and the maximum job length. The threads run methods from the buffer class and are each their own class. In the threads themselves when the request id is somenumber defined as a global variable, the program quits as the loop exits. The program was designed so that the remove and insert method from the Cbuffer class (creates and allows for buffer manipulation) is set to be synchronized. This was to make sure multiple threads can be working simultaneosly except for when the buffers are being maniuplated.All variables are also private as this is a monitor impelementation.  

  * private static class ProducerMaster implements Runnable{...) // producer thread 
     - In a while loop, set to true initially, a length of a job is set by the createJob method.  
     - The job method from the job class creates a job object to be inserted into the circular buffer array  
     - The job is inserted into the buffer using a cbuffer method that is synchronized; cb.insert()
     - The request id is incremented and the producer thread falls asleep for a random amonunt of time 
     - The loop is checked for whether it is time to exit or not, depending on what the RID is. 
     - The method prints a message, indicating what the thread is doing before the thread sleeps. 

  * private static class ConsumerSlave implements Runnable{...) //consumer thread 
    -  This class, has a constructor that tracks the number of threads running. The number of slave threads created is the number of times the users asks to create
    -  In a while loop, set to true initially, the consumer removes the job from the buffer using a method from the CBuffer class; cb.remove() 
    -  The thread then goes to sleep and prints a message indicating whethere the thread is consuming or done consuming the thread. 
    -  Similar to the producer the thread checks the request id, and terminates the program accordingly. 
    
  * public synchronized void insert(Job job){...} //buffer class method - insert new job 
    - Checks if buffer full, if full then wait till buffer is empty  
    - Increments length of buffer when job object is added at end of buffer. 
    - All threads are notified that job has been added 
    
   * public synchronized Job remove() {...) //buffer class method - remove job 
    - Checks if buffer empty, if empty then wait till buffer has something in it 
    - Decrements lenfth of buffer when job object is removed from fromt of the array 
    - All threads are notified that job has been removed 
    
  
  ### Part 2: C++ Semaphores Implementation 

 

## Online Resources 

https://www.sanfoundry.com/java-program-circular-buffer/
http://www-scf.usc.edu/~csci201/lectures/Lecture18/ProducerConsumer.pdf
