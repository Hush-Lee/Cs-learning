#include<unistd.h>
#include<fctnl.h>
#include<iostream>
#include<sys/stat.h>
int main(int argc,char* argv[]){
	if(argc<2){
		std::cout<<argv[0]<<" filename\n";
		return -1;
	}	
	struct stat* st;
	int ret = stat(argv[1],st);
	if(ret == -1){
		perror("stat");
		return -1;
	}
	string str=char[10]{'0'};
	switch  
}
