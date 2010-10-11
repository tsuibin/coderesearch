#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int tmp = 0;

void *thread(void *num)
{
	tmp++;
	int a, i;
	pid_t pid;
	pthread_t tid;
	
	
	pid = getpid();
	tid = pthread_self();
	a = *(int *)num;
	a = a*10 - 9;
	for(i = 0; i < 10; i++)
		printf("%d  ",a++);
	printf("create success! thread pid %u tid %u (0x%x)\n",
	(unsigned int)pid ,(unsigned int)tid, (unsigned int)tid);
	

	return NULL;
}

int main(int argc, char *argv[])
{
	
	pthread_t id;
	int i, ret;
	
	for(i = 1; i <= 10; i++)
	{
		ret = pthread_create(&id, NULL,thread, &tmp);
		if(ret != 0)
		{
		fputs("create pthread error", stderr);
		}
	}
	sleep(3);

	return 0;
}

