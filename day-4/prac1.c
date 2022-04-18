#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	int option;

	
	while(1)
	{
		{
			printf("Enter 1 to exec 'ls' program in child process and 0 to exit\n");
			scanf("%d",&option);
			if(!option)
				exit(0);
			printf("\n");
			if(fork()==0)
			{
				execl("/bin/ls","ls",NULL);
				exit(0);
			}
		}
	}
}
