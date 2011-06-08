#include <stdio.h> 
#include <time.h>
#include <stdlib.h>

int main(int argc ,char *argv[]) 
{
	time_t t;
	char rname[6] = {0};
	int i,l;

	srand(time(&t));
	
	for( l = 0; l < 20; l++)
	{
		for ( i = 0; i < 5; i++)
		{
			rname[i] = rand()%26 + 97;
		}
		printf("%s\n",rname); 
	}

	return 0; 
}
