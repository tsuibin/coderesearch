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
	int k,tmp;
	pid_t pid;
	pthread_t tid;

	pid = getpid();//获取进程id
	tid = pthread_self();//获取线程id

	tmp = *(int*)test * 10 - 9;

	for(k = tmp ; k < tmp + 10;k++)
	{
		printf("%d~",k);
	}
	flag = 1;
	//	printf("create success!thread pid %u tid %u (0x%x)\n", (unsigned int)pid, (unsigned int)tid, (unsigned int)tid); 
}

int main(void)
{
	pthread_t id;
	int i = 0,n = 1,ret;

	while(i < 10)
	{
		if(flag == 1)
		{
			flag = 0;
			ret = pthread_create(&id,NULL,thread,&n);	
			n++;
			printf("this is %d\r\n",i);
			if(ret!=0)
			{
				printf("Create pthread error!\n");
				exit(1);
			}
			i++;
		}
	}
	//	while(i < 20);
	//	{i ++;}
	return 0;
}

