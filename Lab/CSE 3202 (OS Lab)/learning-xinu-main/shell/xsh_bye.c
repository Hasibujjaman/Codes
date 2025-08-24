#include <xinu.h>
#include <stdio.h>


void pr1(sid32), pr2(pid32), pr3(void);




shellcmd xsh_bye(int nargs, char *args[])
{
    sid32 mutex;
    mutex = semcreate(0);


    printf("Main process (pid = %d) is running and will now create 2 child process\n", getpid());

    pid32 child1_pid = create(pr1, 1024, 20, "Child_1", 1, mutex);
    resume(child1_pid);
    resume( create(pr2, 1024, 20, "Child_2", 1, child1_pid) );
    signal(mutex);

    printf("Main process (pid = %d) is running and will exit now\n", getpid());

    //printf("Hello World\n");
    return 0;
}


//child 1
void pr1 (sid32 mutex)
{
    struct procent *prptr;
    prptr = &proctab[getpid()];
    pid32 parent_pid = prptr->prparent;
    char *process_name = prptr->prname;

        
    printf("Process name = %s ||| pid = %d ||| parent pid = %d ||| \n\n", process_name, getpid());

    printf("\nParent will be suspended by child1(pid=%d)\n",getpid());
    wait(mutex);
    suspend(parent_pid);


}


//child 2
void pr2( pid32 child1_pid )
{
    struct procent *prptr;
    prptr = &proctab[getpid()];
    pid32 parent_pid = prptr->prparent;
    char *process_name = prptr->prname;
 

    printf("Process name = %s ||| pid = %d ||| parent pid = %d ||| \n\n", process_name, getpid());

    resume( create(pr3, 1024, 20, "Grandchild", 0) );
    kill(child1_pid);
    printf("\nParent will be resumed by child2(pid=%d)\n",getpid());
    resume(parent_pid);

}


// grandchild
void pr3(void)
{
    struct procent *prptr;
    prptr = &proctab[getpid()];
    pid32 parent_pid = prptr->prparent;
    char *process_name = prptr->prname;

    printf("Process name = %s ||| pid = %d ||| parent pid = %d ||| \n\n", process_name, getpid());
}

