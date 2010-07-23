#include <stdio.h>
#include <stdlib.h>

int getMax(int a,int b)
{
	return (a>b)? a:b;
}
int main(int argc , char *argv[])
{
	int a,b;
	
	a = 5;
	b = 10;

	printf("max = %d\n",getMax(a,b));

	return;
	
}
