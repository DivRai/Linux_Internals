#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main()
{
	char *p;
	int id;
	
	id = shmget(50,260,IPC_CREAT|0644);
	
	if(id<0)
	{
		perror("shmget");
		return 0;
	}
	
	printf("ID = %d\n",id);
	p = shmat(id,0,0);		// PAS - User Space
	printf("Enter the data: ");
	scanf("%s",p);
	return 0;
}
