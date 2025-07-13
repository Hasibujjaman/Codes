import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;

public class SumTask extends RecursiveTask<Integer> {
    private static final int THRESHOLD = 1000; // Threshold for splitting the task
    private final int[] array;
    private final int begin;
    private final int end;

    public SumTask(int[] array, int begin, int end) {
        this.array = array;
        this.begin = begin;
        this.end = end;
    }

    @Override
    protected Integer compute() {  // The compute() method is where the actual computation of the task is done.
        int length = end - begin;

        // If the task is small enough, compute it directly
        if (length <= THRESHOLD) {
            int sum = 0;
            for (int i = begin; i < end; i++) {
                sum += array[i];
            }
            return sum;
        } else {
            // Split the task into two subtasks
            int mid = begin + length / 2;
            SumTask leftTask = new SumTask(array, begin, mid);
            SumTask rightTask = new SumTask(array, mid, end);

            // Fork the subtasks
            leftTask.fork();  // The fork() method is used to asynchronously execute a task in a separate thread.
            rightTask.fork();

            // Join the results from the subtasks
            int leftResult = leftTask.join();   // The join() method is used to wait for the result of a task that was forked earlier.
            int rightResult = rightTask.join();

            // Combine the results
            return leftResult + rightResult;
        }
    }


    public static void main(String[] args) {
        int[] array = new int[10000];
        for (int i = 0; i < array.length; i++) {
            array[i] = i + 1; // Fill the array with numbers 1 to 10000
        }

        // Create a ForkJoinPool
        ForkJoinPool pool = new ForkJoinPool();

        // Create the main task
        SumTask task = new SumTask(array, 0, array.length);

        // Invoke the task and get the result
        int result = pool.invoke(task);

        System.out.println("Sum of array elements: " + result);
    }
}