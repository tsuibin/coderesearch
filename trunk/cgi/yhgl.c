#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "sqlite3.h"
#include "cgi.h"

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
	//char *err = 0;
	int ret = 0;
	char **datatable1;
	char **datatable2;
	char **datatable3;
	int nRow;
	int nColumn;
	char *sql;
	int i;
	char *zErrMsg = 0;
	char buf[1024]={'\0'};

	cgi_init();
	cgi_init_headers();
	cgi_process_form();
	puts("<html><head><title>chaxun</title>");
   puts("<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />");
	//puts("<link href=\"/Style.css\" rel=\"stylesheet\" type=\"text/css\" />");
	puts("</head>");
	puts("<body bgColor=#fffff0>");
	db = open_db("OAK.db");
	sql = sqlite3_mprintf("select C_id,C_name from CompanyInfo");
	ret = sqlite3_get_table(db, sql, &datatable1, &nRow, &nColumn, &zErrMsg);
	if (ret != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		exit(1);
	}
	puts("<form search=\"chaxun.cgi\">");
	puts("<table width='70%' align='center' border=1 border-coer=#000066>");
	puts("<tr><td width='25%'>");
	puts("<input type=\"submit\" value=\"查询\"name=\"search\" >");
	puts("</td><td width='25%'>");	
	puts("<td width='20%'");
	puts("<input type=\"submit\" value=\"添加\"name=\"delete\" >");
	puts("</td></tr>");
	puts("<tr><td></td></tr>");
	puts("</table>");
	if(cgi_param("search")){
		sql = sqlite3_mprintf("select U_id,U_pwd,U_prim from UserInfo");
		puts("<br />");
		puts("<br />");
		ret = sqlite3_get_table(db, sql, &datatable3, &nRow, &nColumn, &zErrMsg);
		if (ret != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			exit(1);
		}
		puts("<table width='70%' align='center' border=1>");
		puts("<tr><td style=\"width:100px\" align=center>用户名</td>");
		puts("<td style=\"width:150px\" align=center>密码</td>");
		puts("<td style=\"width:120px\" align=center>用户权限</td>");
		puts("<td style=\"width:120px\" align=center>修改</td>");
		puts("</tr>");
		if (!(0 == nRow && 0 == nColumn)) {
			for (i = 3; i <= nRow*nColumn ; i += nColumn ) {
				printf("<tr><td>%s</td>", datatable3[i+0]);
				printf("<td>%s</td>", datatable3[i+1]);
				printf("<td>%s</td>",datatable3[i+2]);
				printf("<td><input type=\"submit\" value=\"修改\"name=%s >",datatable3[i]);
				printf("<input type=\"submit\" value=\"删除\"name=%s ></td></tr>",datatable3[i]);
			}
		}
		puts("</table>");
		

	}
	puts("</form>");
	puts("</body></html>");

	cgi_end();

	return 0;
}

