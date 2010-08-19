/*
 * =====================================================================================
 *
 *       Filename:  m_contrl.c
 *
 *    Description:  this cgi(write by C) is to contrl mplayer runing on the adv board
 *
 *        Version:  1.0
 *        Created:  2009年12月30日 18时28分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangGuoDong (gdbdzgd), gdbdzgd@gmail.com
 *        Company:  akaedu
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "wrap.h"
#include "cli.h"
#include "sqlite3.h"
#include <sys/stat.h>
#include <fcntl.h>
#include "cgi.h"
#define DEBUG 0

//open sqlite3 db file
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
	int i;
	int ret = 0;
        int ret_file = 0;
	int nRow;
	int nColumn;
	int playing_flag = 0;
	int pause_flag = 0;
	char *sql;
	char *sql_file;
	char **datatable;
	char **datatable_file;
	char sendbuf[100];
	char *zErrMsg = 0;
        char playing_file[100];

	cgi_init();
	cgi_init_headers();
	cgi_process_form();
	puts("<html><head><title>视频播放控制页面</title></head><body>");
	puts("<meta http-equiv='Content-Type' content='text/html'; charset='utf-8' />");
	//get talbe
	db = open_db("OAK.db");

        //if have value ip get playing file name from database
        if(cgi_param("ip")){
                sql_file=sqlite3_mprintf("select T_vfname from TempLogInfo where T_ip='%s'",cgi_param("ip"));
                ret_file = sqlite3_get_table(db,sql_file,&datatable_file,&nRow,&nColumn,&zErrMsg);
                if (ret_file != SQLITE_OK) {
                        fprintf(stderr, "SQL error: %s\n", zErrMsg);
                        exit(1);
                }
                sprintf(playing_file,"%s",datatable_file[1]);
#if DEBUG
                printf("playing file is :%s<br>",playing_file);
#endif
        }
        //end  ->if have value ip get playing file name from database

	sql = sqlite3_mprintf("select T_ip from TempLogInfo");
	ret = sqlite3_get_table(db, sql, &datatable, &nRow, &nColumn, &zErrMsg);

	if (ret != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		exit(1);
	}
	//do action
	if (cgi_param("start")) {
		if (1 != m_cntrl("start", cgi_param("ip")))
			printf("开始 操作失败！<br>");
	}

	if (cgi_param("pause")) {
		if (1 != m_cntrl("pause", cgi_param("ip")))
			printf("暂停 操作失败！<br>");

	}

	if (cgi_param("disabletv")) {
		if (1 != m_cntrl("disable_tv", cgi_param("ip")))
			printf("黑屏 操作失败！<br>");
	}
	if (cgi_param("enabletv")) {
		if (1 != m_cntrl("enable_tv", cgi_param("ip")))
			printf("取消黑屏 操作失败！<br>");

	}

	sprintf(sendbuf, "getstat%c", '\0');

	if (cgi_param("ip")) {

		if (m_cntrl(sendbuf, cgi_param("ip"))) {
			if (0 == strncmp(sendbuf, "playing", strlen("playing"))) {
#if DEBUG
				printf("mplayer is playing\n");
#endif
				playing_flag = 0;
				pause_flag = 1;
			} else {
				playing_flag = 1;
				pause_flag = 0;
			}

			if (0 == strncmp(sendbuf, "pause", strlen("pause"))) {
#if DEBUG
				printf("mplayer is pause \n");
#endif
				playing_flag = 1;
				pause_flag = 0;
			} else {
				playing_flag = 0;
				pause_flag = 1;
			}
		}
	}
#if DEBUG

	printf("cgi_param ip = %s <br>", cgi_param("ip"));
	printf("cgi_param 查询 = %s<br> ", cgi_param("search"));
	printf("cgi_param 开始 = %s<br> ", cgi_param("start"));
	printf("cgi_param 暂停 = %s<br> ", cgi_param("pause"));
	printf("cgi_param 黑屏 = %s<br> ", cgi_param("disabletv"));
	printf("cgi_param 取消黑屏 = %s <br>", cgi_param("enabletv"));
	printf("playing flag =  %d<br>", playing_flag);
	printf("pause flag =  %d<br>", pause_flag);
#endif

	//form start
	puts("<form action    =\"m_contrl.cgi\"     method='post'");
	//table start
	puts("<table border=\"0\" width=\"100%\" height=\"100%\">");
        puts("<tr><td align= \"center\" valign= \"middle\" width=\"100%\" height=\"100%\">");
	puts("<table border=\"5\" align= \"center\" valign= \"middle\">");
	//first line of table
	puts("<tr>");
	puts("<td height=\"35\" width= \"35\">");
	if (pause_flag)
		puts("<img src = '/images/playing.gif'>");
	else if (playing_flag)
		puts("<img src = '/images/pause.gif'>");
	else
		puts("<img src = '/images/note.gif'>");
		puts("</td>");

	puts("<td ALIGN = \"middle\">");
	if (pause_flag)
		printf("正在播放:%s",playing_file);
	else if (playing_flag)
		printf("暂停播放文件:%s",playing_file);
	else
                printf("请选择IP查询");
		puts("</td>");
	puts("</tr>");
	//end first line of table
	//begin second line of table
	puts("<tr>");
	puts("<td colspan=\"2\">");

	// check stat with ip in c_param
	puts("<select NAME = \"ip\">");
	if (!cgi_param("ip"))
		puts("<option value = " "  > 选择IP</option> ");

	if (!(0 == nRow && 0 == nColumn)) {
		for (i = 1; i < nRow + 1; i++) {
			printf("<option value = \"%s\"", datatable[i]);
			if (cgi_param("ip")) {
				if (0 ==
				    strncmp(cgi_param("ip"), datatable[i],
					    strlen(datatable[i])))
					printf("SELECTED");
			}
			printf("> %s </option> ", datatable[i]);
		}
	}
	puts("<input type=\"submit\" value=\"查询\"name=\"search\"  title=\"选择好IP地址进行查询\" >");
	if (cgi_param("ip")) {
		if (playing_flag)
			puts("<input type=\"submit\" value=\"开始\"name=\"start\"  title=\"开始播放视频\" >");
		if (pause_flag)
			puts("<input type=\"submit\" value=\"暂停\"name=\"pause\"  title=\"暂停播放视频\" >");
		puts("<input type=\"submit\" value=\"黑屏\"name=\"disabletv\"  title=\"黑屏后台运行\" >");
		puts("<input type=\"submit\" value=\"取消黑屏\"name=\"enabletv\"  title=\"取消黑屏\" >");
	}
	puts("</select>");
	puts("</td>");
	puts("</tr>");
	//end second line of table
	puts("</table>");
        puts("</td></tr>");
	puts("</table>");
	//end table
	puts("</form>");
	//form end;

	sqlite3_close(db);

	puts("</body></html>");

	cgi_end();

	return 0;
}
