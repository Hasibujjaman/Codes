#include <stdio.h>
int main()
{
    char s1[201], s2[201];
    int f1[2][26] = {}, f2[2][26] = {};
    scanf("%[^\n]s", s1);
    fflush(stdin);
    scanf("%[^\n]s", s2);

    for (register int i = 0; s1[i]; i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
            f1[0][s1[i] - 'A']++;
        else if (s1[i] >= 'a' && s1[i] <= 'z')
            f1[1][s1[i] - 'a']++;
    }
    for (register int i = 0; s2[i]; i++)
    {
        if (s2[i] >= 'A' && s2[i] <= 'Z')
            f2[0][s2[i] - 'A']++;
        else if (s2[i] >= 'a' && s2[i] <= 'z')
            f2[1][s2[i] - 'a']++;
    }

    int count = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            //printf(" %d %d ",f1[i][j],f2[i][j]);
           if (f1[i][j] < f2[i][j])
            {
                count++;
                printf("NO\n");
                return 0;
            }
            
        }
       // printf("\n");
    }
    if (!count)
        printf("YES\n");
    return 0;
}