#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>


int main()
{
	int qid;
	struct msqid_ds buf;
	qid = msgget(32,IPC_CREAT|0644);
	printf("Qid = %d\n",qid);
	msgctl(qid,IPC_STAT,&buf);
	printf("Here are the details of the queue:\n");
	printf("No of msgs in q is %li\n",buf.msg_qnum);
	printf("Max no of bytes in q is %li\n",buf.msg_qbytes);
	
	return 0;
}
