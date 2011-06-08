#include <stdio.h>

int main(int argc, char* argv[])
{
	int i,j;
	char a[2] = {0};

	printf("input your no i = \n");
	scanf("%d",&i);
	for(j = 0; j < 2; j++)
	{	
		a[j] = i % 2;
		i = i/2;
	}

	printf("%s",a);

	return 0; 

}
