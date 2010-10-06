#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


int main(int argc , char *argv[])
{
	int str1[9] = {2,0,1,0,1,0,0,6};
	char str2[10];
	int i;

	for (i =0; i < 8; i++)
	{
		str2[i] = itoa(str1[i]);
	}
	
	printf("%s\n",str2); 

	return 0; 
}
