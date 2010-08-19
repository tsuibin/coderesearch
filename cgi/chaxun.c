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
	puts("<tr><td width='20%'>");
	puts("<select NAME = \"company\">");	
	puts("<option value = \"\"> 选择公司</option> ");
	
	if (!(0 == nRow && 0 == nColumn)) {
		for (i = 1; i <= nRow*nColumn ; i += nColumn ) {
			printf("<option value = \"%s\"", datatable1[i+1]);
			if (cgi_param("company")) {
			    if (0 == strncmp(cgi_param("company"), datatable1[i+1],strlen(datatable1[i+1])))
					  printf("SELECTED");
			}
		printf("> %s </option> ", datatable1[i+2]);
		
		}
	}
	puts("</select>");
	puts("</td><td width='20%'>");
	sql = sqlite3_mprintf("select R_id,R_name from ResInfo");
	ret = sqlite3_get_table(db, sql, &datatable2, &nRow, &nColumn, &zErrMsg);
	if (ret != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		exit(1);
	}
	puts("<select NAME = \"filename\">");	
	puts("<option value =\"\"> 选择文件名</option> ");
	if (!(0 == nRow && 0 == nColumn)) {
		for (i = 1; i <= nRow*nColumn ; i += nColumn ) {
			printf("<option value = \"%s\"", datatable2[i+1]);
			if (cgi_param("filename")) {
		      if (0 == strncmp(cgi_param("filename"), datatable2[i+1],strlen(datatable2[i+1])))
					  printf("SELECTED");
			  }
			printf("> %s </option> ", datatable2[i+2]);
		}
	}
	puts("</select>");
	puts("</td><td width='20%'");		
	puts("<select NAME = \"filetype\">");	
	puts("<option value = \"\"> 选择文件类型</option> ");
	if(cgi_param("filetype")){
		if(atoi(cgi_param("filetype")) == 0){
			puts("<option value = \"0\" SELECTED>图片</option>");
			puts("<option value = \"1\">视频</option>");
		}else{
			puts("<option value = \"0\">图片</option>");
			puts("<option value = \"1\" SELECTED>视频</option>");
		}
	} else {
		puts("<option value = \"0\">图片</option>");
		puts("<option value = \"1\">视频</option>");
	}
	puts("</td><td width='10%'");
	puts("<input type=\"submit\" value=\"查询\"name=\"search\" >");
	puts("</td></tr>");
	puts("<tr><td></td></tr>");
	puts("</table>");
	if(cgi_param("search")){
	//	printf("<table><tr><td>asdfsdf</td><td>%s</td></tr></table>",cgi_param("search"));
	//	printf("<table><tr><td>asdfsdf</td><td>%s</td></tr></table>",cgi_param("company"));
		sql = sqlite3_mprintf("select L.L_ip,L.R_name,L.B_time,L.E_time from LogInfo L left join ResInfo R on L.R_name = R.R_name left join CompanyInfo C on R.C_id = C.C_id");
		strcat(buf,sql);
		if(cgi_param("company")){
			sql = sqlite3_mprintf(" where C.C_id = %s",cgi_param("company"));
			strcat(buf,sql);
		} 
		if(cgi_param("filename")){
			sql = sqlite3_mprintf(" and R.R_name = '%s'",cgi_param("filename"));	
			strcat(buf,sql);
		} 
		if(cgi_param("filetype")){
			sql = sqlite3_mprintf(" and F_type = %s",cgi_param("filetype"));
			strcat(buf,sql);
		}
		//puts("<table><tr><td></td></tr></table>");
		puts("<br />");
		puts("<br />");
		ret = sqlite3_get_table(db, buf, &datatable3, &nRow, &nColumn, &zErrMsg);
		if (ret != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			exit(1);
		}
		puts("<table width='70%' align='center' border=1>");
		puts("<tr><td style=\"width:100px\" align=center>客户机IP</td>");
		puts("<td style=\"width:150px\" align=center>媒体名称</td>");
		puts("<td style=\"width:120px\" align=center>播放开始时间</td>");
		puts("<td style=\"width:120px\" align=center>播放结束时间</td>");
		puts("</tr>");
		if (!(0 == nRow && 0 == nColumn)) {
			for (i = 4; i <= nRow*nColumn ; i += nColumn ) {
				printf("<tr><td>%s</td>", datatable3[i+0]);
				printf("<td>%s</td>", datatable3[i+1]);
				printf("<td>%s</td>",datatable3[i+2]);
				printf("<td>%s</td></tr>",datatable3[i+3]);
				//puts("</tr>");
			}
		}
		puts("</table>");
		

	}
	puts("</form>");
	puts("</body></html>");

	cgi_end();

	return 0;
}

