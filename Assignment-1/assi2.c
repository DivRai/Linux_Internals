#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd, len;
	int x;
	char write_buf[50]="Welcome to course on Linux Internals!!";
	char read_buf[50];

	fd = open("file2.txt",O_CREAT | O_RDWR,0777);
	
	len = write(fd,write_buf,50);

	printf("return value from write optn = %d\n",len);

	while(1)
	{
		int ch;
		printf("Enter choice:\n1.SEEK_SET \n2.SEEK_END \n3.SEEK_CUR \n4.Quit\n");
		scanf("%d",&ch);
		if(ch==1) {
		// SEEK_SET	
		int rt1 = lseek(fd,0,SEEK_SET);
		printf("\nCFO Position: %d\n\n",rt1);
		}

		else if(ch==2) {
		// SEEK_END	
		int rt2 = lseek(fd,0,SEEK_END);
		printf("\nCFO Position: %d\n\n",rt2);
		}

		else if(ch==3) {
		// SEEK_CUR	
		int pos = lseek(fd,5,SEEK_CUR);
		printf("\nCFO Position: %d\n\n",pos);
		}

		else
			exit(0);
	}

	close(fd);
	return 0;
}
