#include <mach/mach.h>
#include <stdio.h>
#include <string.h>

#define MESSAGE_SIZE 256

struct message {
    mach_msg_header_t header;
    char data[MESSAGE_SIZE];
};

mach_port_t client;
mach_port_t server;

/* Initialize client and server ports */
void initialize_ports() {
    // Allocate a port for the client
    kern_return_t kr = mach_port_allocate(mach_task_self(), MACH_PORT_RIGHT_RECEIVE, &client);
    if (kr != KERN_SUCCESS) {
        fprintf(stderr, "Failed to allocate client port: %s\n", mach_error_string(kr));
        return;
    }
    kr = mach_port_insert_right(mach_task_self(), client, client, MACH_MSG_TYPE_MAKE_SEND);
    if (kr != KERN_SUCCESS) {
        fprintf(stderr, "Failed to insert right for client port: %s\n", mach_error_string(kr));
        return;
    }

    // Obtain the server port (this would typically be done through some lookup mechanism)
    // For this example, we assume the server port is predefined
    printf("Enter the server port: ");
    scanf("%u", &server); // Read the server port from user input
    printf("Client port: %d, Server port: %d\n", client, server); // Debugging information
}

/* Client Code */
void client_code() {
    struct message message;
    // construct the header
    message.header.msgh_size = sizeof(message);
    message.header.msgh_remote_port = server;
    message.header.msgh_local_port = MACH_PORT_NULL; // No reply port needed
    message.header.msgh_bits = MACH_MSGH_BITS(MACH_MSG_TYPE_COPY_SEND, 0);
    // set the message data
    strncpy(message.data, "Hello world!", MESSAGE_SIZE);
    // send the message
    kern_return_t kr = mach_msg(&message.header, // message header
                                MACH_SEND_MSG,   // sending a message
                                sizeof(message), // size of message sent
                                0,               // maximum size of received message - unnecessary
                                MACH_PORT_NULL,  // name of receive port - unnecessary
                                MACH_MSG_TIMEOUT_NONE, // no time outs
                                MACH_PORT_NULL   // no notify port
    );
    if (kr != KERN_SUCCESS) {
        fprintf(stderr, "Failed to send message: %s\n", mach_error_string(kr));
    } else {
        printf("Message sent successfully.\n");
    }
}

int main() {
    // Initialize client and server ports here
    initialize_ports();
    
    client_code();


    return 0;
}