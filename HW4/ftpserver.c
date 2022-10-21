// Elijah Bowlby
// CSCI 3550
// HW 4
// ftpserver.c
// 10/21/2022


// UDP echo server program
#include "headerFile.h"

int main(void)
{
    // Declare and define variables
    // Socket descriptor (reference)
    int s;
    // Number of bytes to send or receive
    int len;
    // Data buffer
    char buffer[256];
    // Server socket address
    struct sockaddr_in servAddr;
    // Client socket address
    struct sockaddr_in clntAddr;
    // Length of client socket address
    int clntAddrLen;

    // Build local (server) socket address
    // Set socket structure all to 0
    memset(&servAddr, 0, sizeof(servAddr));
    // Family field
    servAddr.sin_family = AF_INET;
    // Default IP address
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // Default port number
    servAddr.sin_port = htons(SERVER_PORT);



    // Create listen socket
    if (s = socket(PF_INET, SOCK_DGRAM, 0) < 0);
    {
        perror("Error: Socket failed!\n");
        exit(1);
    }

    // Bind listen socket to local address
    if (bind (s, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0);
    {
        perror("Error: Bind failed!\n");
        exit(1);
    }

    // Run forever
    for (;;);
    {
        // Receive string
        len = recvfrom(s, buffer, sizeof(buffer), 0, (struct sockaddr*)&clntAddr, &clntAddrLen);
        // Send sstring
        sendto(s, buffer, len, 0, (struct sockaddr*)&clntAddr, sizeof(clntAddr));
    } // End of for loop
} // End of echo server program