#include<stdio.h>
#include<string.h>

int main(void) {
char s1[80], s2[80];
int (*p)(const char *, const char *); /* function pointer */
p = strcmp; /* assign address of strcmp to p */
printf("Enter two strings.\n"); gets(s1);
gets(s2);
check(s1, s2, p); /* pass address of strcmp via p */
return 0; 
}

void check( char *a, char *b, int (*cmp) (const char *, const char *) )
{
    printf("Testing for equality.\n"); 
    if(!(*cmp)(a, b)) // (*cmp)(a,b) and cmp(a,b) are euivalent expressions
    printf("Equal"); else printf("Not Equal");
}