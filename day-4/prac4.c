#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	int pid, status;

	printf("Parent: %d\n",getpid());

	pid=fork();
	if(pid==0)
	{
		printf("Child: %d\n",getpid());
		sleep(2);
	
		exit(0);
	}
		printf("parent reporting exit of child whose pid = %d\n",waitpid(pid,&status,0));
	return 0;
}
