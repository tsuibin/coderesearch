#include <stdio.h> 
#include <stdlib.h> 

typedef struct a
{
	int x;
	int y;
}A,*B;

int main(int argc , char *argv[]) 
{
	A bb;
	B pbb;
	pbb = &bb;
	bb.x = 5;
	pbb->x = 6;
	printf("%d\n",bb.x);
	
	return 0;
}
