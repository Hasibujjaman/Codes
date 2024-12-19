
#include<stdio.h>
int main()
{
    int num,incrementor;
    printf("Enter any number\n");
    scanf("%d",&num);
    printf("The multiplication table of the given number:\n");
    for(incrementor=1;incrementor<=10;incrementor++){
        printf("%d x %d = %d\n",num,incrementor,num*incrementor);
    }
}
