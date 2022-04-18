#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sighand(int signum)
{
	printf("Interrupt signal received...but no termination on ctrl+c\n");
}

int main()
{
	int i;
	signal(SIGINT,sighand);
	signal(SIGINT,SIG_DFL);		// Used to nullify the effect of sighand
	
	for(i=0;;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
}
