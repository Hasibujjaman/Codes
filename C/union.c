#include <stdio.h>
#include <stdlib.h>

int pputw(short int num, FILE *fp);

union pw
{
    short int i;
    char ch[2];
};


int main(void)
{
    FILE *fp;
    fp = fopen("test.tmp", "wb+");
    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        exit(1);
    }
    pputw(1025, fp); /* write the value 1025 */
    fclose(fp);
    return 0;
}
int pputw(short int num, FILE *fp)
{
    union pw word;
    word.i = num;
    putc(word.ch[0], fp);        /* write first half */
    return putc(word.ch[1], fp); /* write second half */
}