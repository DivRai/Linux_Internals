#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

#define KEY 32

int main()
{
	char *p;
	int id;
	id = shmget(KEY, 250, IPC_CREAT|0644);
	if(id<0)
	{
		perror("shmget");
		return 0;
	}
	printf("id = %d\n", id);
	
	//Attaching
	p = shmat(id, 0, 0);
	printf("Data read from the SM: %s\n", p);
	shmdt(p);
	return 0;
}


