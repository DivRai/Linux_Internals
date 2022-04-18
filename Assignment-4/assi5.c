#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

volatile int slck;

void *splckThread()
{
	int rc;
	printf("\n----------  THREAD TASK  ----------\n");
	printf("Acquiring spin lock\n");
	rc = pthread_spin_lock(&slck);
	
	printf("\n----------  THREAD TASK  ----------\n");
	printf("Thread going to unlock the spin lock\n");
	rc = pthread_spin_unlock(&slck);

	printf("Thread task finished\n");
	return NULL;
}
 
int main()
{
	int rc=0;
	pthread_t thread,thread1;

	if(pthread_spin_init(&slck,PTHREAD_PROCESS_PRIVATE)!=0)
		perror("init");
	printf("----------  MAIN FUNCTION  ----------\n");
	printf("Acquiring spin lock\n");
	rc = pthread_spin_lock(&slck);

	printf("Creating the spin lock thread\n");
	rc = pthread_create(&thread,NULL,splckThread,NULL);

	printf("Waiting holding the spin lock\n");
	sleep(2);
	
	printf("\n----------  MAIN FUNCTION  ----------\n");
	printf("Inside main, unlocking the spin lock\n");
	rc = pthread_spin_unlock(&slck);
	if(rc==0)
		printf("Thread successfully unlocked\n");
	else
		printf("Thread unsuccessfully unlocked\n");
	
	printf("Waiting for the thread to end\n");
	rc = pthread_join(thread,NULL);
	rc = pthread_spin_destroy(&slck);
	printf("\n----------  MAIN FUNCTION  ----------\n");
	printf("Main finished\n");

	return 0;
}
