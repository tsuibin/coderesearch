#include <stdio.h>
#include <string.h>

int change(int s)
{
	char variable[20];
	int i,l;
	memset(variable,0,20);
	l = cd(s) - 1;
	for(i=l;i >= 0;i--)
	{
		variable[i] = s % 10 + '0';
		s=s/10;
	}
	printf("%s\n",variable);
	return 0;
}

int cd(int p)
{
	int u = 0;
	while(p != 0)
	{
		p = p / 10;
		u ++;
	}
	return u;
}

int main(int argc,char *argv[])
{
	int a;
	//a = 20101006;
	printf("Please input a number(Maximum is eight):");
	scanf("%d",&a);
	change(a);
	return 0;
}
