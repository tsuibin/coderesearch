#include <stdio.h> 

int main(int argc , char *argv[]) 
{
	volatile int a = 5;
	int b = a;
	b += 3;

	return b;
}
