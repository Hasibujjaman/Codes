#include <stdio.h>

int main() {
    int *ptr = NULL;
    *ptr = 10;  // This will cause a segmentation fault (SIGSEGV)
    return 0;
}
