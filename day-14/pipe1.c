#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	int fds[2];
	int res,i;
	char *buf1 = "linuxkernelsystem";
	char *buf = "operatingsystem";
	char buf2[40];
	
	res = pipe(fds);
	
	/* fds[0] for reading and fds[1] for writing */
	if(res==-1)
	{
		perror("pipe");
		exit(1);
	}
	write(fds[1],buf1,15);
	write(fds[1],buf,15);
	read(fds[0],buf2,30);
	for(i=0;i<30;i++)
		printf("%c",buf2[i]);
	printf("\n");
}
