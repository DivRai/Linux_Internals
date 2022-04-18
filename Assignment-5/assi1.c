#include<stdio.h>
#include<sys/shm.h>

int main()
{
	char *ptr;
	int ID;
	ID = shmget(37,500,IPC_CREAT|0644);
	if(ID<0)
	{
		printf("Cannot create shared memory region\n");
		return 0;
	}
	else
	{
		printf("Shared memory region successfully created\n");
		printf("\nShared memory ID = %d\n",ID);
		printf("\nShared memory address = %p\n",shmat(ID,NULL,0));
		
	}
	shmdt(ptr);
	return 0;
	
	
}
