#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main(int argc , char *argv[]) 
{
	//char  * str1 = "hello";
	char str1[] = "hello";
	char * strp = malloc(6);
	if ( strp == NULL)
	{
		printf("malloc error\n"); 
	}
	char * str2 = "w";
	strcpy(strp, str1);
	printf("%s\n",strp);

	free(strp);

	return 0; 
}
