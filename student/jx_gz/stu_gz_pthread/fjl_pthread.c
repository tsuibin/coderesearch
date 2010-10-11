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

	int i;
	int a;
//	pid_t pid;
//	pthread_t tid;
	a = *(int*)test;
//	pid = getpid();
//	tid = pthread_self();
	
	printf("this is %d\n",a);
	for (i = a*10-9 ; i <=a*10 ; i++ )
	{
		printf("--%d",i);
		
	}	
	
		printf("\n");


	//printf("~~~%d\n",*(int*)test);	
	//printf("create success!thread pid %u tid %u (0x%x)\n", (unsigned int)pid, (unsigned int)tid, (unsigned int)tid); 
	//pthread_exit(0);	
}

int main(void)
{
	pthread_t id;
	int i,ret,j;
	int b[20];
	j = 0;
	//pthread_attr_t attr;
	//pthread_attr_init(&attr);
	//pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	for(i=1;i<=10;i++){
		//ret = pthread_create(&id,&attr,thread,NULL);
		b[j] = i;
		ret = pthread_create(&id,NULL,thread,&i);
		//printf("this is %d\r\n",i);
		if(ret!=0){
			printf("Create pthread error!\n");
			exit(1);
		}
	j++;
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
