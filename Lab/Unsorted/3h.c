#include<stdio.h>
int main(){
    int n;
    printf("Input the size of array : ");
    scanf("%d",&n);
    printf("Input %d elements in the array :\n",n);
    int i;
    int ara[n];
    for(i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&ara[i]);
    }


    int small1,small2,i1,i2,temp;
    small1=ara[0];
    i1=0;
    for(i=1;i<n;i++){
        if(ara[i]<small1){
            small1=ara[i];
            i1=i;
        }
    }

    if(i1==0) {
        small2=ara[1];
        i2=1;
    }
    else {
        small2=ara[0];
    }

    for(i=0;i<n;i++){
        if(ara[i]<small2&&i!=i1){
            small2=ara[i];
            i2=i;
        }
    }


    printf("The second smallest element in the array is : %d\n",ara[i2]);
    
    return 0;
}