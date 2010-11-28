#include <iostream> 
using namespace std;
//#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h> 

int main(int argc ,char *argv[]) 
{
		int fd;
		char *name;
		short sec = 2;
		if (argc > 1){
				name = argv[1];
				if (argc > 2) sec = atoi( argv[2]);
		}else{
				name = (char *)"rw.txt";
		}
		fd = open(name,O_RDWR);
		if(fd < 0){
				cout << "文件不存在" <<endl;
				return -1;
		}
		int rlen,wlen;
		char buf[80]={0};

		while((rlen = read( fd, buf,80)) > 0 ){
				wlen = write(1,buf,80);
				sleep(sec);
				memset(buf,0,80); //malloc calloc 
		}
		close(fd);

		return 0; 
}
