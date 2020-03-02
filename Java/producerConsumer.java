package Java;

import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.*;
import java.time.LocalDateTime; 
import java.time.format.DateTimeFormatter;  




public class producerConsumer {
    static int n,m; /* Buffer capacity,max job length */
    static CBuffer cb;

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.println("Enter size of buffer");
        n = scan.nextInt();

        cb = new CBuffer(n);

        System.out.println("Enter maximum job length");
        m = scan.nextInt();

        scan.close();
        
        /*Initializing Producer and consumer threads*/ 

        ExecutorService executor = Executors.newFixedThreadPool(n);
        executor.execute(new ProducerMaster());       
        int ctn; //consumer thread counts initialization 
        for(ctn=1;ctn<=n;ctn++){
            executor.execute(new ConsumerSlave(ctn));
        }

        
    }

    private static class ProducerMaster implements Runnable{
        public void run(){
            try {
                DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
                int rid =0; 
                while(true){
                    int t = createJob();
                    System.out.println("Producer: produced request id: " + rid + ", length " + t+ " at time " + dtf.format(LocalDateTime.now()));
                    Job job = new Job(t,rid); 
                    cb.insert(job);
                    rid++; // increment request id
                    int sleepT = (int) (Math.random() * 10); 
                    System.out.println("Producer: sleeping for "+ sleepT+ " seconds");
                    Thread.sleep(sleepT);
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
                while(true){
                    
                    Job get = cb.remove(); 
                    System.out.println("Consumer "+ i + ": assigned request ID"+ get.reqId+ ", processing request for the next "+ get.jobLength+" seconds, current time is  "+ dtf.format(LocalDateTime.now()));
                    Thread.sleep(get.jobLength);
                    System.out.println("Consumer"+ i + ": completed request ID"+get.reqId + " at time"+ dtf.format(LocalDateTime.now()));
                }
            } catch (Exception e) {
                System.out.println("Consumer Exception: " + e.getMessage());
            }
        }

    }

    public static int createJob() {
        
        Random r = new Random();
        int rm = r.nextInt(m) + 1;
        
        return rm;

    }

    

}