#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	pid_t pid1;

	int pid2;
	printf("I am parent pro pid = %d\n",getpid());
	pid2 = wait(0);


	printf("parent saying child %d terminated normally\n",pid2);
	printf("I am parent process pro pid = %d\n",getpid());
	return 0;
}
