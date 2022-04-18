#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *src;
	//src = malloc(1<<31);	// asking malloc to allocate 2 GB size
	src = malloc(200);
	fgets(src,500,stdin);
	printf("%s\n",src);
	return 1;
}
