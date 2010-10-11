#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int flag=0;
void *callback (void *count)
{
	int i,j;
	static int k=1;
	i = *(int*)count;
	j = i*10;
	for (;k<=j;k++)
	{
		printf("~%d~",k);
		if(k==100)
			return;
	}
	printf("\n");
	flag=1;
	return ;
}
int main (int argc,char *argv)
{
	
	pthread_t id;
	int i,ret;
	for (i = 1;i <=10;i++)
	{
		while(0 != flag);
		ret = pthread_create(&id,NULL,callback,&i);
		flag=0;
		printf("Input a %d~~~\n",i);
		if (ret != 0)
		{
			printf ("Create pthread error!\n");
			exit(1);
		}
	}
	sleep(1);
	return 0;
}

