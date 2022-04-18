#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void *Proc(void *param)
{
	sleep(2);
	return 0;
}
int main()
{
	pthread_attr_t Attr;
	pthread_t Id;
	void *Stk;
	size_t Siz;
	int err;
		
	size_t my_stksize = 20000;
	
	void *my_stack;

	pthread_attr_init(&Attr);

	pthread_attr_getstacksize(&Attr,&Siz);
	pthread_attr_getstackaddr(&Attr,&Stk);

	printf("Default stack: Addr=%08x default size = %ld\n",Stk,Siz); 

	my_stack = (void *)malloc(my_stksize);

	printf("MALLOC checking: Addr=%08x and Size=%ld\n",my_stack,my_stksize);

	pthread_attr_setstack(&Attr,my_stack,my_stksize);

	pthread_create(&Id,&Attr,Proc,NULL);

	pthread_attr_getstack(&Attr,&Stk,&Siz);

	printf("Newly defined stack: Addr=%08x and Size=%ld\n",Stk,Siz);

	return(0);

}

