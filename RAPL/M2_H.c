#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    int i;
    for (i = 1; i <= t; i++)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int A[n];
        int j, sum = 0, count = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &A[j]);
            sum += A[j];
        }
        for (j = 0; j < n; j++)
        {
            if ((A[j] + k) > (sum - A[j]))
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}