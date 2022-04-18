#include<stdio.h>
#include<unistd.h>

void main()
{
	printf("Parent process\n");

	fork();
	fork();
	printf("Child process\n");	

	while(1);
}
