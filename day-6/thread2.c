// implement detachable thread

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define NUM_THREADS 3

int i=0;
void *myfun(void *null)
{
	i++;
	int result=0;
	result += i*1000;
	printf("result = %d\n",result);

	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread[NUM_THREADS];
	pthread_attr_t attr;
	int rc,t,status,detach_state;

	/* Initialize and set thread detached attribute */

	pthread_attr_init(&attr);

	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	for(t=0;t<NUM_THREADS;t++)
	{
		printf("Creating thread %d\n",t);
		pthread_create(&thread[t],&attr,myfun,NULL);
	}

	pthread_attr_getdetachstate(&attr,&detach_state);
	printf("\nDetach state : %d\n",(int *)detach_state);

	printf("\nExiting from main thread\n");
	pthread_exit(NULL);
}
