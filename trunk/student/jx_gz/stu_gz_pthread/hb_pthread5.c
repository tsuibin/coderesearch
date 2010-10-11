#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define M 100

int flag = 1;
void *callback (void *count)
{
	int i,j;
	static int k = 1 ;
	i = *(int*)count;
	j = i*M;
	for (;k <= j;k++)
	{
		printf("%d ",k);
		if(k == 10000)
		{
			flag = 0;
			printf("\n");
			return ;
			
		}
	}
	printf("\n");
	flag = 0;
	return ;
}
int main (int argc,char *argv)
{
	
	pthread_t id;
	int i,ret;
	for (i = 1;i <= M;i++)
	{
		
		ret = pthread_create(&id,NULL,callback,&i);
		while(0 != flag);
		printf("Input a %d~~~\n",i);
		if (0 != ret)
		{
			printf ("Create pthread error!\n");
			exit(1);
		}
	}
	//sleep(1);
	return 0;
}

