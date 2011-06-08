#include <stdio.h> 
#include <time.h>

int main(int argc ,char *argv[]) 
{
	time_t t;
	srand(time(&t));
	int p;
	for (p = 0; p < 20; p++)
	{
	int i = rand();


	printf("%d\n", i);
}
	return 0; 
}
