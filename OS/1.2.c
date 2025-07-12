#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global variable for number of children */
const int numChildren = 10; // Set the desired number of child processes

int main() {
    int j;
    pid_t cpid;

    setbuf(stdout, NULL); // Make stdout unbuffered

    for (j = 0; j < numChildren; j++) {
        switch (cpid = fork()) {
        case -1:
            printf("Error: fork failed\n");
            return EXIT_FAILURE;
        case 0: // Child process
            printf("Child %d is running: \tpid=%d \tppid=%d \n", j, getpid(),getppid());
            exit(EXIT_SUCCESS);
        default:
            printf("Parent of child(pid = %d) is running\n", cpid);
            wait(NULL); // Wait for a child to terminate
            printf("Child(pid = %d) terminated\n\n", cpid);
            break;
        }
    }

    return EXIT_SUCCESS;
}