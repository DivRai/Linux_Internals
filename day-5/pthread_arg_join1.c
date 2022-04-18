#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

static void* threadFunc(void *arg)
{
	char *s = (char *) arg;
	printf("%s\n",s);
	sleep(5);
	return (void*) strlen(s);
}

int main(int argc, char *argv[])
{
	pthread_t t1;
	void *res;
	int s;

	pthread_create(&t1,NULL,threadFunc,"Hello World");
	
	printf("Messages from main()\n");
	
	//sleep(3);
	pthread_join(t1,&res);	// Extract return code of terminated thread
				// &res is the value that threadFunc is returning

	printf("Thread returned %ld\n",(long)res);
	exit(0);
}
