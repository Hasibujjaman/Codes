#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 5

/* Function prototype for the thread function */
void *runner(void *param);

int main(int argc, char *argv[]) {
    int i, scope;
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;

    /* get the default attributes */
    pthread_attr_init(&attr);

    /* Get the current scheduling scope */
    if (pthread_attr_getscope(&attr, &scope) != 0) { // If an error occurs, pthread_attr_getscope() and pthread_attr_setscope() returns a nonzero value.
        fprintf(stderr, "Unable to get scheduling scope\n");
    } 
    else {
        if (scope == PTHREAD_SCOPE_PROCESS) {
            printf("PTHREAD_SCOPE_PROCESS\n");
        } else if (scope == PTHREAD_SCOPE_SYSTEM) {
            printf("PTHREAD_SCOPE_SYSTEM\n");
        } else {
            fprintf(stderr, "Illegal scope value.\n");
        }
    }

    /* set the scheduling algorithm to PCS(Process Contention Scope)/PTHREAD_SCOPE_SYSTEM or SCS(System Contention Scope)/PTHREAD_SCOPE_PROCESS */
    if (pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM) != 0) {  // Linux and macOS systems allow only PTHREAD SCOPE SYSTEM
        fprintf(stderr, "Unable to set scheduling scope to SYSTEM\n");
    }

    /* Create the threads */
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&tid[i], &attr, runner, NULL) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
        }
    }

    /* Wait for all threads to complete */
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    /* Destroy the thread attributes */
    pthread_attr_destroy(&attr);

    return 0;
}

/* Thread function */
void *runner(void *param) {
    /* Do some work... */
    printf("Thread is running...\n");
    pthread_exit(NULL);
}