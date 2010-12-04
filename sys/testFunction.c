#include "stdio.h"
int i;
void p(int a);
int main(int argc,int argv[])
{
	for(i=0;i<5;i++){
		p(i);
	}
	return 0;
}

void p(int a)
{
	printf("test %d \n",a);
}
