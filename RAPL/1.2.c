#include<stdio.h>
int main(){
unsigned long long int A,B,C,D,count=0;
scanf("%llu %llu %llu %llu",&A,&B,&C,&D);
for(A=A;A<=B;A++){
    if(A%C!=0&&A%D!=0){
        count++;
    }
}
printf("%llu\n",count);
return 0;
}