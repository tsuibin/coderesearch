#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define N 6
int main()
{
	pid_t pid;
	int i, fd[2]; 
	fprintf(stderr, "i pid   ppid\n");
	pipe(fd);
	dup2(fd[0], 0); dup2(fd[1], 1);
	close(fd[0]); close(fd[1]);
	for (i=0; i<N; i++) {
		pipe(fd);
		if ((pid=fork())>0) dup2(fd[1], 1); 
		else                dup2(fd[0], 0);
		close(fd[0]); close(fd[1]);
		if (pid) break;
	}
	fprintf(stderr, "%d %d %d\n", i, getpid(), getppid());
	wait(NULL);
	return 0;
}
