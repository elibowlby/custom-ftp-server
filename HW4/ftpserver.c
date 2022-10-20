/*********************/
/*   Elijah Bowlby   */
/*   CSCI 3550       */
/*   HW 4            */
/*   ftpserver.c     */
/*   10/21/2022      */
/*********************/

// FTP echo server program
#include "headerFiles.h"

int main(void)
{
    // Declare and define variables
    // Listen socket descriptor (reference)
    int ls;
    // Socket descriptor (reference)
    int s;
    // Data buffer
    char buffer[256];
    // Data buffer
    char *ptr = buffer;
    // Number of bytes to send or receive
    int len = 0;
    // Maximum number of bytes to receive
    int maxLen = sizeof(buffer)
        // Number of bytes for each receive call
        int waitSize = 16;
    // Server address
    struct sockaddr_in servAddr;
    // Client address
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
    if (ls = socket(PF_INET, SOCK_STREAM, 0) < 0)
    {
        perror("Error: Listen socket failed!");
        exit(1);
    }

    // Bind listen socket to local address
    if (bind(ls, &servAddr, sizeof(servAddr)) < 0)
    {
        perror("Error: bind failed!");
        exit(1);
    }

    // Listen to connection requests
    if (listen(ls, wait size) < 0)
    {
        perror("Error: Listening failed!");
        exit(1);
    }

    // Handle the connection
    // Run forever
    for (;;)
    {
        // Accept connections from client
        if (s = accept(ls, &clntAddr, &clntAddrLen) < 0)
        {
            perror("Error: Accepting failed!");
            exit(1);
        }

        // Data transfer section
        while ((n = recv(s, ptr, maxLen, 0)) > 0)
        {
            // Move pointer along the buffer
            ptr += n;
            // Adjust maximum number of bytes to receive
            maxLen -= n;
            // Update number of bytes received
            len + -n;
        }

        // Send back (echo) all bytes received
        send(s, buffer, len, 0);

        // Close the socket
        close(s);
    } // End of for loop
} // End of echo server program