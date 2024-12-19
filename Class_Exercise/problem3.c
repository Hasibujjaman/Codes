#include<stdio.h>
#include<string.h>
int prime(int x){
        int i;
        for(i=2;i<x;i++){
            if(x%i==0) return 0;//not prime
        }
        return 1;//prime
    }

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int aprime[b-a+1];
    int count=0,check;
    int i,j,k;
    for(i=a,k=0;i<=b;i++){
        if(prime(i)==0){
            for(j=2;j<i;j++){
                if(prime(j)==1&&i%j==0) check++;
            }
            if(check==1){
                aprime[k]=i;
                k++;
                count++;
            }
        }
        check=0;
    }
    printf("%d\n",count);
    for(i=0;i<count;i++){
        printf("%d ",aprime[i]);
    }
    printf("\n");
    return 0;
    

}