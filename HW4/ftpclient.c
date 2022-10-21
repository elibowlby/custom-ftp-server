// Elijah Bowlby
// CSCI 3550
// HW 4
// ftpclient.c
// 10/21/2022


// UDP echo client program
#include "headerFile.h"

// Main method
// Three arguments to be checked later
int main(int argc, char *argv[])
{
    // Declare and define variables
    // Socket descriptor
    int s;
    // Data buffer
    char buffer[256 + 1];
    // Server name
    char *servName;
    // Server port
    int servPort;
    // String to be echoed
    char *string;
    // Length of string to be echoed
    int len;
    // Server socket address
    struct sockaddr_in servAddr;

    // Check and set program arguments
    if (argc != 3)
    {
        printf("Error: Three arguments are needed!");
        exit(1);
    }

    servName = argv[1];
    servPort = atoi(argv[2]);
    string = argv[3];

    // Build server socket address
    memset(&servAddr, 0, sizeof(servAddr));

    // Server IP address;
    servAddr.sin_family = AF_INET;
    // Server port number
    servAddr.sin_port = htons(servPort);
    inet_pton(AF_INET, servName, &servAddr.sin_addr);


    // Create socket
    if ((s = socket(PF_INET, SOCK_DGRAM, 0) < 0))
    {
        perror("Error: Socket failed!");
        exit(1);
    }

    // Send echo string
    len = sendto(s, string, strlen(string), 0, (struct sockaddr*)&servAddr, sizeof(servAddr));
    // Receive echo string
    recvfrom(s, buffer, len, 0, NULL, NULL);
    
    // Print and verify echoed string
    buffer[len] = '\0';
    printf("Echo string received: ");
    fputs(buffer, stdout);

    // Close the socket
    close(s);
    // Stop the program
    exit(0);
} // End of echo client program
