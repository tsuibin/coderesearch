/*
 * 用线程互斥锁和条件变量实现生产者和消费者同步问题
 * 此列用多进程实现，如果用多线程则不用设置设置互斥锁和条件变量的属性
 * 同样也不用mmap实现共享内存
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <pthread.h>
#include <assert.h>

#define BSIZE 1024

typedef struct {
	char buf[BSIZE];
	int occupied;
	int nextin;
	int nextout;
	pthread_mutex_t lock;
	pthread_cond_t more;
	pthread_cond_t less;
} buffer_t;

void buffer_init(buffer_t *);
void buffer_free(buffer_t *);
void producer(buffer_t *, char);
char consumer(buffer_t *);
void producer_driver(buffer_t *);
void consumer_driver(buffer_t *);

int main()
{
	int zfd;
	pid_t pid;
	buffer_t *buf;

	zfd = open("/dev/zero", O_RDWR);
	buf = (buffer_t *)mmap(NULL, sizeof(buffer_t),
			PROT_READ | PROT_WRITE, MAP_SHARED, zfd, 0);
	close(zfd);
	buffer_init(buf);

	if ((pid = fork()) == 0) {
		printf("input something:\n");
		producer_driver(buf);
		exit(0);
	} else {
		consumer_driver(buf);

		waitpid(pid, NULL, 0);
		buffer_free(buf);
		munmap(buf, sizeof(buffer_t));
		return 0;
	}
}

void buffer_init(buffer_t *b)
{
	pthread_mutexattr_t mattr;
	pthread_condattr_t cattr;

	if (b == NULL) return;

	bzero(b->buf, BSIZE);
	b->occupied = b->nextin = b->nextout = 0;

	pthread_mutexattr_init(&mattr);
	pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
	pthread_mutex_init(&b->lock, &mattr);
	pthread_mutexattr_destroy(&mattr);

	pthread_condattr_init(&cattr);
	pthread_condattr_setpshared(&cattr, PTHREAD_PROCESS_SHARED);
	pthread_cond_init(&b->more, &cattr);
	pthread_cond_init(&b->less, &cattr);
	pthread_condattr_destroy(&cattr);
}

void buffer_free(buffer_t *b)
{
	if (b == NULL) return;

	bzero(b->buf, BSIZE);
	b->occupied = b->nextin = b->nextout = 0;

	pthread_mutex_destroy(&b->lock);
	pthread_cond_destroy(&b->more);
	pthread_cond_destroy(&b->less);
}

void producer(buffer_t *b, char item) 
{
	pthread_mutex_lock(&b->lock);
	while (b->occupied >= BSIZE)
		pthread_cond_wait(&b->less, &b->lock);
	assert(b->occupied < BSIZE);
	b->buf[b->nextin++] = item;
	b->nextin %= BSIZE;
	b->occupied++;
	pthread_cond_signal(&b->more);
	pthread_mutex_unlock(&b->lock);
}

char consumer(buffer_t *b) 
{
	char item;

	pthread_mutex_lock(&b->lock);
	while (b->occupied <= 0)
		pthread_cond_wait(&b->more, &b->lock);
	assert(b->occupied > 0);
	item = b->buf[b->nextout++];
	b->nextout %= BSIZE;
	b->occupied--;
	pthread_cond_signal(&b->less);
	pthread_mutex_unlock(&b->lock);

	return item;
}

void producer_driver(buffer_t *b)
{
	int item;

	for (;;) {
		item = getchar();

		if (item == EOF) {
			producer(b, '\0');
			break;
		}

		producer(b, (char)item);
	}
}

void consumer_driver(buffer_t *b)
{
	char item;

	for (;;) {
		if ((item = consumer(b)) == '\0')
			break;

		putchar(item);
	}
}
