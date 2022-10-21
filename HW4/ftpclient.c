// Elijah Bowlby
// CSCI 3550
// HW 4
// ftpclient.c
// 10/21/2022


// FTP echo client program
#include "headerFile.h"

// Main method
// Three arguments to be checked later
int main(int argc, char *argv[])
{
    // Declare and define variables
    // Socket descriptor
    int s;
    // Number of bytes in each receive call
    int n;
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
    // Maximum number of bytes to receive
    int maxLen = sizeof(buffer);
    // Pointer to move along the buffer
    char *ptr = buffer;
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
    if ((s = socket(PF_INET, SOCK_STREAM, 0) < 0))
    {
        perror("Error: Socket creation failed!");
        exit(1);
    }

    // Connect to the server
    if (connect(s, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
    {
        perror("Error: Connection failed!");
        exit(1);
    }

    // Data transfer section
    send(s, string, strlen(string), 0);
    while ((n = recv(s, ptr, maxLen, 0)) > 0)
    {
        // Move pointer along the buffer
        ptr += n;
        // Adjust the maximum number of bytes
        maxLen -= n;
        // Update the length of the string received
        len += n;
    } // End of while loop

    // Print and verify echoed string
    buffer[len] = '\0';
    printf("Echo string received: ");
    fputs(buffer, stdout);

    // Close the socket
    close(s);
    // Stop the program
    exit(0);
} // End of echo client program
