#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "cgi.h"
#include "sqlite3.h"
#include "cgi_op.h"
//#define GBOOK "/tmp/a.html"

static sqlite3 *open_db(const char *filename)
{
	sqlite3 *db = 0;
	//int rc;
	int ret = 0;
	ret = sqlite3_open(filename, &db);
	if (ret != SQLITE_OK) {
		fprintf(stderr, "Can't open database: %s\n",
			sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}

	return db;
}

int main (void)
{
	sqlite3 *db;
	int ret = 0;
	char **datatable1;
	char *sql;
	char buf[256]={'\0'};
	char tbuf[256]={'\0'};
	char *zErrMsg = 0;
	int nRow,nColumn;
	cgi_init();
	cgi_init_headers();
	cgi_process_form();
	puts("<html><head><title>chaxun</title>");
   puts("<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />");
	puts("</head>");
	puts("<body bgColor=#fffff0>");
	db = open_db("OAK.db");
	sql = sqlite3_mprintf("select R_name from ResInfo where R_id = %d", atoi(cgi_param("xuanqu")));
	ret = sqlite3_get_table(db, sql, &datatable1, &nRow, &nColumn, &zErrMsg);
	if (ret != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		exit(1);
	}
	puts("<table width='70%' align='center' border=1 border-coer=#000066>");
	strcat(buf,"/var/httpd/cgi-bin/");
	strcat(buf,datatable1[1]);
	strcat(tbuf,"/opt/OAK/resources/");
	strcat(tbuf,datatable1[1]);
	if(up_file(buf, tbuf,cgi_param("ip") , "8000")){
		puts("<br />");
		puts("上传成功！");
	} else {
		puts("<br />");
		puts("上传失败！");
	}
	puts("</table>");
	puts("</form>");
	puts("</body></html>");

	cgi_end();

	return 0;
}

