#include <xinu.h>
#include <stdio.h>


void proc1(sid32), proc2(sid32), proc3(sid32);




shellcmd xsh_hello(int nargs, char *args[])
{
    sid32 mutex;
    mutex = semcreate(0);

    printf("Main process (pid = %d) is running and will now create 3 child process\n", getpid());
    resume( create(proc1, 1024, 20, "Proc_1", 1, mutex) );
    resume( create(proc2, 1024, 20, "Proc_2", 1, mutex) );
    resume( create(proc3, 1024, 20, "Proc_3", 1, mutex) );

    printf("\nMain process (pid = %d) is running and will exit now\n\n\n", getpid());

    //printf("Hello World\n");
    return 0;
}

//child 1
void proc1 ( sid32 mutex )
{
    struct procent *prptr;
    prptr = &proctab[getpid()];

    pid32 parent_pid = prptr->prparent;
    char *process_name = prptr->prname;

    if(semcount(mutex) <= 0)
        printf("\n\n Semaphore value = %d ||| Process = %s will now be in WAITING state \n\n\n", semcount(mutex), process_name);
        
    wait(mutex);
    printf("Process = %s is resumed ||| pid = %d ||| parent pid = %d ||| semaphore(on which this pr waits on): sid = %d value = %d  \n\n", process_name, getpid(), parent_pid, mutex, semcount(mutex));
}



//child 2
void proc2( sid32 mutex )
{
    struct procent *prptr;
    prptr = &proctab[getpid()];

    pid32 parent_pid = prptr->prparent;
    char *process_name = prptr->prname;
 
    if(semcount(mutex) <= 0)
        printf("\n\n Semaphore value = %d ||| Process = %s will now be in WAITING state \n\n\n", semcount(mutex), process_name);

    wait(mutex);
    printf("Process = %s is resumed ||| pid = %d ||| parent pid = %d ||| semaphore(on which this pr waits on): sid = %d value = %d  \n\n", process_name, getpid(), parent_pid, mutex, semcount(mutex));


}



//child 3
void proc3( sid32 mutex )
{
    struct procent *prptr;
    prptr = &proctab[getpid()];

    pid32 parent_pid = prptr->prparent;
    char *process_name = prptr->prname;

    printf("Process = %s is running ||| pid = %d ||| parent pid = %d ||| semaphore(on which this pr waits on): sid = %d value = %d  \n\n", process_name, getpid(), parent_pid, mutex, semcount(mutex));
    if(semcount(mutex) == -1)
        printf("\n\n A child will be released from the WAITING list\n\n\n");
    else if(semcount(mutex) == -2)
        printf("\n\n Both child will be released from the WAITING list\n\n\n");

    signaln(mutex,2);
}

