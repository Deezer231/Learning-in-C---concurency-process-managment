#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
char buffer[10];
char name [10];
int fd, n;
printf("what would you like to print?\n");
scanf("%s", name);
fd = open(name,O_RDONLY);
do {
n=read(fd, buffer, 10); /*Read 10 chars from file*/
write(1, buffer, n); /*Write chars to text terminal*/
} while (n==10); /* keep reading until n < 10 */
close(fd);
printf("\n");
}
