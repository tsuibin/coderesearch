#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

volatile double pi = 0.0;
pthread_mutex_t pi_lock;
volatile double intervals;

void * process(void *arg)
{
	register double width,localsum;
	register int i;
	register iproc = (*((char *) arg) - '0');

	width = 1.0;

	localsum = 0;
	
	for (i = iproc; i<intervals; i+=2)
	{
		register double x = (i + 0.5) * width;
		localsum += 4.0 / (1.0 + x * x);
	}

	localsum *= width;

	pthread_mutex_lock(&pi_lock);
	pi += localsum;
	pthread_mutex_unlock(&pi_lock);

	return(NULL);
}

int main(int argc, char **argv)
{
	pthread_t thread0, thread1;
	void * retval;

	intervals = atoi(argv[1]);

	pthread_mutex_init(&pi_lock, NULL);

	pthread_create(&thread0, NULL, process, "0");
	pthread_create(&thread1, NULL, process, "1");

	pthread_join(thread0, &retval);
	pthread_join(thread1, &retval);

	printf("Extimation of PI is %20.18f\n",pi);

	return 0;
}
