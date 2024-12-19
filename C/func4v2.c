#include<stdio.h>
#include<string.h>
double find_max(double ara[],int size){ //double ara[]; not allowed except in function patameter. Also can be written as *p or ara[anysize]
    double max;                             
    int i;
    max=ara[0];
    for(i=1;i<size;i++){
        if(ara[i]>max){
            max=ara[i];
        }
    }
    ara[0]=0; //it will store to arr[0] of main func cause ara[] receives pointer to arr array of main func.
    return max;
}
int main(){
    int n;
    int i;
    scanf("%d",&n);
    double arr[n];
    for(i=0;i<n;i++){
        scanf("%lf",&arr[i]);
    }
    printf("%lf\n",find_max(arr,n));
    printf("\n%lf\n",arr[0]);
    return 0;
}
