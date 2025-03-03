#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /* this data is shared by all the thread(s) */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
    printf("This is the main thread(parent)\n");
    pthread_t tid; /* the thread identifier */
    pthread_attr_t attr; /* set of thread attributes */

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <integer value>\n", argv[0]);
        return -1;
    }

    /* set the default attributes of the thread */
    pthread_attr_init(&attr);

    /* create the thread */
    pthread_create(&tid, &attr, runner, argv[1]);



    /* wait for the thread to exit */
    pthread_join(tid, NULL);

    printf("sum = %d\n", sum);

    return 0;
}

/* The thread will execute in this function */
void *runner(void *param)
{
    printf("\nThis is thread 2(child)\n");
    int i, upper = atoi(param);
    sum = 0;

    for (i = 1; i <= upper; i++)
        sum += i;

    printf("Thread 2 finished\n\n");
    pthread_exit(0);
}