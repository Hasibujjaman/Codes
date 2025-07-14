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


    int large1,large2,i1,i2,temp;
    large1=ara[0];
    i1=0;
    for(i=1;i<n;i++){
        if(ara[i]>large1){
            large1=ara[i];
            i1=i;
        }
    }

    if(i1==0) {
        large2=ara[1];
        i2=1;
    }
    else {
        large2=ara[0];
    }

    for(i=0;i<n;i++){
        if(ara[i]>large2&&i!=i1){
            large2=ara[i];
            i2=i;
        }
    }


    printf("The second largest element in the array is : %d\n",ara[i2]);
    
    return 0;
}