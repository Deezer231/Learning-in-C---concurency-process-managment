/**************** Client Code ***************/
#include <stdio.h> /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h> /* for sockaddr_in and inet_addr() */
#include <stdlib.h>/* for atoi() and exit() */
#include <string.h>/* for memset() */
#include <unistd.h>/* for close() */

#define RCVBUFSIZE 32/* Size of receive buffer */

int main(int argc, char *argv[])
{
int sock; 
struct sockaddr_in echoServAddr;
unsigned short echoServPort =8093;
char *servIP;
char *echoString;
char echoBuffer[RCVBUFSIZE];
unsigned int echoStringLen;
int bytesRcvd, totalBytesRcvd;

servIP = "127.0.0.1";
echoString = "hello";
echoStringLen = 5;
echoServPort = 8093;

sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

/* Construct the server address structure */
memset(&echoServAddr, 0, sizeof(echoServAddr));
echoServAddr.sin_family = AF_INET;
echoServAddr.sin_addr.s_addr = inet_addr(servIP);
echoServAddr.sin_port = htons(echoServPort);

/* Establish the connection to the server */
connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr));

/* send the message over the socket connection */
send(sock, echoString, echoStringLen, 0);
printf("Client: Sent greeting-> %s\n", echoString);

/* Receive a reply back from the server */
/* Receive up to the buffer size (minus 1 to leave space for
a null terminator) bytes from the sender */
bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0);

echoBuffer[bytesRcvd] = '\0'; /* Terminate the string! */
printf("Client: Received Reply-> %s\n", echoBuffer); /* Print the string received
from server */

close(sock);
exit(0);
}
