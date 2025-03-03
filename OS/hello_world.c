#include<stdio.h>
#include <unistd.h>

int main(){
    printf("\n(child process pid = %d | parent pid = %d\n", getpid(),getppid());
    printf("hello world!\n");

}