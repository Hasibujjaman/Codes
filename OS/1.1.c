#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;

    /* fork a child process */
    pid = fork();
    if (pid < 0)
    { /* error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0)
    { /* child process */
        execlp("/bin/ls", "ls", NULL); 
    }
    else
    { /* parent process */
        /* parent will wait for the child to complete */ 
        wait(NULL); // When a parent process calls wait(NULL), it waits for any one of its child processes to terminate, not all of them.
        printf("Child Complete\n");
    }
    return 0;
}