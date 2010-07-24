#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

typedef char type_t;


int init_arr(type_t a[],int len)
{
	int i;
	srand(time(NULL));
	len -=1;
	for(i = 0;i < len;i++)
	{
		int tmp = rand() % 26;
		a[i] = (tmp % 2) ? ('a' + tmp) : ('A' + tmp);
	}
	a[i] = '\0';
	return 0;
}

int main(int argc , char *argv[])
{
	type_t a[N] = {0};
	init_arr(a,N);
	printf(a);
	printf("\n");

	return 0;
}
