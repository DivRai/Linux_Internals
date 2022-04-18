#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main()
{
	char *r,*p;
	int id;
	id=shmget(50,260,IPC_CREAT|0644);
	if(id<0)
	{
		perror("shmget");		// POSIX error. stderr device
		return 0;
	}
	
	printf("ID = %d\n",id);
	r = shmat(id,0,0);
	printf("%s\n",r);
	//shmdt(r);
	//printf("%s\n",r);	After detach will not be able to access 
	return 0;
	
	
}
