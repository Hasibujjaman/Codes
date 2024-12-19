#include<stdio.h>

int main() {
    int s = 0, x;
    FILE * a;
    a = fopen("input.txt", "w");
    for (int i = 0; i < 10; i++) {
        fprintf(a, "%d\n", i+1);
    }
    fclose(a);
    a = fopen("input.txt", "r");
    FILE * b = fopen("output.txt", "w");
    for (int i = 0; i < 10; i++) {
        fscanf(a, "%d", &x);
        fprintf(b, "%d\n", x);
        s += x;
    }
    fprintf(b, "AVG: %lf\n", (double)s/10);
    fclose(a);
    fclose(b);


    // FILE * ptr = fopen("output.txt", "r");
    // fscanf(ptr, "%d", &x);
    // fclose(ptr);
    // FILE * ptr_i = fopen("output.txt", "w");
    // fprintf(ptr_i, "%d", x);
    // fclose(ptr_i);
    return 0;
}