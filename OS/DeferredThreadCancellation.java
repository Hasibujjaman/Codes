class MyThread extends Thread {
    public void run() {
        while (!MyThread.currentThread().isInterrupted()) {
            System.out.println("Thread is running...");
            try {
                Thread.sleep(1000);  // Puts thread to sleep
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted! Cleaning up...");
                break;  // Exit the loop to stop execution
            }
        }
    }
}

public class DeferredThreadCancellation {
    public static void main(String[] args) throws InterruptedException {
        MyThread t = new MyThread();
        t.start();

        Thread.sleep(3000);  // Main thread waits
        System.out.println("Requesting interruption...");
        t.interrupt();  // Interrupt the thread
    }
}
