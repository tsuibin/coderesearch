#include <stdio.h>	
#include <stdlib.h>	

int main(int argc,char* argv[])
{
	int i;
	for(i = 0;i < 99999999;i++)
	{
		int *p;
		if ( ( p = malloc( sizeof( int ) ) ) == NULL )
		{
			printf("malloc false!\n");
		}
	}



	return 0;
}
