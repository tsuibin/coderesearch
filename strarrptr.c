#include <stdio.h> 

int main(int argc , char *argv[]) 
{
	char s[] = "asdfafd", *p;

	for (p = s; *p; p++)
		--*p;
		puts(s);
		return 0;
}

