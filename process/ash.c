#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
struct {
	char *argv[8];
	char *in;
	char *out;
} cmd[2];

int main()
{
	cmd[0].argv[0] = "ls";
	cmd[0].argv[1] = "-l";
	cmd[0].argv[2] = NULL;
	cmd[0].in = NULL;
	cmd[0].out = NULL;

	cmd[1].argv[0] = "wc";
	cmd[1].argv[1] = NULL;
	cmd[1].in = NULL;
	cmd[1].out = "output.txt";
	
	int i, fd[2]; pid_t pid;
	pipe(fd);
	for (i=0; i<2; i++) if ((pid=fork())==0) break;
	if (pid==0) {
		switch (i) {
		case 0:
			dup2(fd[1], 1); 
			break;
		case 1:
			dup2(fd[0], 0);
			if (cmd[1].out) {
				int fd = open(cmd[1].out, 
							  O_WRONLY | O_CREAT | O_TRUNC,
							  0644);
				dup2(fd, 1); close(fd);
			}
			break;
		default: break;
		}
		close(fd[0]); close(fd[1]);
		execvp(cmd[i].argv[0], cmd[i].argv);
	}
	close(fd[0]); close(fd[1]);
	wait(NULL); 
	wait(NULL); 
	return 0;
}
