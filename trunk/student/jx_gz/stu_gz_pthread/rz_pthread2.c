#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>
void *thread (void *test)
{
	int m , i;
	pid_t pid ;
	pthread_t tid ;
	i = *(int *)test ;
	m = i - 9 ;
	pid = getpid();
	tid = pthread_self();

	for(;i >= m ; i--)
	{
		printf("~~~%d\n" , i);
	}
	printf("create success!thread pid %u tid %u (0x%x)\n" , (unsigned int)pid, (unsigned int)tid ,(unsigned int)tid);


}   
int main (void)
{
	pthread_t id ;
	int i , ret ;

	for(i = 10 ; i <= 100 ; i += 10)
	{
		ret = pthread_create(&id , NULL ,thread ,&i);
		printf("this is %d\n", i);
		if(ret != 0)
		{
			printf("create pthread error\n");
			exit(1);
		}
	}   


}
