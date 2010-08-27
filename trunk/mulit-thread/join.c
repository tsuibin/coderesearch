#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

void * thread_function_one(void *arg)
{
	printf("thread one is running...\n");
	return ((void *)1);
}

void * thread_function_two(void *arg)
{
	printf("thread two is running...\n");
	pthread_exit((void *)2);

}

void thread_err(int *err)
{
	if (*err != 0)
	{
		printf(" Thread Error ! Error number : %d\n",*err);
		exit(*err);
	}
}

int main(int argc, char **argv)
{
	int err;
	pthread_t tid1, tid2;
	void *thread_ret;

	err = pthread_create(&tid1, NULL, thread_function_one, NULL);//线程ID,线程属性,线程方法,线程参数
	thread_err(&err);
	err = pthread_create(&tid2, NULL, thread_function_two, NULL);
	thread_err(&err);
	err = pthread_join(tid1,&thread_ret);
	thread_err(&err);
	printf("Thread 1 exit code %d\n",(int)thread_ret);
	err = pthread_join(tid2,&thread_ret);
	thread_err(&err);
	printf("Thread 2 exit code %d\n",(int)thread_ret);

	
	return 0;
}
