#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

int flag = 0;

void sig_usr(int signo)
{
	flag = 1;
}

int main(void)
{
	pid_t current;
	pid_t childpid;
	int *count;
	int fd = open("count", O_RDWR | O_CREAT | O_TRUNC, 0644);

	if (fd < 0) {
		perror("open count");
		exit(1);
	}
	
	lseek(fd, sizeof(int) - 1, SEEK_SET);
	write(fd, "a", 1);
	count = mmap(NULL, sizeof(int), PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

	struct sigaction newact, oldact;
	newact.sa_handler = sig_usr;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGUSR1, &newact, &oldact);
	
	*count = 0;
	int i = 5;

	if ((childpid = fork()) < 0) {
		perror("creat child");
		exit(1);
	}
	
	if (childpid == 0) { 
		while(i > 0) {
			if (flag == 1) {
				flag = 0;
				i--;
				(*count)++;
				printf("child = %d\n", *count);
				sleep(1);
				kill(getppid(), SIGUSR1);
			}
		}
	} else { 
		(*count)++;
		printf("parent = %d\n", *count);
		sleep(1);
		kill(childpid, SIGUSR1);
		while(i > 0) {
			if (flag == 1) {
				flag = 0;
				i--;
				(*count)++;
				printf("parent = %d\n", *count);
				sleep(1);
				kill(childpid, SIGUSR1);
			}  

		}

		wait(NULL);
	}

	return 0; 
}
