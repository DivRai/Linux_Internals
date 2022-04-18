// Due to structure padding the size comes out to be 52 bytes

#include<stdio.h>
#include<stdlib.h>
struct A
{
	int roll;
	char name[40],gender;
	float height;
};

int main()
{
	struct A first;
	printf("Size of struct A is %3ld\n",sizeof(first));
}
