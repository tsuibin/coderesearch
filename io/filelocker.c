#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 
#include <sys/file.h>
#include <string.h> 

void locker(char *name)
{
	char filename[20];
	strcpy(filename,"/tmp/");
	strcat(filename,name);

	int fd = open (filename, O_CREAT|O_WRONLY, 0644);
	int lock =  lockf(fd,F_TLOCK,0);
	if (fd == -1) {
		perror("open");
		exit(-1);
	}   

	if (lock == -1) {
		perror("lock");
		exit(-1);
	}


}

int main(int argc, char *argv[])
{
	locker(argv[0]);
	while(1);
	return 0;
}
