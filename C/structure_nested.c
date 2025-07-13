#include<stdio.h>

struct addr{
   unsigned int zip;
};

struct emp{
    struct addr address;
}worker;

int main(){
    worker.address.zip = 1010;
   // address.zip = 0; is undefined 
    printf("%u\n",worker.address.zip);
}