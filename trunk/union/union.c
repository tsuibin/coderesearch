#include <stdio.h> 
#include <stdlib.h> 

union data
{
	int i;
	char ch;
	float f;
};

int main(int argc , char *argv[]) 
{
	union data a;	
	
	printf("%d \n",sizeof(a)); 

	printf("%x\n",&a.i); 
	printf("%x\n",&a.ch); 
	printf("%x\n",&a.f);

	return 0;
}
