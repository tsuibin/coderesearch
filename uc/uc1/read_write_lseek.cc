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
		char ch;
		for(int i=0;i<3;i++){
			read(fd,&ch,1);
			cout << ch;
			lseek(fd,1,SEEK_CUR);//abcdefghijkl
		}
		cout <<endl;

		close(fd);

		return 0; 
}
