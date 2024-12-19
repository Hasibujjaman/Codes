#include<stdio.h>
int main(){
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    if(A>=B&&A>=C)
        printf("%d\n",10*A+B+C);
    else if(B>=A&&B>=C) 
        printf("%d\n",10*B+A+C);
    else
        printf("%d\n",10*C+A+B);
    return 0;
}