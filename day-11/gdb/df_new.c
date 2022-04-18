#include<stdio.h>
#include<stdlib.h>

void buggy(int *p)			//3. Func using that value
{
	p[0] = 10; 				//4. writing to address
	free(p);  				//5. free ptr
}

int main()
{
	int *ptr;
	ptr = (int *)malloc(4);		// 1. Creating 4 bytes
	buggy(ptr);				// 2. Passing address of 4 bytes to through a ptr
	free(ptr);				// 6. Double free i.e. trying to free a ptr already freed
	return 0;
}
