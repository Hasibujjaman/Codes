#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define NUM_THREADS 5

void *runner(void *param);

int main(int argc, char *argv[]) {
    int i, policy, ret;
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;
    struct sched_param param;

    /* Initialize attribute object */
    pthread_attr_init(&attr);

    /* Get the current scheduling policy */
    if ((ret = pthread_attr_getschedpolicy(&attr, &policy)) != 0) {
        fprintf(stderr, "Unable to get policy: %s\n", strerror(ret));
    } else {
        if (policy == SCHED_OTHER)
            printf("Default policy: SCHED_OTHER\n");
        else if (policy == SCHED_RR)
            printf("Default policy: SCHED_RR\n");
        else if (policy == SCHED_FIFO)
            printf("Default policy: SCHED_FIFO\n");
    }

    /* Set the scheduling policy to FIFO */
    if ((ret = pthread_attr_setschedpolicy(&attr, SCHED_FIFO)) != 0) {
        fprintf(stderr, "Unable to set policy: %s\n", strerror(ret));
    }

    /* Set the priority to maximum for SCHED_FIFO */
    param.sched_priority = sched_get_priority_max(SCHED_FIFO);
    if ((ret = pthread_attr_setschedparam(&attr, &param)) != 0) {
        fprintf(stderr, "Unable to set sched_param: %s\n", strerror(ret));
    }

    /* Explicitly tell the attr that you want to use EXPLICIT SCHED */
    if ((ret = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED)) != 0) {
        fprintf(stderr, "Unable to set inherit sched: %s\n", strerror(ret));
    }

    /* Create threads */
    for (i = 0; i < NUM_THREADS; i++) {
        if ((ret = pthread_create(&tid[i], &attr, runner, NULL)) != 0) {
            fprintf(stderr, "Unable to create thread: %s\n", strerror(ret));
        }
    }

    /* Join threads */
    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(tid[i], NULL);

    return 0;
}

void *runner(void *param) {
    printf("Thread %ld is running\n", pthread_self());
    sleep(1);
    printf("Thread %ld is done\n", pthread_self());
    pthread_exit(0);
    return NULL;
}
