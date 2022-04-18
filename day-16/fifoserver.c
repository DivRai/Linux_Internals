#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{
	printf("Server - listening\n");
	
	// Create fifo
	int code = mkfifo("cli_ser_fifo",0764);
	if(code==-1)
		perror("mkfifo returned an error - file may already exist\n");
		
	// Open read end
	int fd = open("cli_ser_fifo",O_RDONLY);
	if(fd==-1)
	{
		perror("Cannot open FIFO for read\n");
		return 0;
	}
		
	printf("FIFO OPEN\n");
	
	// Read string (upto 100 characters)
	char serverrcv[100];		// String buffer
	memset(serverrcv,0,100);	// Set ser buff with zeros
	
	int res;
	char Len;
	while(1)
	{
		res = read(fd,&Len,1);
		if(res==0)
			break;
		read(fd,serverrcv,Len);		// Read string characters
		//serverrcv[(int)Len]=0;	// Zero terminator
		printf("Server received: %s\n",serverrcv);
	}
	
	printf("EOF Reached\n");
	
	close(fd);
	printf("FIFO Closed\n");
	
	return 0;
}
