#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

pthread_mutex_t thread_lock;
int fd;
char buffer[1024];

int thread_err(int *err)
{
	if(*err != 0)
	{
		printf("thread error!error number is %d\n",*err);
		exit(1);
	}

}

void * read_pic(void * count)
{
	int fd_copy;
	int i, j;
	
	fd_copy = open("copyff.jpg", O_CREAT | O_RDWR , S_IRWXU );
	
	if(fd_copy < 0)
	{
		perror("open(copy,O_RDWR | O_CREAT)error\n");
		exit(1);
	}
	j = lseek(fd_copy, 0, SEEK_END);

	if(j < 0)
	{
		perror("lseek(fd_copy, 0, SEEK_END);error\n");
		exit(1);
	}
	
	i = write(fd_copy, buffer, *((int *)count));

	if(i < 0)
	{
		perror("write(fd_copy, buffer, count)error\n");
		exit(1);
	}

	close(fd_copy);

	return 0;
}

int main(int argc, char **argv)
{
	pthread_t id_1, id_2;
	int i;
	size_t count;
	pthread_mutex_init(&thread_lock, NULL);
	
	fd = open("source.jpg", O_RDONLY);
	memset(buffer, 0, sizeof(buffer));

	if(fd < 0)
	{
		perror("open source.jpg error\n");
		exit(1);
	}

	while((count = read(fd, buffer, 1024)))
	{
		int err;
		void *thread_ret;
		err = pthread_create(&id_1, NULL, read_pic, (void *)&count);
		thread_err(&err);
		err = pthread_join(id_1, &thread_ret);
		thread_err(&err);
		memset(buffer, 0, sizeof(buffer));
	}
	
	pthread_mutex_destroy(&thread_lock);

	return 0;
}
