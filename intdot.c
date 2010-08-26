#include <stdio.h> 
#include <stdlib.h> 

int main(int argc , char *argv[]) 
{
	int	i,
		x = 5,
		y = 6;
	
	i = x,y; // i = y
	printf("i = %d x = %d y = %d \n",i,x,y); // output : i = 5 x = 5 y =6

	return 0;

}
