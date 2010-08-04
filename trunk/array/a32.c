#include <stdio.h> 
#include <stdlib.h> 

int main(int argc , char *argv[]) 
{
	int i,j;
	int a[3][2] = {{1,4},{2,5},{3,6}};
	
	for ( i = 0 ; i < 3 ; i++)
		for ( j = 0 ; j < 2; j++)
			printf("a[%d][%d] + a[%d][%d] = %d \n", 
				i, j, i, j, a[i][j]+a[i][j]
			);
	
	return 0;
}
