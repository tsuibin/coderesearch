#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> 

void *thread (void * p)
{
	int m = *(int*)p - 9 ;
 
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	
	for (; m <= *(int *)p ; m ++)
	{
		printf("~~~%d",m );	
	}
	printf("\nthread pid %u ~~ tid %u (0x%x)\n", (unsigned int)pid, (unsigned int)tid, (unsigned int)tid); 

	return ;
}

int main ( int argc , char *argv)
{
	pthread_t id ;
	int i , ret , m ;



		for(i = 1 ; i <= 10 ; i ++)
		{
			m = 10 * i ;
			ret = pthread_create(&id , NULL , thread , &m);

			if(ret!=0)
			{
				printf("Create pthread error!\n");
				exit(1);
			}
		}

	return 0 ; 
}

