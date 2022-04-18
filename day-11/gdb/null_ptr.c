#include<stdio.h>
int main()
{
	int *i;
	float *f;
	char *c;
	
	i=NULL;
	f=NULL;
	c=NULL;
	
	printf("Size of c:%ld\n",sizeof(c));
	printf("Value at i:%d\n",*i);
	return 0;
}
