#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int arr[10] = {0,1,2,3,4,5,6,7,8,9}; /* this data is shared by all the thread(s) */
int sum; /* this data is shared by all the thread(s) */
pthread_mutex_t mutex; /* mutex to protect the shared variable */

void *runner(void *param); /* threads call this function */

int main(void)
{
    printf("This is the main thread(parent)\n");
    pthread_t tid[2]; /* the thread identifier */
    pthread_attr_t attr[2]; /* set of thread attributes */

    /* Initialize the mutex */
    pthread_mutex_init(&mutex, NULL);

    /* set the default attributes of the thread */
    pthread_attr_init(&attr[0]);
    pthread_attr_init(&attr[1]);

    /* create the thread */
    pthread_create(&tid[0], &attr[0], runner, "A"); // will sum arr[0] to arr[4]
    pthread_create(&tid[1], &attr[1], runner, "B"); // will sum  arr[5] to arr[9]

    /* wait for the thread to exit */
    for(int i = 0; i < 2; i++)
        pthread_join(tid[i], NULL);

    printf("sum = %d\n", sum);

    /* Destroy the mutex */
    pthread_mutex_destroy(&mutex);

    return 0;
}

/* The thread will execute in this function */
void *runner(void *param)
{
    pthread_t thread_id = pthread_self();
    printf("\nThis is thread %d\n", thread_id);

    if(param == "A") // will run if the thread is A
    {
        for (int i = 0; i < 5; i++) {
            pthread_mutex_lock(&mutex); // Lock the mutex before accessing the shared variable
            sum += arr[i];
            pthread_mutex_unlock(&mutex); // Unlock the mutex after accessing the shared variable
            printf("Thread: %d, sum = %d \n", thread_id, sum);
        }
    }
    else if(param == "B") // will run if the thread is B
    {
        for (int i = 5; i < 10; i++) {
            pthread_mutex_lock(&mutex); // Lock the mutex before accessing the shared variable
            sum += arr[i];
            pthread_mutex_unlock(&mutex); // Unlock the mutex after accessing the shared variable
            printf("Thread: %d, sum = %d \n", thread_id, sum);
        }
    }

    printf("Thread %d finished\n\n", thread_id);
    pthread_exit(0);
}