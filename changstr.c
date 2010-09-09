#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

void change(char str[],char c)
{
	int i,len;

	while(*str !='\0')
	{
		if (*str == c)
		{
			memmove(str,str+1,strlen(str));
			len--;
		}
		str++;
	}
}

int main(int argc, char *argv[]) 
{
	char str[] = "sadfcdewrcasd";
	change(str,'c');

	printf("%s\n",str);

	return 0;
}
