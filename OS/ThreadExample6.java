import java.util.concurrent.*;

class Task implements Runnable {
    private int upper;
    private int i;

    public Task(int i, int upper) {
        this.i = i;
        this.upper = upper;
    }

    /* The thread will execute in this method */
    public void run() {
        int sum = 0;
        for (int i = 1; i <= upper; i++)
            sum += i;

        System.out.println("Task_no = "+ i +  " |sum = " + sum + " | Thread ID: " + Thread.currentThread().getId()); 
    }
}

public class ThreadExample6 {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide an upper limit as an argument.");
            return;
        }
        int upper = Integer.parseInt(args[0]);

        //ExecutorService: A higher-level replacement for working with threads directly. It manages a pool of threads and provides methods to submit tasks for execution.
        ExecutorService pool = Executors.newFixedThreadPool(10); // This creates a thread pool with a single thread. The ExecutorService is responsible for managing the lifecycle of threads.
        for (int i = 0; i < 15; i++)
            pool.execute(new Task(i, upper)); // Even though 100 tasks are submitted, only 10 threads run at a time.
                                              // The rest of the tasks wait in a queue instead of creating unnecessary new threads

        pool.shutdown(); 
    }
}