#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void quick(char *items);
void qs(char *items, int left, int right);
int main(void)
{
    char s[255];
    printf("Enter a string:");
    gets(s);
    quick(s);
    printf("The sorted string is: %s.\n", s);
    return 0;
}
/* The Quicksort. */
void qs(char *items, int left, int right)
{
    register int i, j;
    char x, y;
    i = left;
    j = right;
    x = items[(left + right) / 2];
    do
    {
        while ((items[i] < x) && (i < right))
            i++;
        while ((x < items[j]) && (j > left))
            j--;
        if (i <= j)
        {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
        qs(items, left, j);
    if (i < right)
        qs(items, i, right);
}
/* Quicksort setup function. */
void quick(char *items)
{   int count=0;
    while(items[count]) count++;
    qs(items, 0, count - 1);
}
