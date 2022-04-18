#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
// argc counts total number of arguments
// argv stores all parameters
{
	int i;
	printf("\nFile name : %s\n",argv[0]);
	printf("\nTotal number of arguments : %d\n",argc);
	printf("\nArguments passed : ");
	for(i=1;i<argc;i++)
		printf("%s ",argv[i]);
	printf("\n");
}
