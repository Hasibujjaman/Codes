// compile with:  gcc -fopenmp -o ImplicitThreading_OpenMP ImplicitThreading_OpenMP.c
#include <omp.h>
#include <stdio.h>

int N = 100;
int main(int argc, char *argv[])
{ /* sequential code */

#pragma omp parallel
    {
        printf("I am a parallel region.");
    }

    /* sequential code*/
    int a[N], b[N], c[N];
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
        b[i] = i;
    }

#pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
        printf("Thread %d: c[%d] = %d\n", omp_get_thread_num(), i, c[i]);
    }

    /* sequential code */
    return 0;
}