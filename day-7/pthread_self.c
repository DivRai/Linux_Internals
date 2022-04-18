#include<stdio.h>
#include<string.h>
#include<pthread.h>

struct my_thread
{
	int thread_ID;
	char mesg[100];
};

void *printHello(void *threadobj)
{
	pthread_t thread_ID;
	struct my_thread *t1;
	t1 = (struct my_thread *) threadobj;
	thread_ID = pthread_self();
	printf("\nThread ID : %lu",thread_ID);
	printf("\n%d Thread Message : %s\n",t1->thread_ID,t1->mesg);
}

int main()
{
	pthread_t thread2,thread3,thread4,thread_ID;
	int rc;
	struct my_thread t2,t3,t4;
	t4.thread_ID=4;
	strcpy(t4.mesg,"I am Fourth thread\n");
	t2.thread_ID=2;
	strcpy(t2.mesg,"I am Second thread\n");
	t3.thread_ID=3;
	strcpy(t3.mesg,"I am Third thread\n");
	
	thread_ID = pthread_self();
	printf("\nMAIN Thread ID : %lu",thread_ID);
	
	pthread_create(&thread4,NULL,printHello,(void *)&t4);
	pthread_create(&thread2,NULL,printHello,(void *)&t2);
	pthread_create(&thread3,NULL,printHello,(void *)&t3);
	
	printf("\nExit from main thread\n");
	pthread_exit(NULL);
}
