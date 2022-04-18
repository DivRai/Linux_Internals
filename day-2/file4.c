#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd;
	int res;
	char buf[300];

	fd = open("file1.c",O_CREAT | O_RDWR,777);
	
	printf("%d\n",fd);
	if(fd<0)
		printf("File is not opened or created\n");
	read(fd,buf,300);
	printf("data from buffer = %s\n",buf);
	close(fd);

	return 0;
}
