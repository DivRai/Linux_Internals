#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	pid_t pid1;
	pid1 = fork();

	if(pid1==0)
	{
		sleep(5);
		printf("\nI am child with delay of 5 sec and my child pro pid = %d\n",getpid());
		execl("/bin/ls","ls",NULL);
		sleep(5);
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
