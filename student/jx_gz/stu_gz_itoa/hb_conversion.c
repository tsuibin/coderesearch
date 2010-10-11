#include <stdio.h>
#define M 100


char *conversion(int count)
{
	
	char sht[M],shh[M];
	char *pa;
	int i=0,j=0;
	while (count!=0)
	{
		sht[i]=count%10+'0';
		count/=10;
		i++;
	}
	
	i--;	
	for (;i>=0;i--)
	{
		shh[j++]=sht[i];
			
	}
	shh[j]='\0';
	printf("%s\n",shh);
	pa=shh;

	return pa;
}
int main (int argc,char *argv)
{

	int count;
	char *p;

	scanf("%d",&count);

	p=conversion(count);
	printf("%s\n",p);

	return 0;
}

