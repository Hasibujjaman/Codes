#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid > 0) {
        // Parent process
        int status;
        printf("\n***parent process starts:\tParent is waiting for child to terminate...\n");

        sleep(1); // Simulate some work
        printf("(parent process) Parent process is running.\n");
        
        
        sleep(1);
        printf("(parent process) Parent process is running\n");

        // 
        printf("(parent process) Parent porecess is terminating. (terminated)\n");
        
    } 
    
    else if(pid == 0) {
        // Child process
        printf("\n***child process starts (parent pid = %d):\tChild process is running.\n", getppid());

        sleep(2); // Simulate some work

        printf("(child process)  parent pid = %d\n", getppid());
        printf("(child process) Child process is terminating. (terminated)\n");
        return 42; // Exit status of child
    }




    return 0;
}

