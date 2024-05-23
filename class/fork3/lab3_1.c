
#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
int fd;
char buffer[80];
static char message[] = "Hello, world";
fd = open("myfile",O_RDWR|O_CREAT |O_TRUNC);
//fd returns  -1 val if unsuccessful
if (fd != -1)
{
printf("myfile opened for read/write access\n");

//fd, message string, write inside file
write(fd, message, sizeof(message));
lseek(fd, 0, SEEK_SET); /* go back to the beginning of the file */
read(fd, buffer, sizeof(message));
printf("%s was written to myfile \n", buffer);
close (fd);
}

}