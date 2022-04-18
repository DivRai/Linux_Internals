// Thread program 3

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void *tt1(void *arg)
{
	int i;
	for(i=0;i<100;i++)
		printf("Thd of con 1\n");
}

void *tt2(void *arg)
{
	int i;
	for(i=0;i<100;i++)
		printf("** Thd of con 2\n");
}

int main()
{
	pthread_t pt1,pt2;
	getchar();	
	pthread_create(&pt1,NULL,tt1,NULL);
	pthread_create(&pt2,NULL,tt2,NULL);
	getchar();
	printf("End of main thread\n");
}
