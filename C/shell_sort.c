#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void shell(char *items, int count);
int main(void)
{
    char s[255];
    printf("Enter a string:");
    gets(s);
    shell(s, strlen(s));
    printf("The sorted string is: %s.\n", s);
    return 0;
}



/* The Shell Sort. */
void shell(char *items, int count)
{
    register int i, j, gap, k;
    char x, a[5];
    a[0] = 9;
    a[1] = 5;
    a[2] = 3;
    a[3] = 2;
    a[4] = 1;
    for (k = 0; k < 5; k++)
    {
        gap = a[k];
        for (i = gap; i < count; ++i)
        {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}