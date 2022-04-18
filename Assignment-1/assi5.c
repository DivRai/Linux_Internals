#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int fd, len;
	int x;
	char write_buf[4096]="";

	fd = open("file5.txt",O_CREAT | O_RDWR,0777);

	len = write(fd,write_buf,4096);

	printf("return value from write optn = %d\n",len);
}

	
