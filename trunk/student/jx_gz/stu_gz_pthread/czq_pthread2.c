#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> 

int flag = 0 ;	//判断各线程是否结束

void *thread (void * p)
{
	int m = *(int*)p - 9 ;

	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	
	printf ("第%d线程\n",flag + 1); 

	for (; m <= *(int *)p ; m ++)
	{
		printf("~~~%d",m );	
	}

	flag ++ ;

	return ;
}


int main ( int argc , char *argv)
{
	pthread_t id ;
	int i , ret;
	int a[12];
	
	for(i = 1 ; i <= 10 ; i ++)
	{
		a[i] = 10 * i ;
		ret = pthread_create(&id , NULL , thread , &a[i]);
		if(ret!=0)
		{
			printf("Create pthread error!\n");
			exit(1);
		}
		printf ("\n");
	}

	while (flag != 10);

	return 0 ; 
}
