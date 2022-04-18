#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *printHello(void *thread)
{
	printf("\nHello World");
	while(1);
}

int main()
{
	pthread_t thread;
	int rc,t=0;
	printf("Creating thread\n");
	rc = pthread_create(&thread,NULL,printHello,NULL);
	printf("\nThread ID: %u",thread);
	sleep(6);
	t = pthread_cancel(thread);
	if(t==0)
		printf("\ncanceled thread\n");
	printf("\n Thread ID : %u\n",thread);
}
