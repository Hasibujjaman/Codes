//macOS does not support SCHED_FIFO or SCHED_RR for pthread scheduling in the same way as Linux or other POSIX real-time operating systems do.

#include <pthread.h>
#include <stdio.h>
#include <unistd.h> // For sleep function

#define NUM_THREADS 5

/* Function prototype */
void *runner(void *param);

int main(int argc, char *argv[]) {
    int i, policy;
    pthread_t tid[NUM_THREADS];  
    pthread_attr_t attr;         

    /* get the default attributes */
    pthread_attr_init(&attr);

    /* get the current scheduling policy */
    if (pthread_attr_getschedpolicy(&attr, &policy) != 0)
        fprintf(stderr, "Unable to get policy.\n");
    else {
        if (policy == SCHED_OTHER)
            printf("SCHED_OTHER\n");
        else if (policy == SCHED_RR)
            printf("SCHED_RR\n");
        else if (policy == SCHED_FIFO)
            printf("SCHED_FIFO\n");
    }

    /* set the scheduling policy - FIFO, RR, or OTHER */
    if (pthread_attr_setschedpolicy(&attr, SCHED_FIFO) != 0)
        fprintf(stderr, "Unable to set policy.\n");

    /* create the threads */
    for (i = 0; i < NUM_THREADS; i++)
        pthread_create(&tid[i], &attr, runner, NULL);

    /* now join on each thread */
    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(tid[i], NULL);

    return 0;
}

/* Each thread will begin control in this function */
void *runner(void *param) {
    /* do some work ... */
    printf("Thread %ld is running\n", pthread_self());
    sleep(1);  // Simulate some work by sleeping for 1 second
    printf("Thread %ld is done\n", pthread_self());
    pthread_exit(0);
    return NULL;  // Added for completeness
}