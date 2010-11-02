#include <stdio.h> 
#include <stdlib.h> 

int main(int argc , char *argv[]) 
{
	int a = -1;


	char *p = &a;
	/*
	   整型： 
	   一个正数的补码和其原码的形式相同。而负数的补码方式是将其绝对值的二进制形式“按位求反再加1” 
	 */	

	printf("%c\n",*p++);
	printf("%c\n",*p++);
	printf("%c\n",*p++);
	printf("%c\n",*p);

	return a;
}
