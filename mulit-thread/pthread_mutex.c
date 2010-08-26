#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

pthread_mutex_t thread_lock;

void * process(void *arg)
{

	printf("thread ID : %u value: %s \n",(unsigned int)pthread_self(),(char *)arg); 	
	pthread_mutex_unlock(&thread_lock);
	
	return(NULL);
}

int main(int argc, char **argv)
{
	pthread_t thread0, thread1;
	pthread_mutex_init(&pi_lock, NULL);
	
	for (;;)
	{
		pthread_mutex_lock(&thread_lock);
		pthread_create(&thread0, NULL, process, "0");
		pthread_mutex_lock(&thread_lock);
		pthread_create(&thread1, NULL, process, "1");
	}
	
	pthread_mutex_destroy(&thread_lock)
	
	return 0;
}
