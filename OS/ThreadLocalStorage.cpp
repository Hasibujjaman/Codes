#include <iostream>
#include <thread>

//thread_local int counter = 0;  // Each thread gets its own counter
static __thread int counter = 0;  // The gcc compiler provides the storage class keyword __thread for declaring TLS data

void increment() {
    counter++;  
    std::cout << "Thread ID: " << std::this_thread::get_id() 
              << " Counter: " << counter << std::endl;
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();
}
