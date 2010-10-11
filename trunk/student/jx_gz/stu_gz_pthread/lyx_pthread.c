#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>

int flag = 1 ;
void *thread(void* test)
{
	int k,n;
	pid_t pid;
	pthread_t tid;

	pid = getpid();//获取进程id
	tid = pthread_self();//获取线程id
	
	n = (*(int *)test) * 10 + 1;
	
	for(k = n ; k < n + 10;k++)
	{
	//	printf("~~~%d\n",*(int*)test);	
		printf("~%d~",k);
	}
	flag = 1;
	printf("create success!thread pid %u tid %u (0x%x)\n", (unsigned int)pid, (unsigned int)tid, (unsigned int)tid); 
}

int main(void)
{
	pthread_t id;
	int i,n,ret;
	
	for(i=0;i<10;i++)
	{
		if(flag == 1)
		{
			flag = 0;
			ret = pthread_create(&id,NULL,thread,&i);	
			printf("this is %d\r\n",i);
			if(ret!=0)
			{
				printf("Create pthread error!\n");
				exit(1);
			}
		}
	}
	
	sleep(3);
	
	return 0;
}
