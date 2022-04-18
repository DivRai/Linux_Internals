// Thread program 1

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

	pthread_join(tid,NULL);
	return 0;
}
