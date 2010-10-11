#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>

int tmp;
void *thread(void* test)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	tmp++;
	printf("create success!thread pid %u tid %u (0x%x)\n",
		(unsigned int)pid, (unsigned int)tid, (unsigned int)tid); 

	printf("%d\n",tmp); 
}

int main(void)
{

	pthread_t id;

	int i,ret;
	//int tmp;
	tmp =0;
	for( i = 0; i <= 5; i++){
		ret = pthread_create(&id,NULL,thread,NULL);
		printf("this is %d\r\n",i);
		if ( ret != 0 )
		{
			printf("Create pthread error!\n");
			exit(1);
		}

	}
	sleep(1);
	return 0;

}
