#include<stdio.h>
int b_search(int arr[], int li, int hi, int num){
    while(li<=hi){
        int mi=(li+hi)/2;
        if(arr[mi]==num)
            return mi;
        if(arr[mi]>num)
            hi=mi-1;n
        else
            li=mi+1;
    }
    return -1;
}
int main(){
    int n,array[n],target;//int array[n],n; wrong
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter array elements in ascending order\n");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    printf("Enter target number\n");
    scanf("%d",&target);
    if(b_search(array,0,n-1,target)==-1) printf("Target not found\n");
    else printf("Target's index is %d\n",b_search(array,0,n-1,target));
    return 0;
}
