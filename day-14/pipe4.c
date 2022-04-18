#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
	int p[2];
	pipe(p);
	printf("Read end of pipe = %d\nWrite end of pipe = %d\n",p[0],p[1]);
	
	if(fork())
	{
		char s[20];
		printf("\nIn parent enter data...\n");
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);
		wait(0);
	}
	else
	{
		char buf[20];
		printf("\nIn child...\n");
		read(p[0],buf,sizeof(buf));
		printf("Child pro printing..Data of the parent process..%s\n",buf);
	}
	return 0;
}

/* After fork, parent will execute first then child will start but it will wait  for user to enter data. As soon as data is entered, child will execute. */
