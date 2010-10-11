#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int flag = 0;
int flag1 = 0;

void *thread(void *s)
{
	flag = 0;
	pid_t pid;
	pthread_t tid;
	int i,j;
	
	i = *(int *)s;
	i = i * 10 - 9;
	pid = getpid();
	tid = pthread_self();
	for(j = i;j < i + 10;j ++)
		printf("%d ",j);
	printf("\n");
	flag1 ++;
}

int main(int argc,char **argv)
{
	int i,ret,a;
	pthread_t id;

	for(i = 1; i <= 10; )
	{
		if(flag == 0)
		{
			flag = 1;
			printf("this is %d\r\n",i);
			ret = pthread_create(&id,NULL,thread,&i);
			if(ret != 0)
			{
				printf("create pthread error!\n");
				exit(1);
			}
			i ++;
		}
	}
	while(flag1 < 10);

	return 0;
}
