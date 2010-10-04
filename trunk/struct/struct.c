#include <stdio.h> 
#include <stdlib.h> 

typedef struct a
{
	int x;
	int y;
}A,*B;

struct mys{
	int id;
	int age;
	char name[20];
};

int main(int argc , char *argv[]) 
{
	A bb; // struct a bb
	B pbb; //struct a *pbb
	pbb = &bb;
	bb.x = 5;
	pbb->x = 6;
	printf("%d\n",bb.x);
	
	return 0;
}
