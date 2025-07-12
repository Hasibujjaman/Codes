#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg) {
    while (1) {  // Infinite loop
        printf("Thread running...\n");
        sleep(1);
    }
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);

    sleep(3);  // Let the thread run for a while
    printf("Cancelling thread...\n");
    pthread_cancel(thread);  // Asynchronous cancellation

    pthread_join(thread, NULL);
    printf("Thread terminated.\n");

    return 0;
}
