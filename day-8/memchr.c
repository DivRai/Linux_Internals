#include<stdio.h>
#include<string.h>

int main()
{
	const char str[] = "linuxkernel.com";
	const char ch = '.';
	char *ret;	
	
	printf("String before chr/scan is %s\n",str);
	
	ret = memchr(str,ch,strlen(str));		// ret is interior pointer

	printf("String after **%c** is  - **%s**\n",ch,ret+1);
	printf("String befre **%c** is  - **%s**\n",ch,ret-1);
	
	return 0;
}
