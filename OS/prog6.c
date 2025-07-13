#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global variable for number of children */
const int numChildren = 3; // Set the desired number of child processes

int main() {
    int j;
    pid_t childPid;

    setbuf(stdout, NULL); // Make stdout unbuffered

    for (j = 0; j < numChildren; j++) {
        switch (childPid = fork()) {
        case -1:
            printf("Error: fork failed\n");
            return EXIT_FAILURE;
        case 0:
            printf("%d child(pid = %d)\n", j, getpid());
            if(j==0 || j==1){
                exit(EXIT_SUCCESS);
            }
            break;
            
        default:
            printf("%d parent\n", j);
            wait(NULL); // Wait for child to terminate
            break;
        }
    }
    printf("Survided child pid = %d\n", getpid());

    return EXIT_SUCCESS;
}