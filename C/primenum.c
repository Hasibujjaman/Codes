#include<stdio.h>
int main(){
    int num,count,i;
    count = 0;
    printf("Enter any positive integer number: ");
    scanf("%d",&num);
    for(i=2;i<num;i++) {
        if(num%i==0) count++;
    }
    if(count==0) printf("The number is a prime number\n");
        else if(count != 0) printf("The number is not a prime number\n");
            else printf("Wrong input\n");
    return 0;
}
