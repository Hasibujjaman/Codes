#include<stdio.h>
#include<math.h>

int ara[26];
int size=26;



void print_ara(){
    int i;
    for(i=2;i<size;i++){
        printf("%4d",ara[i]);
    }
    printf("\n");
    for(i=2;i<size;i++){
        printf("----");
    }
    printf("\n");
    for(i=2;i<size;i++){
        printf("%4d",i);
    }
    printf("\n\n");
}


void sieve(){
    int i,j,root;
    for(i=2;i<size;i++){
        ara[i]=1;
    }
    print_ara();
    for(i=2;i<=sqrt(size);i++){
        if(ara[i]==1){
            for(j=2;i*j<=size;j++){
                ara[i*j]=0;
            }
            print_ara();
        }
    }
}



int prime(int n){
    int i;
    if(n<2) return 0;
    return ara[n];
}



int main(){
    int n;
    sieve();
     while(1){
        printf("Enter a number (Enter 0 to exit): ");
        scanf("%d",&n);
        if(n==0) break;
        if(n>=size){
            printf("The number should be less than %d\n",size);
            continue;
        }
        else if(1==prime(n)) printf("%d is a prime number\n",n);
        else printf("%d is not a prime number\n",n);
    }
    return 0;
}