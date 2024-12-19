#include<stdio.h>
int main() {
    int myIncrementor = 1, myMultiplier =1, finalValue = 1;
    int numberhowbig;
    printf("How many bits = ");
    scanf("%d",&numberhowbig);
    printf("\n");
    while(myIncrementor < numberhowbig) {
        myMultiplier *=2;
        finalValue = finalValue + myMultiplier;
        myIncrementor++;
    }
    if((numberhowbig == 0) || (numberhowbig == 1)){
        printf("Top value = %d\n", numberhowbig);
    }
    else{
        printf("Top value = %d\n", finalValue);
    }
}
