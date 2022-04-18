#include<stdio.h>

#include "calc.h"

int main(int argc, char *argv[])
{
	double v1,v2,m1,m2,m3,m4;
	v1 = 5.2;
	v2 = 7.9;
	m1=add(v1,v2);
	m2=sub(v1,v2);
	m3=multiply(v1,v2);
	m4=divide(v1,v2);
	printf("The addition of %3.3f and %3.2f is %3.2f\n",v1,v2,m1);
	printf("The subtraction of %3.3f and %3.2f is %3.2f\n",v1,v2,m2);
	printf("The multiplication of %3.3f and %3.2f is %3.2f\n",v1,v2,m3);
	printf("The division of %3.3f and %3.2f is %3.2f\n",v1,v2,m4);
	
	return 0;
}
