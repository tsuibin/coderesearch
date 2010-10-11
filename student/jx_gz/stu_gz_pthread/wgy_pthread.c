#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <pthread.h> 
#include <errno.h>
#include <netdb.h>
#include <string.h> 

void *thread (void *test)
{	
	int n,m,j;
	static int i;

	pid_t pid;
	pthread_t tid;
	pid=getpid();
	tid=pthread_self();
	n=*(int *)test;
	printf ("~~~~~~~~~%d\n",*(int *)test); 
	printf("Create sucess !thread pid %u tid %u (0x%x)\n",(unsigned int )pid,(unsigned int)tid,(unsigned int)tid);
	j=n*10;
	for(;i<j;i++)
	{
		printf("&&&&%d\n",i);
	}
		
	

}

int main (int argc ,char *argv[])
{
	pthread_t id;
	int i,ret,j;
	int a[10];
	static int flag = 0;

	j=0;
	for (i=1;i<=10;i++,j<i)
	{
	
		a[j++]=i;	
		ret = pthread_create(&id,NULL,thread,&i);
		printf ("this is %d\r\n",i);
		if(ret!=0)
		{
			printf ("Create pthread error\n");
			exit(1);
		}
		else
			printf("***flag=%d\n",flag++);
		flag = 1; 
	}



	sleep(3);
	printf ("\n"); 
	return 0; 
}
