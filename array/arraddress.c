#include <stdio.h> 
#include <stdlib.h> 
int main(int argc , char *argv[]) 
{
	int arr[2][2] = {{1,2},{3,4}};
	int addr;
	int *p;
	addr = &arr;
	p = addr+4;
	printf("%d \n",*p);
	return 0;
}
