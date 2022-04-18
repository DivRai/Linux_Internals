// Messaging Application

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

typedef struct
{
	long msgtype;
	char buffer[20];
}msg;

int main()
{
	int qid,i;
	msg m1;
	
	qid=msgget(32,IPC_CREAT|0644);
	
	printf("Sent message: ");
	m1.msgtype=10;
	for(i=0;i<20;i++)
	{
		m1.buffer[i]='a';
		printf("%c",m1.buffer[i]);
	}
	
	i=msgsnd(qid,&m1,sizeof(msg),0);
	printf("\n\nReturn value of msgsnd of As = %d\n",i);
	
	i = msgrcv(qid,&m1,sizeof(msg),10,0);
	printf("\nReceived message: ");
	for(i=0;i<20;i++)
		printf("%c",m1.buffer[i]);
		
	printf("\n");	

	return 0;	
}
