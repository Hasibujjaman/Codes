#include<stdio.h>

enum coin {penny, nickel = 9, dime}; // penny , nickel , dime are named integer constants

int main(){
    enum coin money;
    money = dime;
    printf("%d %d %d\n",penny,nickel,dime);
    printf("%d\n",money);
    return 0;
}