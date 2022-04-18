#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd, len;
	int x;
	char write_buf[50]="Linux kernel file program";
	char read_buf[50];

	fd = open("linux_kernel.txt",O_CREAT | O_RDWR,0777);
	
	len = write(fd,write_buf,50);

	printf("return value from write optn = %d\n",len);

	lseek(fd,-2,SEEK_END);

	read(fd,read_buf,len);

	printf("data from buffer(read optn) = %s\n",read_buf);
	
	close(fd);
	return 0;
}
