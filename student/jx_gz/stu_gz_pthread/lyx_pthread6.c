#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>

int flag = 1, n = 1;
void *thread(void* test)
{
	int k,tmp;
	pid_t pid;
	pthread_t tid;

	pid = getpid();//获取进程id
	tid = pthread_self();//获取线程id
	
	tmp = *(int*)test * 100 - 99;
	
	for(k = tmp ; k < tmp + 100;k++)
	{
		printf("%d~",k);
	}
	printf("\n");
	flag = 1;
	n++;
//	printf("create success!thread pid %u tid %u (0x%x)\n", (unsigned int)pid, (unsigned int)tid, (unsigned int)tid); 
}

int main(void)
{
	pthread_t id;
	int i = 0,ret;
	
	while(i < 100)
	{
		if(flag == 1)
		{
			flag = 0;
			ret = pthread_create(&id,NULL,thread,&n);	
			printf("this is %d\r\n",i);
			if(ret!=0)
			{
				printf("Create pthread error!\n");
				exit(1);
			}
			i ++;
		}
	}
//	system("date");
	return 0;
}
