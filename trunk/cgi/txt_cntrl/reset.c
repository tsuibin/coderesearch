/*
 * =====================================================================================
 *
 *       Filename:  rmplayer.c
 *
 *    Description:  :
 *
 *        Version:  1.0
 *        Created:  01/10/2010 01:55:58 PM
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
	int i ;
        //int err;
	int ret = 0;
	int nRow;
	int nColumn;
	char *sql;
	char **datatable;
	char *zErrMsg = 0;
	//if ip is select get data.txt form board
	cgi_init();
	cgi_init_headers();
	cgi_process_form();
	puts("<html><head><title>TXT control</title></head><body>");
	puts("<meta http-equiv=Content-Type content=\"text/html;charset=utf-8\" >");

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
	if (cgi_param("ip") && cgi_param("reqt")){
		//get_file("data.txt", "/opt/OAK/txts/data.txt", "127.0.0.1","8080");
		//get_file("data.txt", "/opt/OAK/txts/data.txt", "192.168.0.100","8080");
		//get_file("/tmp/tmp.txt","/opt/OAK/txts/data.txt", cgi_param("ip"), "8000");
                restartqt(cgi_param("ip"),"8080");
	}
	if (cgi_param("ip") && cgi_param("rmplayer")){

                rmplayer(cgi_param("ip"),"8080");
        }

	puts("<form action    =\"reset.cgi\"     method='post'>");
	puts("<table border=\"0\" width=\"100%\" height=\"100%\">");
	puts("<tr>"
	     "<td align= \"center\" valign= \"middle\" width=\"100%\" height=\"100%\">");
	puts("<table border=\"5\" align= \"center\" valign= \"middle\">");
	puts("<tr>" "<td>" "<textarea  name = \"txtare\" style=\"COLOR:#0052a4;\" rows=\"3\" cols=\"70\">");
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
	puts("<input type=\"submit\" style=\"COLOR:#0052a4;\" value=\"重启mplayer\" name=\"rmplayer\"  title=\"重启mplayer\" >");
	puts("<input type=\"submit\" style=\"COLOR:#0052a4;\" value=\"重启QT\" name=\"reqt\"  title=\"重启QT\" >");
	puts("</td>" "</tr>" "</table>" "</td></tr>" "</table>" "</form>");
	puts("</body></html>");

	cgi_end();
	return 0;
}
