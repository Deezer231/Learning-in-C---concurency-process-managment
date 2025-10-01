#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
int fdptr[2], n, buffersize=21;
char strbuff[buffersize+1];
char message[] = "Welcome to Unix pipes";
int pid;
pid = fork(); /* create a child process */

if (pid == 0) {
while (true) {
n = read(fdptr[0], strbuff, buffersize);
/* read from the pipe into strbuff */
strbuff[n]=0;
printf("Child read: %s\n", message);
sleep(5); /* sleep for 5 seconds */
}
}
else {
while (true) {
printf("Parent writing: %s\n", message);
write(fdptr[1], message, strlen(message));/* write message into the pipe */
sleep(5); /* sleep for 5 seconds */
}
}
}
