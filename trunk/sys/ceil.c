#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(void)
{
	int i;
	for(i=0;i<=10;i++){
		printf("i = %d , i/2 = %f",i,ceil((i/2)));
	}
	return 0;
}
