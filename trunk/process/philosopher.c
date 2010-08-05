#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#define N 5
#define L(p) (p)
#define R(p) (((p)+1)%N)

sem_t *chopstick;
void pick_up(int me)
{
	if (me==0) {
		sem_wait(&chopstick[L(me)]);
		sem_wait(&chopstick[R(me)]);
	} else {
		sem_wait(&chopstick[R(me)]);
		sem_wait(&chopstick[L(me)]);
	}
}
void put_down(int me)
{
	sem_post(&chopstick[R(me)]);
	sem_post(&chopstick[L(me)]);
}
void philosopher(int me)
{
	for (;;) {
		pick_up(me);
		printf("%d eating...\n", me);
		sleep(1);
		put_down(me);
		printf("%d thinking...\n", me);
		sleep(1);
	}
}
int main()
{
	int i;
	int fd = open("chopstick.sem", 
				  O_RDWR | O_CREAT | O_TRUNC, 0644);
	lseek(fd, (N-1)*sizeof(sem_t), SEEK_SET);
	write(fd, "", sizeof(sem_t));
	chopstick = mmap(0, N*sizeof(sem_t), PROT_READ | PROT_WRITE, 
					 MAP_SHARED, fd, 0);
	for (i=0; i<N; i++) sem_init(&chopstick[i], 1, 1);
	for (i=0; i<N-1; i++) if (fork()==0) break;
	philosopher(i);
	return 0;
}
