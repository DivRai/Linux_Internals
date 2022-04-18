# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

void main(){
	int fd = open("./exec",O_RDONLY);
	printf("In inherited program, fd = %d\n",fd);
}
