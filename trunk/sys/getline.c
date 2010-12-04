#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN_MAX 512

char *mygetline(void);
int main()
{
	while( printf("%s\n",mygetline()) > 0 );
	return 0;
}
char *mygetline(void)
{
	char buffer[LEN_MAX],*linePtr = NULL;
	if ( fgets( buffer, LEN_MAX, stdin ) != NULL )
	{
		size_t len = strlen( buffer );
		if( buffer[len-1] == '\n' )
			buffer[len-1] = '\0';
		else
			++len;
		
		if( (linePtr = malloc( len )) != NULL )
			strcpy( linePtr, buffer );
	}
	return linePtr;
}


