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
		name = (char *)"rw.txt";
		fd = open(name,O_RDWR);
		if(fd < 0){
				cout << "文件不存在" <<endl;
				return -1;
		}
		char ch;
		lseek(fd,0,SEEK_END);

		write(fd,"bye\n",4);

		close(fd);

		return 0; 
}
