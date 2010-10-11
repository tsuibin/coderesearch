#include <stdio.h>

void count(int num)
{
	int x;
	int c;
	int n = 1;
	int i = 0;
	int b = 1;
	int m = 1;
	int e = 0;
	int w;
	char a[w];
	for(;num/n != 0;i++)
	n = n*10;
	for(c = 1;c < i;c++)
	b = b * 10;
	while(m != 0)
	{
		x = num / b;
		m = num % b;
		a[e] = x + '0';
		e++;
		b = b /10;
		num = m;
	}
	printf("%s\n",a);
}

int main(int argc , char ** argv[])
{
	int num = 20101006;
	count(num);
	return 0;
}

