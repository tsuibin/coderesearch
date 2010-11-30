#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 

int main(int argc ,char *argv[]) 
{
	int fd;
	fd = open("./abc.tmp",02);
	if(fd < 0)
	{
		printf("e\n"); 
	}
	if ( dup2(fd,2) < 0 ){
		printf("eeee\n");  
	}
	
	printf("filed:%d\n",fd); 
	
	
	write(fd,"aaaaaaaaaaaaaaaaaaaaaaaasd\n",100);

	
	perror("adfasfasdf");
	
	close(fd);

//	execlp("ls","ls","-l",NULL);

return 0; 
//	exit(1);
}
