#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

int gnum = 0;
sem_t sem;

static void pthread_func_1(void);
static void pthread_func_2(void);

int main(void)
{

	pthread_t pt_1 = 0;
	pthread_t pt_2 = 0;
	int ret = 0;

	ret - sem_init(&sem, 0, 1);
	if (ret < 0 )
	{
		perror("sem init error!");
	}

	ret = pthread_create(&pt_1, NULL, (void *)pthread_func_1, NULL);

	
	if (ret != 0)
	{
		perror("pthread_1_create");
	}
	
	ret = pthread_create(&pt_2, NULL, (void *)pthread_func_2, NULL);

	if (ret != 0)
	{
		perror("pthread_2_create");
	}

	pthread_join(pt_1, NULL);
	pthread_join(pt_2, NULL);

	printf("main programme exit\n");
	return 0;
}

static void pthread_func_1(void)
{
	for(;;)
	{
		printf("this is pthread1!\n");
		sem_trywait(&sem);
		sleep(1);
		gnum++;
		printf("thread1 add onr to num:%d\n", gnum);
		sem_post(&sem);
	}
	pthread_exit(0);

}

static void pthread_func_2(void)
{
	for(;;)
	{
		printf("this is pthread2!\n");
		sem_trywait(&sem);//线程执行速度无法确定，所以这里应该用sem_trywait,而不是sem_wait
		sleep(1);
		gnum++;
		printf("thread2 add one to num:%d\n", gnum);
		sem_post(&sem);
	}
	pthread_exit(0);
}
