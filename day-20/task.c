// Write a signal handler program that generates a SIGINT signal and handler tells which signal received

/* My program
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sighand(int signum)
{
	printf(" I am in signal handler of signal %d\n",signum);
}

void main()
{
	signal(SIGINT,sighand);
	while(1);
}

// After running the program press ctrl c*/


// Sir's program
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sighand(int signal)
{
	printf("Interrupt signal received..but no termination on ctrl+c\n");
	if(signal==SIGINT)
		printf("Received a SIGINT signal\n");
		
	exit(0);
}

void main()
{
	int i;
	signal(SIGINT,sighand);
	for(i=0;;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
}
