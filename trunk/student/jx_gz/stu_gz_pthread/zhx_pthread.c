#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
int flag = 0;

void *thread (void *test)
{
	flag ++;
	int i,j = flag - 1 ,ret;
//	j = *(int *)test;
	printf ("this is %d\n",j);

	for (i = 1; i <= 10; i ++)
	{
		ret = j * 10 + i;
		printf ("%d ",ret);
	}
	printf ("\n");
	
	pthread_exit (0);
}

int main (int argc, char *argv [])
{
	pthread_t id;
	int i, ret;

	for (i = 0; i <= 9; i ++)
	{
		ret = pthread_create (&id, NULL, thread, &i);
//		printf ("%d\r\n", i);
		if (ret != 0)
		{
			printf ("error\n");
			return -1;
			//exit(1);
		}
//		sleep (1);
	}
//	sleep(1);

	while(flag != 9);
	return 0;

}
