#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void bubble(char *items, int count);
int main(void)
{
    char s[255];
    printf("Enter a string:");
    gets(s);
    bubble(s, strlen(s));
    printf("The sorted string is: %s.\n", s);
    return 0;
}

/* The Bubble Sort. */ // complexity: .5(n^2-n)
void bubble(char *items, int count)
{
    register int a, b;
    register char t;
    for (a = 1; a < count; ++a)
        for (b = count - 1; b >= a; --b)
        {
            if (items[b - 1] > items[b])
            {
                /* exchange elements */ t = items[b - 1];
                items[b - 1] = items[b];
                items[b] = t;
            }
        }
}