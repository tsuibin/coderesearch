#include <stdio.h> 
#include <pthread.h>
#include <stdlib.h> 
#include <string.h> 

void *thread(void *a)
{
//	sleep(1);
	int n,m;
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	n = *(int*)a;
	printf("this is:%d\n",n);
	printf ("pthread num=%u,process num=%u\n",(unsigned int)tid,(unsigned int)pid); 
	m = n+10;
	for (;n < m;n++)
	{
		printf ("---%d",n); 
	}
	
	printf ("\n");
	pthread_join(tid,NULL);
	
	
}


int main(int argc, char *argv[]) 
{
	system("date");
	pthread_t id;
	int ret,i,j;
	int b[20];
	j = 0;
	for (i = 1; i < 100; i=i+10)
	{
		b[j] = i;
		ret = pthread_create(&id,NULL,thread,&b[j]);
		printf ("%d\n",j);
		if (ret != 0)
		{
			printf ("create thread fail!\n");
			return 0; 
		}

		j++;
	}
		
	printf ("\n");
	while (j --);
	system("date");
	return 0;
}
