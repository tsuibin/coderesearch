#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	int fd[2];
	char c;
	fd[0] = open("f0", O_RDONLY);
	fd[1] = open("f1", O_RDONLY);
	for (;;) {
		read(fd[0], &c, 1);
		write(1, &c, 1);
		read(fd[1], &c, 1);
		write(1, &c, 1);
	}
	return 0;
}
