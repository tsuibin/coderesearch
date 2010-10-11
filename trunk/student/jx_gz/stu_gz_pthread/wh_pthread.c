#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <time.h>
int flag=0;

void *thread(void* test)
{
	flag ++;
	int i, j = flag-1,ret;
	printf("this is %d\n",j);
	for(i = 1; i <= 10;i++)
	{
		ret = j * 10 + i;
		printf("%d ",ret);
	}
	printf("\n");

	pthread_exit(0);	
}

int main(void)
{
	pthread_t id;
	int i,ret;
	for(i=0; i<=9; i++)
	{
		ret = pthread_create(&id,NULL,thread,&i);
		if(ret != 0)
		{
			printf("create pthread error!\n");

		}
	}
	while (flag == 9)
	return 0;
}
