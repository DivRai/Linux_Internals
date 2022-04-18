#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>


int main()
{
	int qid;
	struct msqid_ds buf;
	qid = msgget(49,IPC_CREAT|0644);
	printf("Qid = %d\n",qid);
	msgctl(qid,IPC_RMID,NULL);
	
	return 0;
}
