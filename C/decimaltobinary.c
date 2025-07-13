#include<stdio.h>
#include<math.h>
int main(){
    int decimal;
    printf("Enter decimal number: ");
    scanf("%d",&decimal);
    printf("The number in binary is: ");
    if(decimal==0) printf("0");
    int n=0;
    while(pow(2,n)<=decimal) n++;
    int sum=0;
    for(n-=1;n>=0;n--){
        if((pow(2,n)+sum)<=decimal){
            printf("1");
            sum+=pow(2,n);
        }
        else printf("0");
    }
    printf("\n");
    return 0;
}