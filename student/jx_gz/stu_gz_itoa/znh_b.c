#include <stdio.h>
#include <stdlib.h>

void num_str(void);

int main (int argc, char *argv[])
{
	num_str();

	return 0;
}
void num_str(void)
{
	int num = 20101006, i = 7;
	char str[9];
	
	while(num > 0)
	{
		str[i--] =(num % 10) + '0';
		num /= 10;
	}
	str[8] = '\0';
	printf("%s\n",str);

	return ;
}
