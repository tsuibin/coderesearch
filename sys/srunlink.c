#include "apue.h"
#include "apueerror.h"
#include <fcntl.h>
#define TEMPFILE "tempfile"
int
main(void)
{
	if( creat( "tempfile" , S_IRUSR ) < 0 )
		err_sys("open error");
	if( unlink( "tempfile" ) < 0 )
		err_sys("unlink error");
	printf("file unlinked\n");
	sleep(5);
	printf("done\n");
	exit(0);
}
