package Java;


public class CBuffer {

private int maxSize; 
private int front =0; 
private int rear = 0; 
private int buflen =0; 
private Job[] buf; 

public CBuffer(int n){

    maxSize = n; 
    front = rear = 0; 
    rear =0; 
    buflen =0; 
    buf = new Job[maxSize];

}

public int getSize(){

    return buflen; 

}

//reset the buffer 
public void initialize(){
    
    front = rear = 0; 
    rear =0; 
    buflen =0; 
    buf = new Job[maxSize];
}
// check if buffer full
public boolean isFull(){

    return buflen ==maxSize; 

}

// check if buffer empty
public boolean isEmpty(){

    return buflen ==0; 

}

//insert a job(duration of job) 
public synchronized void insert(Job job){ //check if full, if full then wait till buffer is empty 
    while(isFull()){
        try {
            wait();
        } catch (Exception e) {
            System.out.println("Exception in insert while waiting");
        }
    }
    
        buflen++; 
        rear = (rear +1) % maxSize; 
        buf[rear] = job; 
        notifyAll();
    
}

public synchronized Job remove() {

    while(isEmpty()){ //checks to see if buffer is empty, if it is then wait till full 
        try {
            wait();
        } catch (Exception e) {
            System.out.println("Exception in remove while waiting");
        }
    }
        buflen--; 
        front = (front +1) % maxSize; 
        notifyAll();
        return buf[front]; 
   
    
}

public void display(){

    System.out.print("\nBuffer : "); 
    for (int i =0; i<maxSize; i++){
        System.out.print(buf[i]+ " ");
    }
}

}

