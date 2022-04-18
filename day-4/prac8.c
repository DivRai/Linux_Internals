#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	pid = fork();

	if(pid<0)	// No process creation
	{
		fprintf(stderr,"Fork Failed");
		exit(-1);
	}
	else if(pid==0)
	{
		execl("/bin/ls","ls",NULL);
	}
	else
	{
		wait(0);
		printf("\nChild Complete\n");
		exit(0);
	}
}
