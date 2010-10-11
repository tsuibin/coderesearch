#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

pthread_mutex_t thread_lock;

void * process(void *arg)
{
	for (;;)
	{
		sleep(1);
		pthread_mutex_lock(&thread_lock);
		printf("thread ID : %u value: %s \n",(unsigned int)pthread_self(),(char *)arg); 	
		pthread_mutex_unlock(&thread_lock);
	}

	return ((void *)1);
}

int main(int argc, char **argv)
{
	pthread_t thread0, thread1;
	int ret;
	void * thread_ret = NULL;

	pthread_create(&thread0, NULL, process, "0");
	pthread_create(&thread1, NULL, process, "1");
	for (;;)
	{
		pthread_join(thread0, &thread_ret);
		if ( thread_ret != NULL ) return 1;
		pthread_join(thread1, &thread_ret);
		if ( thread_ret != NULL ) return 1;
	}
	pthread_mutex_destroy(&thread_lock);
	
	return 0;
}
