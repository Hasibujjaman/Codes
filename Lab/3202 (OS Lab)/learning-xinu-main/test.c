#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int stat() {
    static int i = 10;
    i++;
    return i;
}

int main() {
    printf("\n%d\n", stat());
    printf("\n%d\n", stat());



    return 0;
}