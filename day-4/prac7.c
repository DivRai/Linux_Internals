#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Can you see me [ONE]\n");
	
	execl("/home/divyansh/Linux_Internal/day-4/prac6","./prac6","linux","kernel","programming","device","drivers",NULL);
	//execl("/home/divyansh/Linux_Internal/day-4/exec","./prac6","linux","kernel","programming","device","drivers",NULL);

	printf("Can you see me [TWO]\n");
}
