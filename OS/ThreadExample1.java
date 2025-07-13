// Creating thread (method 1):  we create a subclass of Thread and override the run() method. The start() method of Thread is then used to execute the thread

class MyThread extends Thread {
    public void run() { // Overriding run() method
        for (int i = 0; i < 5; i++) {
            System.out.println("Thread is running: " + i);
        }
    }
}

public class ThreadExample1 {
    public static void main(String[] args) {
        MyThread worker = new MyThread(); // Create a thread instance
        worker.start(); // Start the thread
    }
}
