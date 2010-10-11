#include <stdio.h>
#include <pthread.h>

int flag = 0 ;

void *thread(void* test)
{
	int i;
	for (i = 0; i < 200; i++)
	{
		printf("%d\n",flag++);
	}
	pthread_exit(0);
}

int main(void)
{
	pthread_t id;
	int i,ret;
	
	for ( i = 0; i < 50; i++)
	{
		pthread_create(&id,NULL,thread,NULL);	
	}
	while(flag != 10000);
	fflush(stdout);
	
	return 0;
}
