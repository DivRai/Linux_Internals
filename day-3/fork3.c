#include<stdio.h>
#include<unistd.h>

int main(void)
{
	int pid1;
	printf("Current process pid = %d\n",getpid());

	pid1 = fork();

	if(pid1==0)
	{
		printf("New child process pid = %d\n",getpid());
		printf("New child parent process ppid = %d\n",getppid());
	}
	else
	{
		sleep(3);
		printf("parent process pid = %d\n",getpid());
		printf("parents parent process ppid = %d\n",getppid());
	}
	while(1);
	return 0;
}
