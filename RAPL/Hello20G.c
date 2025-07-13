#include <stdio.h>
#include <math.h>
int main()
{

    long long int n, i,x,y,check, mul, count = 0;
    scanf("%lld", &n);

    for (i = 1; i <= sqrt(2 * n); i++)
    {
        mul = 2 * n;
        if (mul % i == 0)
        {
            x = i;
            y = mul / i;
            check=(x+y-1);
            if (check % 2 == 0)
            {
                count++;
            }
        }
    }
    printf("%lld\n", count * 2);
    return 0;
}