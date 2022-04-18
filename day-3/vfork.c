#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	pid_t pid;
	printf("Current process pid = %d\n",getpid());

	pid = vfork();

	if(pid)
	{
		printf("Parent process pid = %d\n",getpid());
	}
	else
	{
		sleep(5);
		printf("child process pid = %d\n", getpid());
	}
	exit(0);
	return 0;
}
