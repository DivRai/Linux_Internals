#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

typedef struct
{
	long msgtype;
	char data[256];
}msg;

int main()
{
	msg m1,m2;
	struct msqid_ds buf;
	int i,id,ret;
	
	id=msgget(37,IPC_CREAT|0644);		
	printf("Message queue id = %d\n",id);

	m1.msgtype=37;		
	for(i=0;i<256;i++)
		m1.data[i]='c';	
		
	m2.msgtype=78;
	for(i=0;i<256;i++)
		m2.data[i]='h';
	
	msgsnd(id,&m1,sizeof(msg),0);
	msgsnd(id,&m2,sizeof(msg),0);	
	
	msgctl(id,IPC_STAT,&buf);
	printf("\n------ Message Queue Details ------\n");
	printf("\nNumber of messages in queue is %li\n",buf.msg_qnum);
	printf("\nCurrent no of bytes in queue is %li\n",buf.msg_cbytes);
	printf("\nMax no of bytes in queue is %li\n",buf.msg_qbytes);
	printf("\nRemoving message queue...\n");
	ret=msgctl(id,IPC_RMID,NULL);
	if(!ret)
		printf("Message queue removed\n");	
	return 0;
}
