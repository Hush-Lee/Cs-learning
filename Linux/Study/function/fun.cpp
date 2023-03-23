#include<fcntl.h>
#include<unistd.h>
#include<iostream>
int main(){
	int fd;
	fd=open("english.txt", O_RDONLY);
	if(fd==-1){
		perror("english open");
		close(fd);
		return -1;
	}
	int cp=open("copy.txt",O_WRONLY|O_CREAT,0777);
	if(cp==-1){
		perror("copy open");
		close(cp);
		return -1;
	}
	char copy[1024]={'0'};
	int res;
	do{
		res=read(fd,copy,1024);
		if(res==-1){
			perror("read");
			close(fd);
			return -1;
		}
		res=write(cp,copy,res);
		if(res==01){
			perror("write");
			close(cp);
			return -1;
		}
	}while(res>0);
	close(fd);
	close(cp);
	return 0;
}
