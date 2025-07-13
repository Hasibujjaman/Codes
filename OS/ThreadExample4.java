class Task implements Runnable {
    public void run() { // Implementing run() method
        for (int i = 0; i < 5; i++) {
            System.out.println("Runnable thread is running: " + i + " | Thread ID: " + Thread.currentThread().getId());
        }
    }
}

public class ThreadExample4 {
    public static void main(String[] args) {
        int numberOfThreads = 3; // Number of threads to create
        Thread[] threads = new Thread[numberOfThreads];

        for (int i = 0; i < numberOfThreads; i++) {
            Task task = new Task(); // Create task
            threads[i] = new Thread(task); // Pass task to a Thread
            threads[i].start(); // Start the thread
        }

        // Wait for all threads to finish
        for (int i = 0; i < numberOfThreads; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println("All threads have finished.");
    }
}