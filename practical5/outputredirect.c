
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

if (access ("fifo", F_OK) == -1) /*doesn’t exist */
if (mknod("fifo", 010600, 0) == 0)
printf("fifo Pipe created successfully \n");
else {
printf("Failed to create fifo Pipe \n");
exit(0); /* Program terminates */
}
else
printf("Using existing named pipe \n");

open("fifo",O_WRONLY);
close(1);
dup(3);

printf("David\n");
}
