#include <stdio.h>
#include <stdlib.h>
int main(int argc , char *argv[])
{
	int i =0;
	printf("%d \n",argc);
	
	for (;i < argc; i++)
	{
		printf("%s \n ", argv[i]);
	}

	return	0;
}
