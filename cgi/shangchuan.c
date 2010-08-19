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
	char **datatable3;
	int nRow;
	int nColumn;
	char *sql;
	int i;
	char *zErrMsg = 0;

	cgi_init();
	cgi_init_headers();
	cgi_process_form();
	puts("<html><head><title>chaxun</title>");
   puts("<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />");
	//puts("<link href=\"/Style.css\" rel=\"stylesheet\" type=\"text/css\" />");
	puts("</head>");
	puts("<body bgColor=#fffff0>");
	db = open_db("OAK.db");
	sql = sqlite3_mprintf("select * from IpInfo");
	ret = sqlite3_get_table(db, sql, &datatable1, &nRow, &nColumn, &zErrMsg);
	if (ret != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		exit(1);
	}
	puts("<form action=\"load.cgi\">");
	puts("<table width='70%' align='left' border=1 border-coer=#000066>");
	puts("<tr><td width='20%'>");
	puts("<select NAME = \"ip\">");	
	puts("<option value = \"\"> 选择IP</option> ");
	
	if (!(0 == nRow && 0 == nColumn)) {
		for (i = 1; i <= nRow*nColumn ; i += nColumn ) {
			printf("<option value = \"%s\"", datatable1[i]);
			if (cgi_param("company")) {
			    if (0 == strncmp(cgi_param("ip"), datatable1[i],strlen(datatable1[i])))
					  printf("SELECTED");
			}
		printf("> %s </option> ", datatable1[i]);		
		}
	}
	puts("</select>");
	puts("</td>");
	puts("<td>");
	puts("<input type=\"submit\" value=\"上传\"  name=\"action\" >");	
	puts("</td></tr></table>");
	sql = sqlite3_mprintf("select R.R_id,R.R_name,R.R_flag,C.C_name from ResInfo R left join CompanyInfo C on R.C_id = C.C_id;");
	puts("<br />");
		puts("<br />");
		ret = sqlite3_get_table(db, sql, &datatable3, &nRow, &nColumn, &zErrMsg);
		if (ret != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			exit(1);
		}
		puts("<table width='70%' align='left' border=1>");
		puts("<tr><td style=\"width:50px\" align=center>选择</td>");
		puts("<td style=\"width:150px\" align=center>媒体名称</td>");
		puts("<td style=\"width:120px\" align=center>媒体类型</td>");
		puts("<td style=\"width:170px\" align=center>所属公司</td>");
		puts("</tr>");
		if (!(0 == nRow && 0 == nColumn)) {
			for (i = 4; i <= nRow*nColumn ; i += nColumn ) {
				puts("<tr><td align='center'><input type = 'checkbox' name='xuanqu' ");
				printf(" value=%s />", datatable3[i+0]);
				puts("</td>");
				printf("<td>%s</td>", datatable3[i+1]);
				if(atoi(datatable3[i+2]) == 0){
					printf("<td>视频文件</td>");
				} else {
					printf("<td>图片文件</td>");		
				}				
				printf("<td>%s</td></tr>",datatable3[i+3]);
			}
		}
		puts("</table>");
	puts("</form>");
	puts("</body></html>");

	cgi_end();

	return 0;
}

