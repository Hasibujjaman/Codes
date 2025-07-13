import java.util.concurrent.*;

class Task1 implements Runnable {
    private int upper;

    public Task1(int upper) {
        this.upper = upper;
    }

    /* The thread will execute in this method */
    public void run() {
        int sum = 0;
        for (int i = 1; i <= upper; i++)
            sum += i;

        System.out.println("Task_no = 1" +  " |sum = " + sum + " | Thread ID: " + Thread.currentThread().getId()); 
    }
}

// The Callable interface is similar to Runnable, except that it can return a value.
class Task2 implements Callable<Integer> { 
    private int upper;

    public Task2(int upper) {
        this.upper = upper;
    }

    /* The thread will execute in this method */
    public Integer call() {
        int sum = 0;
        for (int i = 1; i <= upper; i++)
            sum += i;
            
        System.out.println("Task_no = 2" +  " |sum = " + sum + " | Thread ID: " + Thread.currentThread().getId()); 
    
        return Integer.valueOf(sum);
    }
}





public class ThreadExample8 {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please provide an upper limit as an argument.");
            return;
        }
        int upper = Integer.parseInt(args[0]);

        ScheduledExecutorService pool = Executors.newScheduledThreadPool(3);



        // Run after a 5-second delay
        // pool.schedule(() -> System.out.println("Delayed task executed"), 5, TimeUnit.SECONDS);
        Future<Integer> result = pool.schedule(new Task2(upper), 5, TimeUnit.SECONDS);

        // Run every 2 seconds, starting after 3 seconds
        // pool.scheduleAtFixedRate(() -> System.out.println("Periodic task"), 3, 2, TimeUnit.SECONDS);
        pool.scheduleAtFixedRate(new Task1(upper), 3, 2, TimeUnit.SECONDS);


        //Delay shutdown to allow periodic tasks to run
        try {
            Thread.sleep(10000); // Adjust the sleep time as needed
            System.out.println("(Returned data from task 2) sum = " + result.get());  // get() method of the Future object is used to retrieve the result of the computation. This method blocks until the computation is complete.

        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace();
        }
        pool.shutdown();
    }
}