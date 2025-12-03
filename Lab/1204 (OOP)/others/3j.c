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
    printf("The given array is : ");
    for(i=0;i<n;i++){
        printf("%d ",ara[i]);
    }


    int j,count=0;
    for(i=1;;i++,count=0){
        for(j=0;j<n;j++){
            if(i==ara[j]){
                count++;
                break;
            }
        }
        if(count==0){
            printf("\nThe smallest positive number missed is: %d\n",i);
            break;
        }
    }

    return 0;

}