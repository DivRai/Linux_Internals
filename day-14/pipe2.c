#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int fds[2];

/* Let us assume that parent will be writing to pipe and
   child will be reading from the pipe*/

void parent_code()
{
	char *buf1="linuxkernels";
	char *buf="operatingsystem";
	close(fds[0]);
	write(fds[1],buf,15);
	write(fds[1],buf1,13);
	printf("\nEnd of parent\n");
}

void child_code()
{
	char buf[30];
	int n,i;
	close(fds[1]);
	n = read(fds[0],buf,28);
	printf("No. of chars read = %d\n",n);
	for(i=0;i<n;i++)
		printf("%c",buf[i]);
	printf("\nEnd of child\n");
}

void main()
{
	int res,i;
	pid_t p;
	res = pipe(fds);
	
	if(res==-1)
	{
		perror("pipe");
		exit(1);
	}
	p = fork();
	if(p==0)
	{
		child_code();
	}
	else
	{
		
		parent_code();
		while(1);
	}
}
