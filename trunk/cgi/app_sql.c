/*
 * =====================================================================================
 *
 *       Filename:  app_sqlite.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2009年12月30日 13时37分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangGuoDong (gdbdzgd), gdbdzgd@gmail.com
 *        Company:  akaedu
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include <time.h>

#include "log_sql.h"

#define LEN 258

static void currtime(char * tim);
static void add_log(sqlite3 * db, Log * to_add, char * tim);
static void update_log(sqlite3 * db, Log * to_add, char * tim);
static void insert_temp(sqlite3 * db, Log * to_add);


int do_insert(Log * to_add)
{  
      
    int   flag;                           /* 0－播放开始 1－ 播放结束                 */
    int   ret_log   = 0;
    char  * err = 0;
    char tim[LEN];
    sqlite3 * db;

    /* 打开数据库 */
    ret_log = sqlite3_open("./OAK.db", &db);
    if ( ret_log != SQLITE_OK)
    {
        fputs(sqlite3_errmsg(db), stderr);
        fputs("\n", stderr);
        exit(1);

    }

    currtime(tim);                                      /* 获取当前服务器时间 */
    flag = to_add->timetype;
    if (flag == 0){
        add_log(db, to_add, tim); 
        insert_temp(db, to_add);
    }
    else if (flag == 1)
        update_log(db, to_add, tim);

    sqlite3_close(db);
    return 1;
}



/* 获取服务器时间  */
void currtime(char * tim) 
{
    time_t stime;

    stime = time(NULL);
    strftime(tim, LEN, "%Y-%m-%d %X", localtime(&stime));

}


/*  插入数据 */
void add_log(sqlite3 * db, Log * to_add, char * tim)
{
    int  ret = 0;
    char * err = 0;
    char sql[LEN];

    sprintf(sql, "INSERT INTO LogInfo (L_ip, R_name, B_time, F_type) VALUES('%s', '%s', '%s', %d)",\
            to_add->ipaddress, to_add->filename, tim, to_add->filetype); 
    ret = sqlite3_exec(db, sql, 0, 0, &err);
    if (ret != SQLITE_OK)
    {
        fputs(err, stderr);
        fputs("\n", stderr);
        sqlite3_close(db);
        exit(1);
    }
    return ;
}

/*  修改数据 */
void update_log(sqlite3 * db, Log * to_add, char * tim)
{
    int ret1    = 0;
    char * err1 = 0;
    char sql1[LEN];

    sprintf(sql1, "update LogInfo set E_time='%s' where L_ip='%s' and R_name='%s' and E_time is NULL",\
            tim, to_add->ipaddress, to_add->filename ); 
    ret1 = sqlite3_exec(db, sql1, 0, 0, &err1);
    if (ret1 != SQLITE_OK)
    {
        fputs(err1, stderr);
        fputs("\n", stderr);
        sqlite3_close(db);
        exit(1);
    }
    return;
}


void insert_temp(sqlite3 * db, Log * to_add)
{

    int ret_temp = 0;
    int nrow;
    int ncolumn;
    char *errtemp = NULL;
    char **dbresult;
    char sql_temp[LEN];
    char sql1_temp[LEN];
    char sql2_temp[LEN];
    char sql3_temp[LEN];
    char sql4_temp[LEN];

    sprintf(sql_temp, "select T_ip='%s' from TempLogInfo", to_add->ipaddress);  
    sprintf(sql1_temp, "insert into TempLogInfo (T_ip, T_vfname) values ('%s', '%s')", \
            to_add->ipaddress, to_add->filename);  
    sprintf(sql2_temp, "insert into TempLogInfo (T_ip, T_pfname) values ('%s', '%s')", \
            to_add->ipaddress, to_add->filename);  
    sprintf(sql3_temp, "update TempLogInfo set T_vfname= '%s' where T_ip='%s'", \
            to_add->filename, to_add->ipaddress);  
    sprintf(sql4_temp, "update TempLogInfo set T_pfname= '%s' where T_ip='%s'", \
            to_add->filename, to_add->ipaddress);  

    ret_temp = sqlite3_get_table(db, sql_temp, &dbresult, &nrow, &ncolumn, &errtemp);
    if ((nrow != 0) && (ncolumn != 0) )
     {
            if (to_add->filetype == 0)
                ret_temp = sqlite3_exec(db, sql3_temp, 0, 0, &errtemp);
            else if (to_add->filetype == 1)
                ret_temp = sqlite3_exec(db, sql4_temp, 0, 0, &errtemp);
    }
    else
    {
            if (to_add->filetype == 0)
                ret_temp = sqlite3_exec(db, sql1_temp, 0, 0, &errtemp);
            else if (to_add->filetype == 1)
                ret_temp = sqlite3_exec(db, sql2_temp, 0, 0, &errtemp);
    }

    return ;
}








    

    







