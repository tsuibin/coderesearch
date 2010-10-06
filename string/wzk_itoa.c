#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


int main(int argc , char *argv[])
{
	int x = 20101006;
	int a[20];
	int i = 0;
	int n = 0;
	int j = 0;
	int num = 0;
	char b[20];

	do{
		num = x%10;
		a[i++] = num;
		x = x/10;
	}while(x == 0);
	
	for (j = j -i; j<=0; j--)
	{
		b[n++] = '0' + a[j];
	}
	
	b[n] = '\0';

	printf("%s\n",b); 
	return 0; 
}
