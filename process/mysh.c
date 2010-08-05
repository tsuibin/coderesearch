#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAXLINE 1024
int main()
{
	char buf[MAXLINE];
	pid_t pid;
	int status;
	printf("mysh> ");
	while (fgets(buf, MAXLINE, stdin)) {
		buf[strlen(buf)-1] = '\0';
		pid = fork();
		if (pid==0) {
			execlp(buf, buf, (char*)0);
			printf("couldn't exec %s\n", buf);
			exit(127);
		}
		waitpid(pid, &status, 0);
		printf("mysh> ");
	}
	exit(0);
}
