#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg) {
    while (1) {
        printf("Thread running...\n");
        sleep(1);
        pthread_testcancel();  // Check if cancellation has been requested. If a cancellation request is found to be pending, the call to pthread testcancel() will not return, and the thread will terminate; otherwise, the call to the function will return, and the thread will continue to run
    }
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);

    sleep(3);  // Let the thread run for a while
    printf("Requesting cancellation...\n");
    pthread_cancel(thread);  // Request cancellation

    pthread_join(thread, NULL);
    printf("Thread terminated.\n");

    return 0;
}
