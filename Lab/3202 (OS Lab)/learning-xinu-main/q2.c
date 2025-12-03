#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

int main() {
    pid_t first_child = fork();
    pid_t second_child;
    pid_t grand_child;

    if (first_child < 0) {
        printf("Fork failed\n");
        exit(-1);
    }

    if (first_child == 0) { // first child
        printf("First child is suiciding\n");
        exit(0); // first child exits
    }

    if (first_child > 0) { // parent
        second_child = fork();


        if (second_child > 0) { // parent
            wait(NULL); // wait for first child
            wait(NULL); // wait for second child
            printf("Parent is exiting\n");
            exit(0);
        }
    }

    if (second_child == 0) { // second child
        printf("Second child running. Going to create a grandchild\n");
        grand_child = fork();

        if (grand_child > 0) { // second child
            wait(NULL); // wait for grandchild to terminate
            printf("Second child exiting\n");
            exit(0);
        }
    }

    if (grand_child == 0) { // grandchild
        printf("Grandchild exiting\n");
        exit(0);
    }

    return 0;
}