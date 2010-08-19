#include <stdio.h> 
#include <stdlib.h> 
typedef struct stra{
	char * cp;
	int ab;
}STR ,*pSTR;

void num(STR sa)
{
	static pSTR p;
	p = &sa;
	printf("%d \n",p->ab); 
}

int main(int argc , char *argv[])
{
	STR abc;
	abc.ab = 5;
	num(abc);
	return 0;
}
