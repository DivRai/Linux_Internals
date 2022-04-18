#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1,fd2, len;
	int x;
	char write_buf1[50]="This is content of opened file";
	char write_buf2[50]="This is content of created file";
	char read_buf1[50];

	// Open operation
	fd1 = open("file4_1.txt",O_CREAT | O_RDWR,0777);
	
	// Write operation
	len = write(fd1,write_buf1,50);

	printf("return value from write optn = %d\n",len);

	// lseek operation
	lseek(fd1,0,SEEK_SET);

	// Read operation
	read(fd1,read_buf1,len);

	printf("data from buffer(read optn) = %s\n",read_buf1);

	// Creat operation
	fd2 = creat("file4_2.txt",0777);
	if(fd2==-1)
		printf("\nFile not created\n");
	else
	{
		printf("\nFile created with fd = %d\n",fd2);
		write(fd2,write_buf2,50);
		printf("Use cat command to display the contents of newly created file\n");
	}
	
	// Close operation
	close(fd1);
	close(fd2);
	return 0;
}
