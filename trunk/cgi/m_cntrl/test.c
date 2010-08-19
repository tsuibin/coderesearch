/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
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
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "log_sql.h"


int main(int argc, char * argv[])
{
    sqlite3 * db;
    int ret = 0;
    char * err = 0;
    Log add = {"zhouqiang.c", 0, 0, "192.168.0.888"};
    Log add1 = {"zhouqiang.c", 1, 0, "192.168.0.888"}; 
    Log add2 = {"zhangguodong.c", 0, 0, "192.168.0.888"};
    

   /* ret = sqlite3_open("./OAK.db", &db); */
    do_insert(&add);
   do_insert(&add1);
    do_insert(&add2);
   /* ret = sqlite3_exec(db, "select * from LogInFo\n", 0, 0, &err);

    sqlite3_close(db); */


    return 0;
}




