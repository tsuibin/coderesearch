
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

#define THRD_NUM	2
volatile int persize;
/*

typedef struct copy_param
{
	FILE *src;
	FILE *des;
	int off_set;
} *Copy_param;

unsigned long filesize(FILE *fp)
{
	fseek(fp, 0L, SEEK_END);
	return ftell(fp);	
}

unsigned long thrd_copy(Copy_param ptr)
{
	char c;
	FILE *src = ptr->src;
	FILE *des = ptr->des;
	unsigned long off_set = ptr->off_set;
	unsigned long i;

	printf("off set = %d\n", off_set);
	assert(src != NULL && des != NULL);
	fseek(src, off_set, SEEK_SET);
	fseek(des, off_set, SEEK_SET);

	for (i = 0; i < persize; i++)
	{
		fread(&c, 1, 1, src);
		fputc(c, des);	
	}

	return i+1;
}




int main(int argc, char *argv[])
{
	FILE *src, *des;
	FILE *src[THRD_NUM], *des[THRD_NUM];
	int count;
	int ret;
	pthread_t copy_thrd[THRD_NUM];
	unsigned long length = 0;
	Copy_param ptr = NULL;
	char c;

	if (argc != 3)
	{
		printf("usage filename srcfile desfile\n");
		return 1;
	
	}	

	src = fopen(argv[1], "r");
	des = fopen(argv[2], "w+");
	if (src == NULL || des == NULL)
	{
		perror("open file");
		return 2;
	}

	length = filesize(src);
	persize = length/THRD_NUM;
	printf("persize = %d\n", persize);

	for (count = 0; count < THRD_NUM; count++)
	{
		ptr = (Copy_param)malloc(sizeof(struct copy_param));
		ptr->src = src;
		ptr->des = des;
		ptr->off_set = count * persize;

		ret = pthread_create(copy_thrd + count, NULL, (void *)thrd_copy,(void *)ptr);	
		if (ret != 0)
		{
			printf("thread %d creat error\n", count);
			return count;
		}	
	}

	for (count = 0; count < THRD_NUM; count++)
	{
		ret = pthread_join(copy_thrd[count], NULL);
		if (ret == 0)
		{
			printf("thread %d join success\n", count);
		}
	}

	fclose(src);
	fclose(des);
	return 0;
}
*/
