#include<stdio.h>

int main(int argc,char *argv[])
{
	int i;
	printf("File name: %s\n",argv[0]);
	printf("\nTotal Number of Arguments: %d",argc);
	printf("\nArguments Passed: ");
	for(i=1;i<argc;i++)
		printf("%s ",argv[i]);
	printf("\n");
}
