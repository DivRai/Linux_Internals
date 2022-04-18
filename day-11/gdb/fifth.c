// Due to structure padding the size comes out to be 52 bytes

#include<stdio.h>
#include<stdlib.h>
struct A
{
	int roll;
	char name[40],gender __attribute__((aligned(2)));
	float height;
}__attribute__((packed));		// specifies how the compiler should align data items

int main()
{
	struct A first;
	printf("Size of struct A is%3ld\n",sizeof(first));
}
