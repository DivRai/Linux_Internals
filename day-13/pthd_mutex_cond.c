#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

// Declaration of thread condition variable
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

// Declaring mutex
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int done=1;

// Thread function
void *foo(void *arg)
{
	char *str = (char *)arg;
	printf("Thread task called by = %s\n",str);
	
	// acquire a lock
	pthread_mutex_lock(&lock);
	if(done==1)
	{
		// let's wait on condition variable cond1
		printf("Waiting on condition variable cond1\n");
		pthread_cond_wait(&cond1,&lock);
	}
	else
	{
	// let's signal condition variable cond1
	printf("Signaling condition variable cond1\n");
	pthread_cond_signal(&cond1);
	}
	
	// release lock
	pthread_mutex_unlock(&lock);
	
	printf("Returning thread\n");
	
	return NULL;
}

// Driver code
int main()
{
	pthread_t tid1,tid2;
	
	// Create thread 1
	pthread_create(&tid1,NULL,foo,"THDone");

	// sleep for 1 sec so that thread 1 would get chance to run first
	sleep(1);
	
	// let's wait on condition variable cond1
	
	done=2;	
	
	// Create thread 2
	pthread_create(&tid2,NULL,foo,"THDtwo");
	
	// wait for completion of thread 2
	pthread_join(tid2,NULL);
	
	return 0;
}