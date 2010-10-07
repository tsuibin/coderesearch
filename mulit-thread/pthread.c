#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>


void *thread(void* test)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("~~~%d\n",*(int*)test);	
	printf("create success!thread pid %u tid %u (0x%x)\n", (unsigned int)pid, (unsigned int)tid, (unsigned int)tid); 
	//pthread_exit(0);	
}

int main(void)
{
	pthread_t id;
	int i,ret;
	//pthread_attr_t attr;
	//pthread_attr_init(&attr);
	//pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	for(i=0;i<=5;i++){
		//ret = pthread_create(&id,&attr,thread,NULL);
		ret = pthread_create(&id,NULL,thread,&i);
		printf("this is %d\r\n",i);
		if(ret!=0){
			printf("Create pthread error!\n");
			exit(1);
		}
	}
	/*
	#include <signal.h>
	int sig;
	ret = pthread_kill(tid, sig); // kill -l
	pthread_cancel(tid);	
	*/
	sleep(3);
	return 0;

}
