#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1,fd2,maxfds;
	fd1 = open("file1.c",O_WRONLY,777);
	printf("%d\n",fd1);

	fd2 = open("file.txt",O_CREAT | O_RDWR,777);
	printf("%d\n",fd2);

	maxfds = getdtablesize();
	printf("%d\n",maxfds);

	close(fd1);
	close(fd2);
}
