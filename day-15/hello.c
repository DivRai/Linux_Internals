#include<stdio.h>
#include "mean.h"

int deveshmla=50;

void name(char arr[])
{
	printf("Hello %s\n",arr);	
}

void name1()
{
	char nm2[10]="Monish";
	name(nm2);
}

int main()
{
	char nm[10]="Lala";
	char nm1[10]="Devil";
	printf("Hello World\n");
	printf("Hello %s\n",nm);
	printf("%d",deveshmla);
	name(nm1);
}
