#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Can you see me [ONE]\n");
	
	execl("/home/divyansh/Linux_Internal/day-4/prac6","./	prac6","assignment","two","question","four",NULL);

	printf("Can you see me [TWO]\n");
}
