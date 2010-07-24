#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define T_MAX 2049

char buf[T_MAX];
const int tmp = 'a' - 'A';

char ctoUper(char c)
{
	if ( 96 < c && c < 123)
	{
		return c -= tmp;
	}
	else
	{
		return c;
	}
}

char ctoLower(char c)
{
	if ( 64 < c && c < 91)
	{
		return c += 32;
	}
	else
	{
		return c;
	}
}

char * strToUper(char * str)
{
	int i,len;
	len = strlen(str);
	if (len > T_MAX)
	{
		printf("this string size is to large , big than 2048\n"); 
		return NULL;
	}
	for (i = 0; i < len ; i++)
	{
		buf[i] = ctoUper(*str);
	//	buf[i] = ctoLower(*str);
		str++;
	}
	buf[++i] = 0;	
	return buf;
}

int main(int argc , char *argv[])
{
	char * test1 = "sadfdsafnejf";
	char * test2 = "09123abcdABCD 6";
	char * test3 = "CbdDSK&~`f";
	char * test4 = "sadf2137#&^^*&*";


	printf("%s \n",strToUper(test1));
	printf("%s \n",strToUper(test2));
	printf("%s \n",strToUper(test3));
	printf("%s \n",strToUper(test4));
	return	0;
}
