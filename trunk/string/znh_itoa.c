#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


int main(int argc , char *argv[])
{
	int a = 20101006;
	int i = 0;
	int j = 0;
	char b[8],c[9];

	while(a/10 > 0)
	{
		a = a/10;
		b[i] = (a%10) - '0';
		i++;
	}

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j>=0; j++)
		{
			c[j] = b[i];
		}
	}
	c[8] = '\0';
	puts(c);
	
	return 0; 
}
