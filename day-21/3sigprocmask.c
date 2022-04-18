// Use kill command to kill the running executable

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

// Iterates through a list of signals and prints out which signals are in a signal set
void printSignalSet(sigset_t *set)
{
	const int sigList[] = { SIGHUP,SIGINT,SIGQUIT,SIGILL,SIGABRT,SIGFPE,SIGKILL,SIGSEGV };	
	const char *sigNames[] = { "SIGHUP","SIGINT","SIGQUIT","SIGILL","SIGABRT","SIGFPE","SIGKILL","SIGSEGV" };
	const int sigLen=8;

	for(int i=0;i<sigLen;i++)
	{
		int ret=sigismember(set,sigList[i]);
		if(ret==-1)
		{
			perror("sigismemeber:");
			exit(EXIT_FAILURE);
		}
		else if(ret==1)
			printf("Signal %s=%d is in the set.\n",sigNames[i],sigList[i]);
		else
			printf("Signal %s=%d is not in the set.\n",sigNames[i],sigList[i]);
	}
}

void main()
{
	sigset_t set;
	
	if(sigprocmask(0,NULL,&set)!=0)
	{
		perror("sigprocmask:");
		exit(EXIT_FAILURE);
	}
	
	printf("--- Initial signal mask for this process: ---\n");
	printSignalSet(&set);
	
	if(sigaddset(&set,SIGINT)!=0)	// Add SIGINT to our set
	{
		perror("sigaddset:");
		exit(EXIT_FAILURE);
	}
	
	// Tell OS that we want to mask our new set of signals---which now includes SIGINT.
	if(sigprocmask(SIG_SETMASK,&set,NULL)!=0)
	{
		perror("sigprocmask:");
		exit(EXIT_FAILURE);
	}
	
	// Now, SIGINT will be "blocked".
	printf("\n--- NEW signal mask for this process: ---\n");
	printSignalSet(&set);
	
	int secToSleep=20;
	printf("\nTry Ctrl+C. Try killing this program with 'kill -kill %d'. Going to sleep for %d seconds.\n",getpid(),secToSleep);
	sleep(secToSleep);
	printf("\nSleep returned.\n");
	
	printf("\nRemoving all signals from mask.\n");
	
	sigfillset(&set);
	
	sigprocmask(SIG_SETMASK,&set,NULL);
	
	printSignalSet(&set);
	
	sleep(1);
	printf("Exited normally.\n");
}
