#include <stdio.h>
#include <string.h>
#include <libcgi/cgi.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	cgi_init();
	cgi_session_start();
	cgi_process_form();
	cgi_init_headers();
	
	printf("hello cgi!\n");

	cgi_end();
	return 0;
}
