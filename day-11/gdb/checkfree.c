#include<stdio.h>
#include<stdlib.h>

void buggy()
{
	int *intptr;
	intptr = (int *)malloc(sizeof(int));

	*intptr = 100;
	printf("Value at ptr intptr = %d\n",(*intptr));
	free(intptr); 	// free the pointer
	*intptr = 99;	// trying to derefer the freed pointer
}

int main()
{
	buggy();
	return 0;
}
