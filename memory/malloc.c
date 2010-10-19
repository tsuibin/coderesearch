#include <stdio.h>	
#include <stdlib.h>	

int main(int argc,char* argv[])
{
	int i;
	for(i = 0;i < 99999999;i++)
	{
		int *p;
		if ( ( p = malloc( sizeof( int )*1024 ) ) == NULL )
		{
			printf("%d malloc false!\n",i);
		}
	}
	
	printf("ok\n"); 

	return 0;
}
