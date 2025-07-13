#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void insert(char *items, int count);
int main(void)
{
    char s[255];
    printf("Enter a string:");
    gets(s);
    insert(s, strlen(s));
    printf("The sorted string is: %s.\n", s);
    return 0;
}


/* The Insertion Sort. */ // complexity: 
void insert(char *items, int count)
{
    register int a, b;
    char t;
    for (a = 1; a < count; ++a)
    {
        t = items[a];
        for (b = a - 1; (b >= 0) && (t < items[b]); b--)
            items[b + 1] = items[b];
        items[b + 1] = t;
    }
}