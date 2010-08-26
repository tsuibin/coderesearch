#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>


void * process(void *arg)
{

	printf("thread ID : %u value: %s \n",(unsigned int)pthread_self(),(char *)arg); 	
	return(NULL);
}

int main(int argc, char **argv)
{
	pthread_t thread0, thread1;
	
	for (;;)
	{
		pthread_create(&thread0, NULL, process, "0");
		pthread_create(&thread1, NULL, process, "1");
	}
	
	
	return 0;
}
