#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1,fd2,len;
	int x;
	char read_buf[11];

	fd1 = open("file1_1.txt",O_RDWR,777);
	fd2 = creat("file1_2.txt",777);

	read(fd1,read_buf,11);

	write(fd2,read_buf,11);

	close(fd1);
	close(fd2);
	return 0;
}
