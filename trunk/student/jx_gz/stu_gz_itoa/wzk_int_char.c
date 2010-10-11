#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
int main(int argc, char *argv[]) 
{
	
	int i,j,x,n,num;
	int y;
	int a[20];
	char b[20];
	i = 0;
	n = 0;
	printf ("please input num\n");
	scanf ("%d",&x);
	do{
		
		num = x%10;
		a[i++] = num;
		x = x/10;
		
	}while (x != 0);
	
	for (j = i-1; j >= 0; j--)
	{
		b[n++] = '0' + a[j];
	}
	
	b[n] = '\0';

	printf ("%s\n",b);
	y = atoi(b);
	printf ("y = %d\n",y); 

	return 0;
}
