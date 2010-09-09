#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int a[5][5] = {
		{1, 6, 2, 3, 7},
		{2, 7, 3, 2, 2},
		{3, 2, 5, 3, 6},
		{3, 2, 6, 4, 2},
		{4, 3, 7, 4, 8}	
	};
	int i, j;
	int t;

	for(i = 0; i < 5; i++)
	{
		for(j = 0;j < 5; j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n"); 
	}

	
	for(i = 0; i < 5; i++)
	{
		for(j = i+1; j < 5; j++)
		{
			t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
		printf("\n"); 
	}

	printf("\n\n");

	for(i = 0; i < 5; i++)
	{
		for(j = 0;j < 5; j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n"); 
	}
	
	return 0; 
}

