/*********************/
/*   Elijah Bowlby   */
/*   CSCI 3550       */
/*   HW 4            */
/*   headerFile.h    */
/*   10/21/2022      */
/*********************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#ifdef _WIN32
// For Windows
int betriebssystem = 1;
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <ws2def.h>
#pragma comment(lib, "Ws2_32.lib")
#include <windows.h>
#include <io.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/wait.h>
int betriebssystem = 2;
#endif

struct sockaddr
{
    unsigned short
        // Address family - (2 bytes) holds the family and
        sa_family;
    char
        // Holds port (2 bytes), IP address (4 bytes), and 8 bytes of unused chars.
        sa_data[14];
};

struct sockaddr_in
{
    short sin_family;        // Address family
    unsigned short sin_port; // Port number
    struct in_addr sin_addr; // Internet (IP) address
    unsigned char sin_zero[8];
};

struct in_addr
{
    unsigned long s_addr; // The 32 bit IP address
};