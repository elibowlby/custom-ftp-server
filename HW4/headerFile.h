// Elijah Bowlby
// CSCI 3550
// HW 4
// headerFile.h
// 10/21/2022


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


// Structs are already defined in import libraries

// struct sockaddr
// {
//     unsigned short
//         // Address family - (2 bytes) holds the family and
//         sa_family;
//     char
//         // Holds port (2 bytes), IP address (4 bytes), and 8 bytes of unused chars.
//         sa_data[14];
// };

// struct sockaddr_in
// {
//     short sin_family;        // Address family
//     unsigned short sin_port; // Port number
//     struct in_addr sin_addr; // Internet (IP) address
//     unsigned char sin_zero[8];
// };

// struct in_addr
// {
//     unsigned long s_addr; // The 32 bit IP address
// };

// struct sockaddr_in myaddr;
// int s;
// myaddr.sin_family = AF_INET;
// myaddr.sin_port = htons(3490); // host to network short
// inet_aton("63.161.169.137", &myaddr.sin_addr.s_addr);
// //inet_aton:: convert from a struct in_addr to a string in dots-and-numbers
// s = socket(PF_INET, SOCK_STREAM, 0);
// bind(s, (struct sockaddr*)myaddr, sizeof(myaddr));