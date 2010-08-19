#include <stdio.h>
#include <string.h>
#include "cgi.h"
#include <stdlib.h>
#include "sqlite3.h"
#define DATEBASE "OAK.db"

int main(int argc, char *argv[])
{
	cgi_init();
	cgi_session_start();
	cgi_process_form();
	cgi_init_headers();

	sqlite3 *db;
	char *err = 0;
	char *sql = NULL;
	char **result=NULL;
	int row=0,col=0;
	int ret = 0;
	ret = sqlite3_open(DATEBASE,&db);
	if(ret != SQLITE_OK)
	{
		fputs(sqlite3_errmsg(db),stderr);
		fputs("\n",stderr);
		exit(1);
	}
	sql = sqlite3_mprintf("select U_prim from UserInfo where U_id='%s' and U_pwd='%s'",
						  cgi_param("user"),cgi_param("password"));
	ret = sqlite3_get_table(db,sql,&result,&row,&col,&err);
	if(ret != SQLITE_OK)
	{
		fputs(err,stderr);
		fputs("\n",stderr);
		sqlite3_close(db);
		exit(1);
	}
	if(col == 0 && row == 0)
	{
		/* 修改路径 */
		printf("bad input");
		printf("%s  ",cgi_param("user"));
		cgi_include ("../htdocs/login.html");
	}
	else
	{
		cgi_session_register_var("logged",result[1]);
		/* 修改系统用户跳转页面地址 */
		cgi_include("../htdocs/main.html");	
	}
	sqlite3_free_table(result);
	sqlite3_close(db);
	cgi_end();
	return 0;
}
