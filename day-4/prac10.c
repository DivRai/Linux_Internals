// Thread program 2

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

pthread_t tid1;
pthread_t tid2;

void *thread1(void *arf)
{
	printf("Newly created thread 1 is executing\n");
	return NULL;
}

void *thread2(void *arf)
{
	printf("Newly created thread 2 is executing\n");
	return NULL;
}

int main()
{
	int ret1 = pthread_create(&tid1,NULL,thread1,NULL);
	if(ret1)
		printf("Thread 1 is not created\n");
	else
		printf("Thread 1 is created\n");


	int ret2 = pthread_create(&tid2,NULL,thread2,NULL);
	if(ret2)
		printf("Thread 2 is not created\n");
	else
		printf("Thread 2 is created\n");

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
