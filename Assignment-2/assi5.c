#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int fd;
	char read_buf[60];
	pid_t pid1;
	pid1 = fork();

	if(pid1==0)
	{
		sleep(3);
		printf("\nI am child reading a file and with delay of 3 sec and my child pro pid = %d\n",getpid());
		fd = open("file1.txt",O_RDWR,777);
		read(fd,read_buf,50);
		printf("\ndata from buffer = %s\n",read_buf);
		close(fd);
	}
	else
	{
		int pid2;
		printf("I am parent process pid = %d\n",getpid());
		pid2 = wait(0);


		printf("\nparent saying child %d terminated normally\n",pid2);
		printf("\nI am parent process process pid = %d\n",getpid());
	}
	return 0;
}
