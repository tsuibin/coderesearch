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
#define DEBUG 1

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
	//int i;
        int ret_file = 0;
	int nRow;
	int nColumn;
	char *sql_file;
	char **datatable_file;
	//char sendbuf[100];
	char *zErrMsg = 0;
        char playing_file[100];
        char cgi_param[100]="192.168.0.100";
	//get talbe
	db = open_db("OAK.db");


        //if have value ip get playing file name from database
        if(cgi_param){
                printf("ip is avalueble: %s <br>",cgi_param) ;
                sql_file=sqlite3_mprintf("select T_vfname from TempLogInfo where T_ip='%s'",cgi_param);
                ret_file = sqlite3_get_table(db,sql_file,&datatable_file,&nRow,&nColumn,&zErrMsg);
                if (ret_file != SQLITE_OK) {
                        fprintf(stderr, "SQL error: %s\n", zErrMsg);
                        exit(1);
                }
                printf("playing file is :%s",datatable_file[0]);
                sprintf(playing_file,"%s",datatable_file[1]);
                printf("playing file is :%s",playing_file);
        }
        //end  ->if have value ip get playing file name from database


	return 0;
}
