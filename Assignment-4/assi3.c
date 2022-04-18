#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *init()
{
	printf("\nInitialized thread\n");
}

void *thdTask(void *i)
{
	printf("Created thread\n");
	pthread_once(&once,(void *)init);
	printf("\nExit from thread task function\n");
}

int main()
{
	pthread_t thread;
	pthread_create(&thread,NULL,thdTask,NULL);
	sleep(2);
	
	printf("\nExit from main thread\n");
	pthread_exit(NULL);
}
