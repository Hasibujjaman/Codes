// Creating thread (method 3):  we create a lambda expression that implements the Runnable interface and then pass an instance
        

public class ThreadExample3 {
    public static void main(String[] args) {
       
        Runnable task = () -> { 
            System.out.println("I am a thread.");
        };


        Thread worker = new Thread(task);
        worker.start();



    }
}