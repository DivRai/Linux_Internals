#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int a[2];
	pipe(a);
	// Read end a[0]
	// Write end a[1]
	
	if(fork())
	{
		char wbuf[20];
		printf("Inside parent process...\n");
		printf("Enter data: ");
		scanf("%s",wbuf);
		write(a[1],wbuf,sizeof(wbuf));
		wait(0);
	}
	else
	{
		char rbuf[20];
		sleep(5);
		printf("\nInside child process...\n");
		read(a[0],rbuf,sizeof(rbuf));
		printf("Child process displaying data entered by the parent process..\n");
		printf("%s\n",rbuf);
	}
	return 0;
}
