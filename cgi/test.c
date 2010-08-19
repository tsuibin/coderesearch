#include <stdio.h>
#include <string.h>
#include "cgi.h"
#include <stdlib.h>
#include "sqlite3.h"
#define DATEBASE "OAK.db"

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
