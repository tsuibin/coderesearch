#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

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


int main(int argc , char *argv[]) 
{
	char cont[MAX_LINE];
	char *p;
	char *tmp;
	int count;
	init_file("./tmp");
	while( (tmp = get_line()) != NULL )
	{
		memmove(cont,tmp,MAX_LINE);
		p = strstr(cont,"共和国");
		printf("%s\n",p);
	}
	close_file();
	
	return 0;
}
