#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static void* threadFunc(void *arg)
{
	char *s = (char *) arg;
	printf("%s\n",s);
	return 0;
}

int main(int argc, char *argv[])
{
	pthread_t t1;
	void *res;
	int s;

	pthread_create(&t1,NULL,threadFunc,"Hello World");
	/*s = pthread_create(&t1,NULL,threadFunc,"Hello World");
	if(s != 0)
	{	
		printf("pthread_create error %d\n",s);
		return;
	}*/
	
	printf("Messages from main()\n");
	
	sleep(3);

	exit(0);
}
