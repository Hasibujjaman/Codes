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

public class ThreadExample7 {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide an upper limit as an argument.");
            return;
        }
        int upper = Integer.parseInt(args[0]);

        //ExecutorService: A higher-level replacement for working with threads directly. It manages a pool of threads and provides methods to submit tasks for execution.
        ExecutorService pool = Executors.newCachedThreadPool(); //* Creates a thread pool that creates new threads as needed, but
                                                                          //* will reuse previously constructed threads when they are available.
                                                                          //* These pools will typically improve the performance
                                                                          //*  of programs that execute many short-lived asynchronous tasks.
        for (int i = 0; i < 15; i++)
            pool.execute(new Task(i, upper));

        pool.shutdown(); 
    }
}