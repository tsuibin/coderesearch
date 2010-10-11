#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>

int flag = 1;

void *thread(void* test)
{
	int m;
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("create success!thread pid %u tid %u (0x%x)\n", (unsigned int)pid, (unsigned int)tid, (unsigned int)tid); 
	for (m = flag*10-9;m <= flag*10;m++)
	printf("%d  ",m);
	printf("\n");
	flag ++;
	return ;
}

int main(void)
{
	pthread_t id;
	int i,ret;
	for (i=1;i<=10;i++)
		{
			printf("this is %d\r\n",i);
	       		ret = pthread_create(&id,NULL,thread,&i);
			if(ret!=0)
				{
					printf("Create pthread error!\n");
					exit(1);
				}	
		}
		while (flag != 11);
		return 0;

}
