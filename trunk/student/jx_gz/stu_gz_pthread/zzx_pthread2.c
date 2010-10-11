#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> 

int flag = 0 ;	//判断各线程是否结束

void *thread (void * p)
{
	int m = *(int*)p - 9 ;
	printf("pthread ~~~~~~~~~~ %d\n",m); 
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	for (; m <= *(int *)p ; m ++)
	{
		printf("~~~%d",m );	
	}
	printf("\npid %u ~~ tid %u (0x%x)\n", (unsigned int)pid, (unsigned int)tid, (unsigned int)tid); 
//	system ("date"); 

	flag ++ ;

	return ;
}

void *f1 (void *p)
{
	*(int *)p = 0 ;

	sleep (1) ;
	puts ("\n\n\t\tIs over !");
	system ("date");

	flag ++ ;

	return ;
}


int main ( int argc , char *argv)
{
	pthread_t id ;
	int i , ret, tmp;
	int a[12];

	for(i = 1 ; i <= 10 ; i ++)
	{
		a[i] = 10 * i ;
		ret = pthread_create(&id , NULL , thread , &a[i]);
		/*if (a[i] == 20)
		{
			tmp = pthread_create(&id , NULL , f1 , &a[i]);

			if(tmp!=0)
			{
				printf("Create pthread error!\n");
				exit(1);
			}
		}*/
		
		if(ret!=0)
		{
			printf("Create pthread error!\n");
			exit(1);
		}
		printf ("\n");
	}
	//	sleep (2);
	while (flag != 10);

	return 0 ; 
}

