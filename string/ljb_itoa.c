#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


int main(int argc , char *argv[])
{
	int i = 20101006 ,j;
	char a;
	char b[8],*s;
	int k = 7;
	

	for (; i / 10 != 0; i = i / 10)
	{
		printf("%d \n",i); 
		j = i % 10;
		printf("/// %d\n",j); 
		a = j + '0';
		b[k] = a;
		k--;
	}
	s = b;

	printf("%s\n",s); 

	return 0; 
}
