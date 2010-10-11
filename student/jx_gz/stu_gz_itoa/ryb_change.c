#include <stdio.h>
#include <string.h>
int change (int b)
{
	char variable [20];
	memset (variable,0,20);
	 sprintf(variable,"%d",b);
	printf("variable=%s\n",variable);
	return 0;


}


int main (int argc,char *argr[])
{
	int a;
	scanf("%d",&a);
	change (a);
	return 0;


}
