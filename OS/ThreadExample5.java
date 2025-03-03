import java.util.concurrent.*;

class Task implements Callable<Integer> {
    private int upper;

    public Task(int upper) {
        this.upper = upper;
    }

    /* The thread will execute in this method */
    public Integer call() {
        int sum = 0;
        for (int i = 1; i <= upper; i++)
            sum += i;
        return Integer.valueOf(sum);
    }
}

public class ThreadExample5 {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide an upper limit as an argument.");
            return;
        }
        int upper = Integer.parseInt(args[0]);

        //ExecutorService: A higher-level replacement for working with threads directly. It manages a pool of threads and provides methods to submit tasks for execution.
        ExecutorService pool = Executors.newSingleThreadExecutor(); // This creates a thread pool with a single thread. The ExecutorService is responsible for managing the lifecycle of threads.
        Future<Integer> result = pool.submit(new Task(upper)); // The submit() method of the ExecutorService is used to submit a task to the thread pool. The task is an instance of the Task class that implements the Callable interface. The submit() method returns a Future object that represents the result of the asynchronous computation.

        try {
            System.out.println("sum = " + result.get());  // get() method of the Future object is used to retrieve the result of the computation. This method blocks until the computation is complete.
        } catch (InterruptedException | ExecutionException ie) { // If the computation is interrupted or throws an exception, the InterruptedException or ExecutionException is caught and printed.
            ie.printStackTrace();
        } finally {
            pool.shutdown(); // shutdown() method is called in the finally block to ensure that the thread pool is properly shut down after the task is completed.
        }
    }
}