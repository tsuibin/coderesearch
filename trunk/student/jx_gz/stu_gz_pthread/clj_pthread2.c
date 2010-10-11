#include <stdio.h> 
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 

void *thread(void *a)
{
	int i = *(int *)a;
	printf("This is pthread %d :\n", i); 
	int p,j;
	p = (i - 1) * 10;
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("create success! thread pid %u tid %u (0x%x)\n",(unsigned int )pid,(unsigned int)tid,(unsigned int)tid); 	
	
	printf("print the number ten:\n"); 
	for(j = p+1 ; j  <= p+10 ; j++) 
	{
		printf(" ~~ %d", j);
	}
	printf("\n"); 
	pthread_join(tid,NULL);
	printf("\n"); 
	return 0;   
	

}


int main(int argc,char *argv[])

{
	pthread_t id;
	int ret,str[20],i,j;
	j = 0;
	for(i = 1;i <= 10;i++) 
	{	
		str[j] = i;
		ret = pthread_create(&id,NULL,thread,&str[j]);
//		printf("this is %d:\n",i);
		if(ret != 0)
		{
			printf("create pthread error!\n");
			exit(1);
		}
		j++;
		printf("%d\n",j);	
	}

	printf("jjjjj %d\n",j);	
	while(j--)
	return 0;   
	
}
