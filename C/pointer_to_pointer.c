#include <stdio.h>
int main(void) {
    int a = 10;
    int *p1,**p2;
    p1 = &a;
    p2 = &p1;
    printf("(%p %d %p) (%p %d %p)\n",p1,*p1,&p1, p2,**p2,&p2);
    return 0; 
}