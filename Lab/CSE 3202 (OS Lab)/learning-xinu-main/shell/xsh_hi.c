#include <xinu.h>
#include <stdio.h>


void prod2(sid32, sid32), cons2(sid32, sid32);


int32 n = 0; /* Variable n has initial value zero */


shellcmd xsh_hi(int nargs, char *args[])
{
    sid32 produced, consumed;
    consumed = semcreate(0);
    produced = semcreate(1);

    printf("Main process (pid = %d) is running and will now create 2 child process\n", getpid());
    resume( create(cons2, 1024, 20, "cons", 2, consumed, produced) );
    resume( create(prod2, 1024, 20, "prod", 2, consumed, produced) );
    printf("Main process (pid = %d) is running and will exit now\n", getpid());

    //printf("Hello World\n");
    return 0;
}

void prod2 ( sid32 consumed, sid32 produced )
{
    struct procent *prptr;
    prptr = &proctab[getpid()];

    pid32 parent_pid = prptr->prparent;
    char *process_name = prptr->prname;
    sid32 semaphore;

    int32 i;
    for( i=1 ; i<=5 ; i++ )
    {
        if(semcount(consumed) <= 0)
            printf("\n\n Process %s will now be in WAITING state\n\n\n", process_name);
        

        wait(consumed);
        n++;
        printf("Process name = %s ||| pid = %d |||  n = %d  ||| parent pid = %d ||| semaphore(on which this pr waits on): sid = %d value = %d  \n\n", process_name, getpid(), n, parent_pid, semaphore=prptr->prsem, semcount(semaphore));
        signal(produced);
    }
}

void cons2( sid32 consumed, sid32 produced )
{
    struct procent *prptr;
    prptr = &proctab[getpid()];

    pid32 parent_pid = prptr->prparent;
    char *process_name = prptr->prname;
    sid32 semaphore;

    int32 i;
    for( i=1 ; i<=5 ; i++ )
    {   
        if(semcount(produced) <= 0)
            printf("\n\n Process %s will now be in WAITING state\n\n\n", process_name);


        wait(produced);
        printf("Process name = %s ||| pid = %d |||  n = %d  ||| parent pid = %d ||| semaphore(on which this pr waits on): sid = %d value = %d  \n\n", process_name, getpid(), n, parent_pid, semaphore=prptr->prsem, semcount(semaphore));
        signal(consumed);

    }
}

