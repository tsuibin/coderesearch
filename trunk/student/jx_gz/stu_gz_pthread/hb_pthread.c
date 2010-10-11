#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>


int flag=1;
void *callback (void *count)
{
	int i,j;
	static int k=1;
	i = *(int*)count;
	j = i*10;
	for (;k<=j;k++)
	{
		printf("~%d~",k);
	}
	flag=0;
	return ;
}
int main (int argc,char *argv)
{
	
	pthread_t id;
	int i,ret;
	for (i = 1;i <=10;i++)
	{
		
		ret = pthread_create(&id,NULL,callback,&i);
		while(0 != flag);
		printf("Input a %d~~~\n",i);
		if (ret != 0)
		{
			printf ("Create pthread error!\n");
			exit(1);
		}
	}
sleep(5);	
	return 0;
}

