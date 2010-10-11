#include<stdio.h>

int main(int argc,char **argv)
{

	int i = 20101006;
	int j;
	char a;
	char  b[8],*s;
	int k = 7;
	for(;i != 0;i = i/10)
	{
		j = i%10;
		a = j + '0';
		b[k] = a;
		k --;
	}
	s = b;
	printf("%s\n",s);
	return 0;

}
