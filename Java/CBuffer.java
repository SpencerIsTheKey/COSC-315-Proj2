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
public synchronized void insert(Job job){
    while(isFull()){
        try {
            wait();
        } catch (Exception e) {
            System.out.println("Exception in insert while waiting");
        }
    }
    //if(!isFull()){
        buflen++; 
        rear = (rear +1) % maxSize; 
        buf[rear] = job; 
        notifyAll();
   /* }else{
        System.out.println("Error : Underflow Exception");
    }*/ 
    
}

public synchronized Job remove() {

    while(isEmpty()){
        try {
            wait();
        } catch (Exception e) {
            System.out.println("Exception in remove while waiting");
        }
    }
    //if(!isEmpty()){
        buflen--; 
        front = (front +1) % maxSize; 
        notifyAll();
        return buf[front]; 
    /*}else{
        System.out.println("Error : Underflow Exception");
        return ' '; 
    } */
    
}

public void display(){

    System.out.print("\nBuffer : "); 
    for (int i =0; i<maxSize; i++){
        System.out.print(buf[i]+ " ");
    }
}

}

