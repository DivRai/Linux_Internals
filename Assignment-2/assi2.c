#include<stdio.h>
#include<unistd.h>

int main()
{
	int child1, child2;
	printf("Current process pid = %d\n",getpid());

	child1 = fork();

	if(child1==0)
	{
		sleep(2);
		printf("\nChild 1 process pid = %d\n",getpid());
		printf("Child 1 parent process ppid = %d\n",getppid());
	}
	else
	{
		child2 = fork();
		if(child2==0)
		{
			sleep(2);
			printf("\nChild 2 process pid = %d\n",getpid());
			printf("Child 2 parent process ppid = %d\n",getppid());
		}
		else
		{		
			printf("Parent process pid = %d\n",getpid());
		}
	}
	while(1);
	return 0;
}
