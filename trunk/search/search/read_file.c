/*
 * read a html file
 */

#include <stdio.h>

FILE * fp;

#define MAX_LINE 1024
static char buf[MAX_LINE];
/* return 0,open file ok
 * open file error!!!
 */

int init_file (char *filename)
{
	if ( (fp = fopen(filename,"r+")) == NULL) {
		perror(filename);
		return -1;
	}

	return 0;
}

char * get_line(void )
{
	char *ret;
	
	ret = fgets(buf,MAX_LINE,fp);

	if (ret != buf)
		return NULL;
	
	return ret;
}

void close_file ()
{

	fclose(fp);
}
