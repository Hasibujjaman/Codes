#include <stdio.h> 
#include <stdlib.h>
int pwr(int a, int b);

int main(void) {
    int (*p)[10]; //Declare a pointer to an array that has 10 ints in each row.
    register int i, j;
    p = malloc(40*sizeof(int)); //allocate memory to hold a 4 x 10 array
    if(!p) {
        printf("Memory request failed.\n"); 
        exit (1);
    }
    for(j=1; j<11; j++)
        for(i=1; i<5; i++) p[i-1][j-1] = pwr(j, i);
    for(j=1; j<11; j++) {
        for(i=1; i<5; i++) printf("%10d ", p[i-1][j-1]);
        printf ("\n");
    }
    return 0; 
}
/* Raise an integer to the specified power. */ 
int pwr(int a, int b){
    register int t=1;
    for(; b; b--) t = t*a;
    return t;
}