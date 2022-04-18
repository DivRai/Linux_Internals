// system() System Call

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buff_comm[6];
	strcpy(buff_comm,"ls -l");
	
	printf("System() library function uses fork() to create a child process\n");
	printf("\nChild process executes execl() which loads and run new program provided by system() arguments\n\n");
	system(buff_comm);
	//printf("%d\n",system(NULL));         This will return 1
	//system();                            This will give "too few arguments" error
	return 0;
}
