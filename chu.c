#include <stdio.h> 
#include <stdlib.h>

int main(int argc , char * argv[])
{
	int i = 0;
	for ( i ; i < 15 ; i++ )
	{
		printf("%d % 3 = %d\n",i,i%3);
	}

	return 0;

}
