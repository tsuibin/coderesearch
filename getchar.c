#include   <stdio.h>
#include   <stdlib.h>

int main(void)
{
	int   c;
	for   (;c = getchar();)
	{
		printf( "c   =   %08x\n ",   (unsigned   int)c);
		printf( "c   =   %d\n ","\n");
		printf( "c   =   %d\n ",   (unsigned   int)c);
	}

	return 0;
} 
