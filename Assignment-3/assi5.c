#include<stdio.h>
#include<stdio.h>
#include<pthread.h>

int sv=5;

pthread_mutex_t mm;		

void *thread_mul(void *arg)
{
	pthread_mutex_lock(&mm);
	printf("\nApplied lock to shared variable...\n");
	sv*=5;
	printf("Value of shared variable after multiplication with 5 = %d",sv);
	pthread_mutex_unlock(&mm);
	printf("\nApplied unlock to shared variable...\n");
}

void *thread_div(void *arg)
{
	pthread_mutex_lock(&mm);
	printf("\nApplied lock to shared variable...\n");
	sv/=5;
	printf("Value of shared variable after division with 5 = %d",sv);
	pthread_mutex_unlock(&mm);
	printf("\nApplied unlock to shared variable...\n");
}

int main()
{
	pthread_t thd1,thd2;
	
	printf("Initial value of shared variable = %d\n",sv);

	pthread_mutex_init(&mm,NULL);
	
	pthread_create(&thd1,NULL,thread_mul,NULL);
	pthread_create(&thd2,NULL,thread_div,NULL);

	pthread_join(thd1,NULL);
	pthread_join(thd2,NULL);

	printf("\nFinal value of shared variable = %d\n",sv);
	return 0;
}
