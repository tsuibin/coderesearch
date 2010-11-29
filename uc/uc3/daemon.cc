#include <iostream> 
using namespace std; 
#include <unistd.h>
#include <stdlib.h> 
#include <sys/stat.h>
#include <fcntl.h> 

void work()
{
	char ch='A';
	for(;;){
		int fd = open("tick.txt",O_WRONLY|O_CREAT|O_APPEND,0777);
		if(fd >=0){
			write(fd, &ch,1);
			close(fd);
		}
		ch++;
		if(ch > 'Z')
			ch = 'A';
		sleep(3);
	}
}

void make_daemon(){
	if(fork() != 0){
		exit(0); 
	}
	setsid();//彻底脱离父子关系
	umask(0077);//屏蔽其他人的一切权限
	for(int fd = 0;fd < 256;fd++){
		close(fd);
	}
	work();

}

int main(int argc ,char *argv[]) 
{
	make_daemon();
	return 0;
}
