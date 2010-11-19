#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>


sigset_t bset;


void* sigmgr_thread()
{
	sigset_t    oset;
	int        sig;
	int        rc;
	pthread_t  ppid = pthread_self();

	//pthread_detach(ppid);


	while (1)  {
		rc = sigwait(&bset, &sig);/*对不再指定信号集中的信号会继续等待*/
		if (rc != -1) {
			printf("sig is : %d \n", sig);
		} else {
			printf("sigwaitinfo() returned err: %d; %s\n", errno, (char *)strerror(errno));
		}
	}
}


int main()
{ 
	sigset_t  oset; 
	int             i;
	pid_t           pid = getpid();
	pthread_t       ppid;

	sigemptyset(&bset);
	sigaddset(&bset, 70);
	sigaddset(&bset, SIGRTMIN);
	sigaddset(&bset, SIGRTMIN+2);
	sigaddset(&bset, SIGRTMAX);
	sigaddset(&bset, SIGUSR1);
	sigaddset(&bset, SIGUSR2);

	if (pthread_sigmask(SIG_BLOCK, &bset, &oset) != 0)
		printf("!! Set pthread mask failed\n");

	kill(pid, 70);// using system signals couldn't send user's sig
	kill(pid, SIGRTMAX);/*主线程发送信号量*/
	kill(pid, SIGRTMAX);
	kill(pid, SIGRTMIN+2);
	kill(pid, SIGRTMIN);
	kill(pid, SIGRTMIN+2);
	kill(pid, SIGRTMIN);
	kill(pid, SIGUSR2);
	kill(pid, SIGUSR2);
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR1);

	// Create the dedicated thread sigmgr_thread() which will handle signals synchronously
	pthread_create(&ppid, NULL, sigmgr_thread, NULL);

	pthread_join(ppid,NULL);
	//sleep(10);

	exit (0);
}
