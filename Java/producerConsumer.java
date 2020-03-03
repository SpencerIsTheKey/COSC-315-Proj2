package Java;

import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.*;
import java.time.LocalDateTime; 
import java.time.format.DateTimeFormatter;  




public class producerConsumer {
    static int n,m; /* Buffer capacity,max job length */
    static CBuffer cb;
    static int sleepT;
    static int reqEnd; 

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.println("Enter size of buffer: ");
        n = scan.nextInt();

        cb = new CBuffer(n);

        System.out.println("Enter maximum job length: ");
        m = scan.nextInt();

        System.out.println("Enter number of requests after program terminates: ");
        reqEnd = scan.nextInt(); 

        scan.close();

        /* Initializing Producer and consumer threads */

        ExecutorService executor = Executors.newFixedThreadPool(n);
        executor.execute(new ProducerMaster());
        int ctn; // consumer thread counts initialization
        for (ctn = 1; ctn <= n; ctn++) {
            executor.execute(new ConsumerSlave(ctn));
        }

    }

    private static class ProducerMaster implements Runnable {

        public void run() {
            try {
                DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
                int rid = 1;
                boolean exit = true;
                while (exit) {
                    int t = createJob(); // creates random job lengths from between 1-M
                    System.out.println("Producer: produced request id: " + rid + ", length " + t + " at time "
                            + dtf.format(LocalDateTime.now()));
                    Job job = new Job(t, rid); // creates job object to be inserted into memory
                    cb.insert(job); // inserts job into memory buffer, method in cbuffer class
                    rid++; // increment request id
                    sleepT = (int) (Math.random() * 10);
                    System.out.println("Producer: sleeping for "+ sleepT+ " seconds");
                    Thread.sleep(sleepT);
                    if(rid == reqEnd){ // the thread will stop executing after # specified in reqEnd  by user - stop scenario 
                        exit = false; 
                    }
                }
            } catch (Exception ie) {

                System.out.println("Producer Exception: " + ie.getMessage());
            }
        }
    }

    private static class ConsumerSlave implements Runnable{
        int i; 
        public ConsumerSlave(int ct){

             i = ct; 
        }

        public void run(){
            try {
                DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
                boolean exit = true; //controls how long the thread will run 
                while(exit){
                    
                    Job get = cb.remove(); //removes job length from buffer 
                    System.out.println("Consumer "+ i + ": assigned request ID "+ get.reqId+ ", processing request for the next "+ get.jobLength+" seconds, current time is  "+ dtf.format(LocalDateTime.now()));
                    Thread.sleep(get.jobLength); // signals consumer is consuming job for that period 
                    System.out.println("Consumer "+ i + ": completed request ID "+get.reqId + " at time "+ dtf.format(LocalDateTime.now()));
                    if(get.reqId == 11){ // the thread will stop executing after 10 Ids - stop scenario 
                        exit = false; 
                    }
                }
            } catch (Exception e) {
                System.out.println("Consumer Exception: " + e.getMessage());
            }
        }

    }

    public static int createJob() {
        //Creates random job length for each job 

        Random r = new Random();
        int rm = r.nextInt(m) + 1;
        
        return rm;

    }

    

}