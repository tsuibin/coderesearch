#include <stdio.h> 
#include <stdlib.h> 

#include <mysql.h>

#define DB_HOSTNAME "localhost"
#define DB_USERNAME "root"
#define DB_PASSWORD "a12345"
#define DB_DBNAME   "edinner"
#define DB_PORT	    3306

MYSQL * connect_database(MYSQL *conn_ptr)
{
	return mysql_real_connect(conn_ptr,
				DB_HOSTNAME,
				DB_USERNAME,
				DB_PASSWORD,
				DB_DBNAME,
				DB_PORT,
				/*unix socket name*/ NULL,
				/*flag*/ 0);
}

int main(int argc, char *argv[]) 
{
	MYSQL *conn_ptr;

	conn_ptr = mysql_init(NULL);
	if (!conn_ptr) 
	{
		fprintf(stderr, "mysql_init failed\n");
		return EXIT_FAILURE;
	}

	conn_ptr = connect_database(conn_ptr);
	
	if (conn_ptr)
	{
		printf("Connection success\n"); 
	}
	else
	{
		printf("Connection failed\n");
	}

	mysql_close(conn_ptr);

	return EXIT_SUCCESS;
}
