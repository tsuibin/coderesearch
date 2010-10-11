#include <stdio.h>  

int main(int argc, char *argv[])

{
	int i,a;
	int b;
	char c[20];
	i = 0;
 	a = 12345678;
	
	for (i = 0; i < 8; i++)
	{	
		b = a % 10;
		a = a/10;
		c[i] = b + '0';
		
	}
	c[i] = '\0';

	for (i = i - 1;i >= 0; i--)
	{
		printf ("%c",c[i]); 
	}
	printf ("\n"); 
 	
	return 0;
}
