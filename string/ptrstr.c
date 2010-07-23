#include <stdio.h>
#include <stdlib.h>

void swapadd(char **str1 , char **str2)
{
	char **tmp;
	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}
int main(int argc , char *argv[])
{
	char *pstr1 = "abcdefg";
	char *pstr2 = "1234567";
	swapadd(&pstr1,&pstr2);
	printf("%s\n",pstr1);	
	printf("%s\n",pstr2);	
	return	0;
}
