#include<pthread.h>
#include<stdio.h>

void *my(void *i)
{
	printf("\nI am in %d thread\n",(int *)i);
}

void main()
{
	pthread_t pid;
	struct sched_param param;
	int priority,policy,ret;
	/* scheduling parameters of target thread */
	ret = pthread_getschedparam(pthread_self(),&policy,&param);
	if(ret!=0)
		perror("getschedparam");
	printf("\n---------Main Thread---------\nPolicy : %d \tPriority : %d\n",policy,param.sched_priority);
	policy = SCHED_FIFO;	
	param.sched_priority = 3;
	ret = pthread_setschedparam(pthread_self(),policy,&param);
	if(ret!=0)
		perror("getschedparam");
	ret = pthread_getschedparam(pthread_self(),&policy,&param);
	if(ret!=0)
		perror("getschedparam");
	printf("\n---------Main Thread---------\nPolicy : %d \tPriority : %d\n\n",policy,param.sched_priority);
}

// run this program using sudo ./a.out
