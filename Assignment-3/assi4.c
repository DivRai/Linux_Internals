#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t thdid;

void *thdTsk(void *arg)
{
	pid_t proid;
	proid = getpid();
	thdid = pthread_self();
	printf("Thread task printing thread id and calling process id...\n");
	printf("Calling process ID: %d\n",proid);
	printf("Thread ID: %lu\n",thdid);
	return 0;
}

int main(void)
{
	pthread_create(&thdid,NULL,thdTsk,NULL);
	sleep(2);
	exit(0);
}
