#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>

int main()
{
	int fd;
	char *c;
	struct stat file_info;
	fd = open("kernel.txt",O_CREAT|O_RDWR,0777);
	write(fd,"linux kernel technology",25);
	
	fstat(fd,&file_info);		// works like ls -l
	printf("File size is %lu\n",file_info.st_size);
	
	c = mmap(0,file_info.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
	perror("mmap");
	
	printf("%s\n",c);	    // no need of accessing sys call for file read write
	
	munmap(c,file_info.st_size);
	close(fd);	
	
	return 0;
}
