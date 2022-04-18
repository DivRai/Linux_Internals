#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
	int fd1,fd3;
	fd1 = open("linux.txt",O_WRONLY|O_CREAT,777);

	fd3 = fcntl(fd1,F_DUPFD); 	// F-DUPFD = Duplicating file descriptor

	printf("duplicate value of fd1 is fd3 = %d\n",fd3);

	close(fd1);
	close(fd3);
}
