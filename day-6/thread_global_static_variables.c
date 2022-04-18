#include<stdio.h>
#include<stdio.h>
#include<pthread.h>

int sharedVar=5;

void *thread_inc(void *arg) 	// Critical section
{
	sharedVar++;
	printf("after incr = %d\n",sharedVar);
}

void *thread_dec(void *arg)	// Critical section
{
	sharedVar--;
	printf("after decr = %d\n",sharedVar);
}

int main()
{
	pthread_t thread1,thread2;
	
	pthread_create(&thread1,NULL,thread_inc,NULL);
	pthread_create(&thread2,NULL,thread_dec,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("sharedVar = %d\n",sharedVar);
	return 0;
}
