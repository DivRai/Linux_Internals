#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("I am going to execute pstree command\n\n");
	execl("/usr/bin/pstree","pstree",NULL);
	return 0;
}
