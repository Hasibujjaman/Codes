
class MyThread {
    private static ThreadLocal<Integer> threadData = ThreadLocal.withInitial(() -> 0);  // ThreadLocal is a class that provides thread-local variables. Each thread accessing the variable has its own, independently initialized copy of the variable.

    public void increment() {
        threadData.set(threadData.get() + 1);
        System.out.println("Thread " + Thread.currentThread().getId() + " Counter: " + threadData.get());
    }
}

public class ThreadLocalStorage {
    public static void main(String[] args) {
        MyThread myThread = new MyThread();

        Thread t1 = new Thread(myThread::increment);
        Thread t2 = new Thread(myThread::increment);

        t1.start();
        t2.start();
    }
}
