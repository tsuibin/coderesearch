#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

int *count;
void sig_usr(int signo)
{
	(*count)++;
	printf("%s\n", "sigusr1");
}

int main(void)
{
	pid_t childpid;
	int fd = open("count", O_RDWR | O_CREAT | O_TRUNC, 0644);

	if (fd < 0) {
		perror("open count");
		exit(1);
	}
	
	lseek(fd, sizeof(int) - 1, SEEK_SET);
	write(fd, "a", 1);
	count = (int *)mmap(NULL, sizeof(int), PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

	if (count == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}

	if (close(fd) < 0) {
		perror("close count");
		exit(1);
	}

	struct sigaction newact, oldact;
	sigset_t newmask, oldmask, suspmask;
	newact.sa_handler = sig_usr;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGUSR1, &newact, &oldact);

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGUSR1);
	sigprocmask(SIGUSR1, &newmask, &oldmask);

	*count = 0;
	int i = 5;

	if ((childpid = fork()) < 0) {
		perror("creat child");
		exit(1);
	}
	
	if (childpid == 0) { 
		while(i-- > 0) {
			printf("%s\n", "child");
			kill(getppid(), SIGUSR1);
			suspmask = oldmask;
			sigdelset(&suspmask, SIGUSR1);
			sigsuspend(&suspmask);
			printf("%d\n", *count);
		}
	} else { 
		while(i-- > 0) {
			printf("%s\n", "parent");
			suspmask = oldmask;
			sigdelset(&suspmask, SIGUSR1);
			sigsuspend(&suspmask);
			printf("%d\n", *count);
			kill(childpid, SIGUSR1);
		}  
		wait(NULL);
	}
	sigaction(SIGUSR1, &oldact, NULL);
	sigprocmask(SIGUSR1, &oldmask, NULL);

	return 0; 
}
