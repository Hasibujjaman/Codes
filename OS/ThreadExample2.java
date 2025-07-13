// Creating thread (method 2):  we create a class that implements the Runnable interface and then pass an instance of that class to the Thread constructor. The start() method of Thread is then used to execute the thread

class Task implements Runnable {
    public void run() { // Implementing run() method
        for (int i = 0; i < 5; i++) {
            System.out.println("Runnable thread is running: " + i);
        }
    }
}

public class ThreadExample2 {
    public static void main(String[] args) {
        Task task = new Task(); // Create task
        Thread worker = new Thread(task); // Pass task to a Thread
        worker.start(); // Start the thread
    }
}
