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
	msg m1,m2;
	
	qid=msgget(32,IPC_CREAT|0644);
	
	i = msgrcv(qid,&m1,sizeof(msg),10,0);
	for(i=0;i<100;i++)
		printf("%c",m1.buffer[i]);
		
	printf("\n");
	
	m2.msgtype=20;
	for(i=0;i<100;i++)
		m2.buffer[i]='b';
	
	i = msgrcv(qid,&m2,sizeof(msg),20,0);
	for(i=0;i<100;i++)
		printf("%c",m2.buffer[i]);
		
	printf("\n");	

	return 0;	
}
