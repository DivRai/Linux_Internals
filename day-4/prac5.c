#include<stdio.h>
#include<stdlib.h>

void callback1(void)
{
	printf("Callback1 func called\n");
}

void callback2(void)
{
	printf("Callback2 func called\n");
}

void callback3(void)
{
	printf("Callback3 func called\n");
}

int main()
{
	printf("Registering callback1\n");
	atexit(callback1);
		
	printf("Registering callback2\n");
	atexit(callback2);

	printf("Registering callback3\n");
	atexit(callback3);

	printf("\nmain()...exiting now\n\n");

	exit(0);		// Functions will be called
	//_exit(0);		// Functions will not be called
}
