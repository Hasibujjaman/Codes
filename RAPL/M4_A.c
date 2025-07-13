#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, count;
        count = 0;
        scanf("%d", &n);
        int num[n];
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            for (int j = 0; j < i; j++)
            {
                if (temp == num[j])
                {
                    count++;
                    break;
                }
            }
            num[i] = temp;
        }
        if (count)
            printf("ne krasivo\n");
        if (!count)
            printf("prekrasnyy\n");
    }
    return 0;
}