// pthread_exit function program

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

pthread_t tid;

void *thread1(void *arf)
{
	printf("Newly created thread is executing\n");
	return NULL;
}

int main()
{
	int ret = pthread_create(&tid,NULL,thread1,NULL);
	if(ret)
		printf("Thread is not created\n");
	else
		printf("Thread is created\n");

	/* There may be pending requests at this point */
	/* Just exit the main thread/process - not the whole program - so that remaining
	requests that may still be processed can continue. */
	pthread_exit(NULL);
	return 0;
}
