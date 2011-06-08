/* system.c */
/*
* int system(const char *s);
* 
*/
#include <stdio.h> 
#include <stdlib.h>

int main(int argc ,char *argv[]) 
{
	int ret = 0;
	if ( system( NULL ) )
	{
		system("echo \"Shell:$SHELL; process ID:$$\" ");
	} else {
		printf("No command process available.\n"); 
	}

	return 0;
}
