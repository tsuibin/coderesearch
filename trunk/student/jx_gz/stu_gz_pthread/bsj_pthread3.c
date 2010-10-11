#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

int u = 0;

void *thread(void *text)
{
	u = 1;
	pid_t pid;
	pthread_t tid;
	int k,w,l = 0;
	char s[50];
	
	pid = getpid();
	tid = pthread_self();
	w = *(int*)text * 10 + 1;
	for(k =w;k < w + 10;k++)
	{
		sprintf(s,"%d",k);
		printf("~~%s",s);
	}
	s[l++] = '\0';
	u = 0;
	//printf("create success!thread pid %u tid %u (0x%x)\n", (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
	
}

int main(int argc,char *argv[])
{
	pthread_t id;
	int i,ret;
	for(i = 0;i < 10;i ++)
	{
		if (u == 0)
		{	
			ret = pthread_create(&id,NULL,thread,&i);
			printf("this is %d\r\n",i);
			if (ret != 0)
			{
				printf("create error");
				exit(1);
			}
		}
		else i--;
	}	
	return 0;
}
