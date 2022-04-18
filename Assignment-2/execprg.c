#include<stdio.h>
#include<unistd.h>
# include <sys/types.h>
# include <fcntl.h>

int main()
{	
	/*printf("I am going to execute an 'ls' program\n");

	execl("/bin/ls","ls","-lh",NULL);*/
	
	int fd = open("execprg.c",O_RDONLY);
	printf("In execprg.c, fd = %d\n",fd);
	
	return 0;
}
