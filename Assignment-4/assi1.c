#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t id;

void *thd(void *arg)
{
	sleep(2);
	printf("\n----------  THREAD TASK  ----------\n");
	printf("Thread printing pattern\n");
	for(int i=5;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return NULL;
}

int main()
{
	printf("----------  MAIN FUNCTION  ----------\n");
	
	int ret = pthread_create(&id,NULL,thd,NULL);
	if(ret)
		printf("Thread not created\n");
	else
		printf("Thread created\n");
	
	printf("\nMain Function Exit\n");
	pthread_exit(NULL);
	
	return 0;
}
