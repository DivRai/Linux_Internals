#include<stdio.h>
#include<stdio.h>
#include<pthread.h>

int sv=5;

void *thread_mul(void *arg) 
{
	sv*=5;
	printf("Value of shared variable after multiplication with 5 = %d\n\n",sv);
}

void *thread_div(void *arg)
{
	sv/=5;
	printf("Value of shared variable after division with 5 = %d\n\n",sv);
}

int main()
{
	pthread_t thd1,thd2;
	
	printf("Initial value of shared variable = %d\n\n",sv);
	
	pthread_create(&thd1,NULL,thread_mul,NULL);
	pthread_create(&thd2,NULL,thread_div,NULL);

	pthread_join(thd1,NULL);
	pthread_join(thd2,NULL);

	printf("Final value of shared variable = %d\n",sv);
	return 0;
}
