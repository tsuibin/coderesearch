#include <stdio.h>
#include <string.h>
int main (int argc, char *argv [])
{
	int i;
	int a =20101006;
	char variable[9]= {};
	for(i = 7;i>=0 ;i--)
	{	variable[i]=a%10+'0';
		a=a/10;
//		printf ("variable[%d]=%c\n",i,variable[i]);

	}

	printf ("%s\n",variable);




	return 0;
}
