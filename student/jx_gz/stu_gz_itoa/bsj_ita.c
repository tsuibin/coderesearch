#include <stdio.h>
#include <stdlib.h>

int change(int s)
{
	char variable[10];
	sprintf(variable,"%d",s);
	printf("%s\n",variable);
	return 0;
}

int main(int argc,char *argv[])
{
	int a;
	printf("Please input a number:");
	scanf("%d",&a);
	change(a);
	return 0;
}
