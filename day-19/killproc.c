#include<sys/types.h>
#include<signal.h>
#include<stdio.h>

int main()
{
	pid_t pid;
	int sig_no;
	printf("Entedr the pid of the process for which the signal need to be sent: ");
	scanf("%d",&pid);
	printf("Enter the signal that need to be sent: ");	// Enter 2 as signal number
	scanf("%d",&sig_no);
	kill(pid,sig_no);
	perror("Sig_res");
}
