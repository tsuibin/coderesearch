#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2048
long strlen1(const char *);
char * strseac1(const char *, char);
char * strseac2(const char *, const char *, char);
void putstr(const char *, const char *);
int main(int argc, char * argv[])
{
	FILE *fp;
	char buf[MAX] ;
	char *ptr, *start, *end;
	long tmp;
	if((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		exit(1);
	}

	while(fgets(buf, MAX, fp) != NULL) 
	{
		if ((ptr = strseac1(buf, '@')) != NULL)
		{	
			start = strseac2(ptr, buf, ' ');
			if ( start == NULL ){
				start = strseac2(ptr, buf, '\t');
			}

			end = strseac1(ptr, ' ');
			
			if ( end == NULL ){
				end = strseac1(ptr,'\r');
			}
			else if ( end == NULL )
			{
				end = strseac1(ptr, 26 );
			}
			if ( end == NULL )
			{
				printf("con't find end of mail");
				return 1;
			}
			if (start != NULL)
			{
				putstr(start, end);
			}
		}
		memset(buf, 0, MAX);

	}
	fclose(fp);
	printf ("bye!\n");

	return 0;
}

long strlen1(const char * str)
{
	long i = 0L;

	while (*str++)
	{
		i++;
	}

	return i;
}

char * strseac1(const char * str, char ch)
{
	while (*str != ch && *str != '\0')
	{
		str++;
	}

	if (*str == '\0')
	{
		return NULL;
	}
	else 
	{	
		return (char *) str;
	}
}

char * strseac2(const char * str1, const char * str2, char ch)
{
	while (*str1 != ch && str1 >= str2)
	{
		str1--;
	}
	
	if (*str1 == ch)
	{
		return (char *) str1;
	}
	else
	{
		return NULL;
	}
}

void putstr( const char * start, const char * end)
{
	const char * str;

	for (str = start + 1; str < end; str++)
	{
		putc(*str, stdout);
	}
	printf("\n");
}
