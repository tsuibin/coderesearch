#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *mystr(int a)
{
	int i;
	char j=0;
	char *p;
	p=malloc(20);
	while(a!=0)
	{
		i=a%10;
		a=a/10;
		p[j++]=i+'0';
	}
	

	return p; 
}
int main(int argc,char *argv[])
{	
	int a;
	int i;
	int len;
	char *p;
	printf("please input a num!\n");
	scanf("%d",&a);
	p=mystr(a);
	len=strlen(p);
	for(i=len-1;i >= 0;i--)
	{
		printf("%c",p[i]);
		
	}

	printf ("\n");
	return 0;
}
