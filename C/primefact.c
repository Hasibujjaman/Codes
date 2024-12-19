#include <stdio.h>

int main()
{
    int n;
    printf("Enter any between 2-99: ");
    scanf("%d",&n);
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for(int i = 0; primes[i] <= n; i++){
        int cur = primes[i];
        int total = 0;
        while(cur <= n){
            total += (n/cur);
            cur = cur*cur;
        }
        printf("(%d^%d)\n", primes[i], total);
    }
    return 0;
}