#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1,fd2, len;
	int x;
	char write_buf1[50]="This is content of opened file\n";
	char write_buf2[50]="This is content of created file\n";
	char read_buf1[50];

	// Open operation
	fd1 = open("file1.txt",O_CREAT | O_RDWR,0777);
	printf("file1.txt created\n");
	
	// Write operation
	len = write(fd1,write_buf1,50);

	printf("\nreturn value from write optn = %d\n",len);

	// lseek operation
	lseek(fd1,0,SEEK_SET);

	// Read operation
	read(fd1,read_buf1,len);

	printf("data from buffer(read optn) = %s\n",read_buf1);

	// Creat operation
	fd2 = creat("file2.txt",0777);
	printf("file2.txt created\n");
	if(fd2==-1)
		printf("\nFile not created\n");
	else
	{
		printf("\nFile created with fd = %d\n",fd2);
		write(fd2,write_buf2,50);
		printf("Use cat command to display the contents of newly created files\n");
	}
	
	// Close operation
	close(fd1);
	close(fd2);
	return 0;
}
