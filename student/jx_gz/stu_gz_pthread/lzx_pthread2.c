#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>
int flag = 0 ;
void *thread(void *tes)
{
	int m;
	
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("-----%d\n",*(int*)tes);
	printf("create success!thread pid %u tid %u\n", (unsigned int)pid, (unsigned int)tid); 
	for(m = flag*10 -9;m<=flag*10;m++)
	printf ("%d\n",m); 






}
int main()
{
	pthread_t id;
	int i, ret;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	for(i = 1; i<= 10 ;i++){
			flag++;
			
	ret = pthread_create(&id, NULL,thread ,&a[i-1]);
	
//	printf("----%d\n",i);
	}
	if(ret != 0){
	printf("create  pthread error\n");
	exit(0);
	}
sleep(3);
	return 0;
}
