#include<stdio.h>
#include<string.h>
#include<pthread.h>

struct my_thd
{
	int thd_id;
	char msg[100];
};

void *thdTask(void *thdobj)
{
	pthread_t thd_id;
	struct my_thd *t1;
	t1 = (struct my_thd *) thdobj;
	thd_id = pthread_self();
	printf("\n------- THREAD TASK -------\n");
	printf("Thread ID : %lu",thd_id);
	printf("\n\n----- Thread Structure Info -----\n");
	printf("Thread ID: %d\n",t1->thd_id);
	printf("Thread Message: %s\n",t1->msg);
}

int main()
{
	pthread_t thd1,thd_id;
	int rc;
	struct my_thd t1;
	
	t1.thd_id=55;
	strcpy(t1.msg,"I am First thread");
	
	thd_id = pthread_self();
	printf("-------- MAIN TASK -------\n");
	printf("Thread ID: %lu",thd_id);
	
	pthread_create(&thd1,NULL,thdTask,(void *)&t1);
	
	printf("\nExit from main thread\n");
	pthread_exit(NULL);
}
