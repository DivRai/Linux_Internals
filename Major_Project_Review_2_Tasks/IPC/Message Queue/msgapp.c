// Messaging Application

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

typedef struct
{
	long msgtype;
	char buffer[100];
}msg;

int main()
{
	int qid,i;
	msg m1;
	
	qid=msgget(32,IPC_CREAT|0644);
	
	m1.msgtype=10;
	printf("Enter message to be transmitted: ");
	fgets(m1.buffer,100,stdin);
	
	i=msgsnd(qid,&m1,sizeof(msg),0);
	printf("\nReturn value of msgsnd = %d\n",i);
	
	i = msgrcv(qid,&m1,sizeof(msg),10,0);
	printf("\nReceived message: ");
	printf("%s",m1.buffer);	

	return 0;	
}
