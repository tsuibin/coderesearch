#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void func(int signal)
{
		switch(signal)
		{
				case SIGKILL:printf("爸爸%d接受被杀死信号\n",getpid());
							 break;
				case SIGINT:printf("爸爸%d接受中断信号\n",getpid());
							break;
				case SIGSTOP:printf("爸爸%d接受挂起信号\n",getpid());
							 break;
		}
}

void func1(int signal)
{
		switch(signal)
		{
				case SIGKILL:printf("儿子%d接受被杀死信hao\n",getpid());
							 break;
				case SIGINT:printf("儿子%d接受中断信号\n",getpid());
							break;
				case SIGSTOP:printf("儿子%d接受挂起信号\n",getpid());
							 break;
		}
}
int main(int argc, char *argv[])
{
		int i = 100;
		int fd;
		fd = fork();
		if(!fd)
		{
				signal(SIGINT,func1);
				//signal(	SIG,func1);
				signal(	SIGKILL,func1);
				for(;i != 0; i--)
				{
						//	if(!(i % 10)) 
						//	{
						kill(getppid(),SIGINT);
						if(pause() < 0)
								printf("儿子%d接到爸爸回信!\n",getpid());
						//	}
						//	else 
						//		printf("儿子还活着\n");
						sleep(1);
				}
		}
		else if(fd > 0)
		{
				signal(SIGINT,func);
				signal(	SIGKILL,func);
				while(1)
				{		
						if(pause() < 0)
								printf("爸爸%d接到儿子消息!\n",getpid());
						kill(fd,SIGINT);
						//kill(fd,SIGINT);
						//while(kill(fd,SIGINT) == -1);
				}
		}
		return 0;	
}	
