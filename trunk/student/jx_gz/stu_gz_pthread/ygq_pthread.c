#include <stdio.h> 
#include <pthread.h>
int s = 0 ; 


void *thread ( void *i)
{
	s++;
	int j,p ;
	j = s;
	pid_t pid ;
	pthread_t tid ;
	pid = getpid();
	tid = pthread_self();
	printf("creat pthread success! pthread pid = %d ~~tid = %d\n",
		(unsigned int)pid,(unsigned int)tid); 
	printf("this is pthread %d\n", j); 
	p = (j -1) * 10 ;
	for(j = p +1 ; j <= p +10 ; j ++ )
	{
		printf(" %d", j); 
	}
	printf("\n"); 

	pthread_exit(0);
}
int main ( void)
{
	pthread_t id ;
	int i ,ret ;
	for(i = 1 ; i <= 10 ; i++)
	{
		ret = pthread_create(&id , NULL , thread , &i);
		if(ret != 0)
		{
			printf("create pthread error!\n"); 
			return -1;
		}

	}
	sleep(2);
	return 0; 
}
