#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

#define MAXPENDING 5
#define RCVBUFSIZE 32 /* Maximum outstanding connection requests */

int main(int argc, char *argv[])
{
int servSock;
int clntSock;
struct sockaddr_in echoServAddr;
struct sockaddr_in echoClntAddr;
unsigned short echoServPort;
unsigned int clntLen;
char echoBuffer[RCVBUFSIZE];
int recvMsgSize;
char *echoString;
unsigned int echoStringLen;

echoString = "server is alive, how are you?"; /* Server's reply to client */
echoStringLen = 29;
echoServPort = 8093; /* local port on which server is going to listen */

/* Create local TCP/IP socket for incoming connections */
servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

/* Construct local address structure */
memset(&echoServAddr, 0, sizeof(echoServAddr));
echoServAddr.sin_family = AF_INET;
echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
echoServAddr.sin_port = htons(echoServPort);

bind(servSock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr));

listen(servSock, MAXPENDING);
for (;;) /* Run forever */
{
/* Set the size of the in-out parameter */
clntLen = sizeof(echoClntAddr);

/* Blocking wait for a client to connect */
clntSock = accept(servSock, (struct sockaddr *) &echoClntAddr,&clntLen);

/* clntSock is connected to a client! */
printf("Server: Handling client %s\n",inet_ntoa(echoClntAddr.sin_addr));

/* Receive message from client */
recvMsgSize = recv(clntSock, echoBuffer, RCVBUFSIZE, 0);
printf("Server: Received msg-> %s\n",echoBuffer);

/* Send response message back to client */
send(clntSock, echoString, echoStringLen, 0);
printf("Server: Sent Reply-> %s\n",echoString);
close(clntSock);/* Close client socket */
}
}

