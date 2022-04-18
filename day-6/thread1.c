//pthread_detach function program

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *process(void *arg)
{
	pthread_detach(pthread_self());

	printf("sleeping 2 secs\n");

	sleep(2);
	printf("slept 2 secs\n");
}

int main(void)
{
	pthread_t tid;
	int errno = pthread_create(&tid,NULL,process,NULL);
	if(errno) perror("pthread_create:");

	pthread_exit(NULL);
}
