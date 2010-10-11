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
	flag++;
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("-----%d\n",*(int*)tes);
	printf("create success!thread赖章雄 pid %u tid %u (0x%x)\n", (unsigned int)pid, (unsigned int)tid, (unsigned int)tid); 
	for(m = flag*10 -9;m<=flag*10;m++)
		printf ("%d\n",m); 






}
int main()
{
	pthread_t id;
	int i, ret;
	for(i = 1; i<= 10 ;i++){
		ret = pthread_create(&id, NULL,thread ,&i);
		//	printf("----%d\n",i);
	}
	if(ret != 0){
		printf("create  pthread error\n");
		exit(0);
	}
	sleep(2);
	return 0;
}
