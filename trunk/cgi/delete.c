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
#include "cgi_op.h"

static sqlite3 *open_db(const char *filename)
{
	sqlite3 *db = 0;
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
	int n;
	char **datatable1;
	int nRow;
	int nColumn;
	char *sql;
	int i = 1;
	char *zErrMsg = 0;
	char buf[256] = {'\0'};
	char tmp[256] = {'\0'};

	cgi_init();
	cgi_init_headers();
	cgi_process_form();
	puts("<html><head><title>shanchu</title>");
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
	puts("<form action=\"delete.cgi\">");
	puts("<table width='70%' align='left' border=1 border-coer=#000066>");
	puts("<tr><td width='20%'>");
	puts("<select NAME = \"ip\">");	
	puts("<option value = \"\"> 选择IP</option> ");
	
	if (!(0 == nRow && 0 == nColumn)) {
		for (i = 1; i <= nRow*nColumn ; i += nColumn ) {
			printf("<option value = \"%s\"", datatable1[i]);
			if (cgi_param("ip")) {
			    if (0 == strncmp(cgi_param("ip"), datatable1[i],strlen(datatable1[i])))
					  printf("SELECTED");
			}
		printf("> %s </option> ", datatable1[i]);		
		}
	}
	puts("</select>");
	puts("</td>");
	puts("<td>");
	puts("<input type=\"submit\" value=\"查询\"  name=\"search\" >");	
	puts("</td>");
	puts("<td>");
	puts("<input type=\"submit\" value=\"删除\"  name=\"delete\" >");	
	puts("</td></tr></table>");
	
	puts("<br />");
		puts("<br />");
	if(cgi_param("delete")){
		strcat(tmp,"/opt/OAK/resources/");
		strcat(tmp,cgi_param("xuanqu"));
		if(rm_file(tmp, cgi_param("ip"), "8080")){
			puts("<br />");
			puts("删除成功");
		}
	} else {
		if(cgi_param("ip")){
			get_file("playlist", "/opt/OAK/playlist", cgi_param("ip"), "8080");
		}
		puts("<table width='70%' align='left' border=1>");
		puts("<tr><td style=\"width:50px\" align=center>选择</td>");
		puts("<td style=\"width:250px\" align=center>媒体名称</td>");
		puts("</tr>");
		i = 1;
		if(cgi_param("ip")){
			while(1){		
				if((n = my_readline("playlist",buf,i)) != -1){
					puts("<tr><td align='center'><input type = 'checkbox' name='xuanqu' ");
					printf(" value=%s />", buf);
					printf("<td>%s</td></tr>",buf);
					i++;
					buf[0] = '\0';
				} else{
					break;
				}
			}
		}
		puts("</table>");
	} 
	puts("</form>");
	puts("</body></html>");

	cgi_end();

	return 0;
}

