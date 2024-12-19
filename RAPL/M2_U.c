#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    char genom[n];
    int freq[n];
    scanf("%s",genom);
    int i,sum,temp;
    char fixed[] = "ACTG";
    sum = 1000000;
    for(i=0;i< n-3;i++){
        int diff, ans = 0;
        for (int j = i; j <= i+3; j++) {
            diff = abs(genom[j] - fixed[j-i]);
            int tmp = 26 - abs(genom[j] - fixed[j-i]);
            if (tmp < diff) diff = tmp;
            ans += diff;
        }
        if (ans < sum) sum = ans;
    }
    printf("%d\n",sum);
    return 0;


}