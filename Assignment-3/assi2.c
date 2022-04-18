#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

pthread_t thd;

void *printPattern()
{
	printf("\nThread printing pattern\n");
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	thdCancel();
	while(1);
}

void thdCancel()
{
	int rt=0;
	printf("\nThread cancelling itself\n");
	thd = pthread_self();
	printf("Thread ID: %lu\n",thd);
	rt = pthread_cancel(thd);
	if(rt==0)
		printf("\nThread cancelled itself");
}

int main()
{
	int rc;
	printf("Thread is created inside main\n");
	rc = pthread_create(&thd,NULL,printPattern,NULL);
	printf("Thread ID: %lu\n",thd);
	sleep(2);
}
