#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *str1 = "Divyansh";
	char *str2 = "Rai";
	
	char *name = (char *)alloca(strlen(str1)+strlen(str2)+1);
	
	stpcpy(stpcpy(name,str1),str2);
	//strcpy(stpcpy(name,str1),str2);
	
	printf("The string 1 data is = %s\n",str1);
	printf("The string 2 data is = %s\n",str2);
	printf("The copied string data is = %s\n",name);
	
	return 0;
}
