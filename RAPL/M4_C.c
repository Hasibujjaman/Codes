#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n], t[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    int sum1, sum2;
    sum1 = sum2 = 0;
    for (int i = 0, temp = 0; i < n; i++)
    {
        if (t[i])
        {
            sum1 += a[i];
        }
        if (i < k)
        {
            if (!t[i])
            {
                temp += a[i];
                sum2 = temp;
            }
        }
        else
        {
            if (!t[i])
                temp += a[i];
            if (!t[i - k])
                temp -= a[i - k];
            if (sum2 < temp)
                sum2 = temp;
        }
    }
    // printf("%d %d\n",sum1,sum2);
    printf("%d\n", sum1 + sum2);
    return 0;
}