#include<pthread.h>
#include<stdio.h>

void main()
{
	struct sched_param param;
	int pri,pol,r;
	/* scheduling parameters of target thread */
	r = pthread_getschedparam(pthread_self(),&pol,&param);

	printf("\n Main Thread Old Parameters \nPolicy : %d \tPriority : %d\n",pol,param.sched_priority);
	pol = SCHED_FIFO;	
	param.sched_priority = 2;
	r = pthread_setschedparam(pthread_self(),pol,&param);
	
	r = pthread_getschedparam(pthread_self(),&pol,&param);
	
	printf("\n Main Thread New Parameters \nPolicy : %d \tPriority : %d\n\n",pol,param.sched_priority);
}
