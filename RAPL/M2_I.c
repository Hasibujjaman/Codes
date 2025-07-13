#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int i;
    for(i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        int height[n],l=0,h=0;
        int j;
        for(j=0;j<n;j++){
            scanf("%d",&height[j]);
        }
        for(j=0;j<n-1;j++){
            if(height[j]<height[j+1]) h++;
            else if(height[j]>height[j+1]) l++;
        }
        printf("Case %d: %d %d\n",i,h,l);

    }
    return 0;
}