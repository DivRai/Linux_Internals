// Mutex implementation

#include<stdio.h>
#include<stdio.h>
#include<pthread.h>

int sharedVar=5;

pthread_mutex_t my_mutex;		// Declaring mutex variable

void *thread_inc(void *arg)
{
	pthread_mutex_lock(&my_mutex);		// Take mutex
	sharedVar++;
	printf("after incr = %d\n",sharedVar);
	pthread_mutex_unlock(&my_mutex);	// Release mutex
}

void *thread_dec(void *arg)
{
	pthread_mutex_lock(&my_mutex);		// Take mutex
	sharedVar--;
	printf("after decr = %d\n",sharedVar);
	pthread_mutex_unlock(&my_mutex);	// Release mutex
}

int main()
{
	pthread_t thread1,thread2;

	pthread_mutex_init(&my_mutex,NULL);	// Initialize mutex
	
	pthread_create(&thread1,NULL,thread_inc,NULL);
	pthread_create(&thread2,NULL,thread_dec,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("sharedVar = %d\n",sharedVar);
	return 0;
}
