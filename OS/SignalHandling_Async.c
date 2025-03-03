#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// User-defined signal handler
void handle_signal(int sig) {   
    printf("Caught signal %d (SIGINT). Ignoring Ctrl+C!\n", sig);
}

int main() {
    signal(SIGINT, handle_signal);  // Register signal handler

    while (1) {
        printf("Running... Press Ctrl+C to try to terminate me!\n");
        sleep(2);
    }
    return 0;
}
