#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


int main(int argc , char *argv[]) 
{
	char str[10] = "hello";
	char * str1 = "world";


	memmove(str,str1,strlen(str1));
	printf("%s\n",str);

	printf("%s\n",str1); 

	return 0; 

}
