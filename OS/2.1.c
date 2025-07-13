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
        
        // Parent waits for the child to terminate
        pid_t terminated_pid = wait(&status);
        printf("(parent process) Parent process is running\n");

        // Status holds the child's termination info
        if (WIFEXITED(status)) {
            printf("(parent process) Child with PID %d terminated normally with exit code %d.\n",
                   terminated_pid, WEXITSTATUS(status));
        } else {
            printf("(parent process)Child with PID %d terminated abnormally.\n", terminated_pid);
        }


        printf("(parent process) Parent process is terminating. (terminated)\n");
    } 
    
    else if(pid == 0) {
        // Child process
        printf("\n***child process starts:\tChild process is running.\n");

        sleep(2); // Simulate some work

        printf("(child process) Child process is terminating. (terminated)\n");
        return 42; // Exit status of child
    }




    return 0;
}
