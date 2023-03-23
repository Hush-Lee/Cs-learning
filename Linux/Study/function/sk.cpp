#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
int main(){
	int fd=open("copy.txt",O_RDWR);
	if(fd==-1){
		perror("open");
		return -1;
	}
	lseek(fd,1000,SEEK_END);
	char c[2]={' '};
	write(fd,c,1);
	close(fd);
	return 0;
}
