#include <mach/mach.h>
#include <stdio.h>
#include <string.h>

#define MESSAGE_SIZE 256

struct message {
    mach_msg_header_t header;
    char data[MESSAGE_SIZE];
};

mach_port_t server;

/* Initialize server port */
void initialize_server_port() {
    // Allocate a port for the server
    kern_return_t kr = mach_port_allocate(mach_task_self(), MACH_PORT_RIGHT_RECEIVE, &server);
    if (kr != KERN_SUCCESS) {
        fprintf(stderr, "Failed to allocate server port: %s\n", mach_error_string(kr));
        return;
    }
    kr = mach_port_insert_right(mach_task_self(), server, server, MACH_MSG_TYPE_MAKE_SEND);
    if (kr != KERN_SUCCESS) {
        fprintf(stderr, "Failed to insert right for server port: %s\n", mach_error_string(kr));
        return;
    }
    printf("Server port: %d\n", server); // Print the server port for client reference
}

/* Server Code */
void server_code() {
    struct message message;
    // receive the message
    kern_return_t kr = mach_msg(&message.header,       // message header
                                MACH_RCV_MSG,          // receiving a message
                                0,                     // size of message sent
                                sizeof(message),       // maximum size of received message
                                server,                // name of receive port
                                MACH_MSG_TIMEOUT_NONE, // no time outs
                                MACH_PORT_NULL         // no notify port
    );
    if (kr != KERN_SUCCESS) {
        fprintf(stderr, "Failed to receive message: %s\n", mach_error_string(kr));
        return;
    }
    // print the received message
    printf("Received message: %s\n", message.data);
}

int main() {
    // Initialize server port here
    initialize_server_port();
    
    // Run the server code to receive messages
    while (1) {
        server_code();
    }

    return 0;
}