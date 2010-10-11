#include <stdio.h>
#include <string.h>

int my_itoa(int n,int i)
{
	int j;
	char str[20];
	for(j = n;j >= 0;j--)
	{
		str[j] = i % 10 + '0';

		i = i / 10;
	}
	str[n + 1] = '\0';
	printf("%s\n",str);

	return 0;
}

int my_count(int i)
{
	int count = 0;
	while(i / 10 != 0)
	{
		count ++;
		i = i / 10;
	}
	return count;
}

int main(int argc,char *argv[])
{
	int n = 0,i;
	printf("please enter a number:");
	scanf("%d",&i);
	n = my_count(i);
	my_itoa(n,i);
	return 0;
}
