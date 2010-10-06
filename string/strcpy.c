#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main(int argc , char *argv[]) 
{
	char * str1 = "hello";
	char * str2 = "world!";

	strcpy(str1,str2);
	printf("%s\n",str1); 

	return 0; 
}
