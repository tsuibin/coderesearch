#include <stdio.h> 
#include <signal.h>


int main(int argc , char *argv[])
{
	sigset_t set;
        int sig;
	
	sigemptyset(&set);
	sigaddset(&set, SIGSTOP);


	//int sigwait(const sigset_t *restrict set, int *restrict sig);

	sigwait( &set,&sig);
printf("sig is: %d\n",sig); 
//	while(1);

	return 0; 

}
