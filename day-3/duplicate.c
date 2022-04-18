#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
	int fd1,fd2,fd3,fd4;
	fd1 = open("linux.txt",O_WRONLY|O_CREAT|O_TRUNC,777);
	fd2 = open("linuxnew.txt",O_WRONLY|O_CREAT|O_TRUNC,777);
	printf("fd1 = %d\n",fd1);
	printf("fd2 = %d\n",fd2);

	fd3 = dup(fd1);
	printf("fd3(dup of fd1) = %d\n",fd3);

	fd4 = dup2(fd2,8);
	printf("fd4(dup of fd2) = %d\n",fd4);

	close(fd1);
	close(fd2);
	close(fd3);
}
