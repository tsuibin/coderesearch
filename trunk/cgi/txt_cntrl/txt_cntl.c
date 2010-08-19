/*
 * =====================================================================================
 *
 *       Filename:  mytest.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/09/2010 05:11:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangGuoDong (gdbdzgd), gdbdzgd@gmail.com
 *        Company:  akae
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <netinet/in.h>
#include <fcntl.h>
#include "cgi.h"
#include "sqlite3.h"
#include "cgi_op.h"
#include "wrap.h"
#include "cli.h"
//#include "cgi_op.c"
#define DEBUG 0

void putsstyle(void )
{
        puts(""
"<style type=\"text/css\">"
"<!--"
".BB {line-height: 40px;	font-size: 36px;}"
".style6{letter-spacing: normal; font-size: 9px; font-family: Arial;}"
".style7{line-height: 12px; letter-spacing: normal; word-spacing: normal; font-family: Arial; font-size: 12px; }"
".style8{font-size: 12px;letter-spacing: 5px;}"
".style16{font-family:\"黑体\"; color=\"#0052a4\";}"
".style18 {font-size: 26px}"
".style23 {font-family: Arial; font-weight: bold; font-size: 15px;}"

".style26 {font-size: 14px; font-family: \"宋体\"}"

"td {font-family: \"宋体\", \"Times New Roman\";	font-size: 12px; color: #0052A4;}"
"-->"
"</style>"
"");
}
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

int main(void)
{
	sqlite3 *db;
	//char *err = 0;
	int tfd, i, n,senfd;
        //int err;
	int ret = 0;
	int nRow;
	int nColumn;
	char *sql;
	char **datatable;
	char buf[FD_SETSIZE];
	char outbuf[FD_SETSIZE];
	char *zErrMsg = 0;
	//if ip is select get data.txt form board
	cgi_init();
	cgi_init_headers();
	cgi_process_form();
	puts("<html><head><title>TXT control</title></head><body>");
	puts("<meta http-equiv=Content-Type content=\"text/html;charset=utf-8\" >");
        putsstyle();

	//open database file 
	db = open_db("OAK.db");
	sql = sqlite3_mprintf("select T_ip from TempLogInfo");
	ret = sqlite3_get_table(db, sql, &datatable, &nRow, &nColumn, &zErrMsg);

	if (ret != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		exit(1);
	}
#if 0 

        printf("selected ip is %s<br>",cgi_param("ip"));
        printf("txtarea  is %s <br> ",cgi_param("txtare"));
        if(cgi_param("txtare"))
                printf("txtarea length is %d<br>",strlen(cgi_param("txtare")));
#endif
        //if ip get txt from board
        //if(1){
	if (cgi_param("ip")){
		//get_file("data.txt", "/opt/OAK/txts/data.txt", "127.0.0.1","8080");
		get_file("data.txt", "/opt/OAK/txts/data.txt", cgi_param("ip"),"8080");
		//get_file("data.txt", "/opt/OAK/txts/data.txt", "192.168.0.100","8080");
		//get_file("/tmp/tmp.txt","/opt/OAK/txts/data.txt", cgi_param("ip"), "8000");
		if (0 > (tfd = open("data.txt", O_RDONLY)))
			printf("can.t open data.txt\n");
	}
        //if ip && setone checked send to board
        if (cgi_param("ip") && cgi_param("setone")){
               senfd = open("data.txt",O_RDWR | O_CREAT | O_TRUNC, 0777);
               if(senfd < 0)
                        perr_exit("up open data.txt");
               write(senfd,cgi_param("txtare"),strlen(cgi_param("txtare")));
               close(senfd);
               up_file("data.txt","/opt/OAK/txts/data.txt",cgi_param("ip"),"8080");
        }
        //if setall checked send to all board
        if (cgi_param("ip") && cgi_param("setall")){
               senfd = open("data.txt",O_RDWR | O_CREAT | O_TRUNC, 0777);
               if(senfd < 0)
                        perr_exit("up open data.txt");
               write(senfd,cgi_param("txtare"),strlen(cgi_param("txtare")));
               close(senfd);
		for (i = 1; i < nRow + 1; i++) {
                        up_file("data.txt","/opt/OAK/txts/data.txt",datatable[i],"8080");
                }
        }

	puts("<form action    =\"txt_cntl.cgi\"     method='post'>");
	puts("<table border=\"0\" width=\"100%\" height=\"100%\">");
	puts("<tr>"
	     "<td align= \"center\" valign= \"middle\" width=\"100%\" height=\"100%\">");
	puts("<table border=\"5\" align= \"center\" valign= \"middle\">");
	puts("<tr>" "<td>" "<textarea  name = \"txtare\" style=\"COLOR:#0052a4;\" rows=\"3\" cols=\"70\">");
        //err = write(1,"test",4);
        //printf("err is  %d \n",err);
	if (cgi_param("ip")){
	//if (0){
		while ((n = read(tfd, buf, FD_SETSIZE))) {
                 //       write(STDOUT_FILENO , buf , n);
			snprintf(outbuf, n+1, "%s%c", buf, '\0');
			printf("%s", outbuf);
		}
                close(tfd);
        }

	puts("</textarea>");
	puts("</td>" "</tr>" "<tr>""<td>");
	puts("<select NAME = \"ip\"style=\"COLOR:#0052a4;\">");
	if (!cgi_param("ip"))
		puts("<option value = "" > 选择IP</option>");

	if (!(0 == nRow && 0 == nColumn)) {
		for (i = 1; i < nRow + 1; i++) {
			printf("<option value = \"%s\" ", datatable[i]);
			if (cgi_param("ip")) {
				if (0 ==
				    strncmp(cgi_param("ip"), datatable[i],
					    strlen(datatable[i])))
					printf("SELECTED");
			}
			printf("> %s </option> ", datatable[i]);
		}
	}
	puts("</select>");
	puts("<input type=\"submit\" style=\"COLOR:#0052a4;\" value=\"查询\"name=\"search\"  title=\"选择好IP地址进行查询\" >");
	puts("<input type=\"submit\" style=\"COLOR:#0052a4;\" value=\"根据所选IP上传\"name=\"setone\"  title=\"只更改所选IP播放文字内容\" >");
	puts("<input type=\"submit\" style=\"COLOR:#0052a4;\" value=\"上传到所有广告机\"name=\"setall\"  title=\"所有广告机文字统一更改\" >");
	puts("<input type=\"submit\" disabled = \"true\" value=\"高级配置\"name=\"disabletv\"  title=\"列出所有广告机选择配置\" >");
	puts("</td>" "</tr>" "</table>" "</td></tr>" "</table>" "</form>");
	puts("</body></html>");

	cgi_end();
	return 0;
}
