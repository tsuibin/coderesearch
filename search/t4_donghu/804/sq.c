#include <stdio.h>
#include <stdlib.h>
#include "mail.h"

int ret = 0;
int empty =1;
char *err = 0;
sqlite3 *db;

void create_table(void)
{
	ret = sqlite3_open("./mail.db", &db);
	if (ret != SQLITE_OK)
	{
		fputs("\n",stderr);
		exit(1);
	}
	sqlite3_exec(db, "create table MAIL(ID integer primary key, MAIL text);", NULL, &empty, &err);
}

void insert_table(int id, char * mail)
{	
	char *sql = sqlite3_mprintf("insert into MAIL(MAIL) values('%s');",mail);
	ret = sqlite3_exec(db, sql, NULL, &empty, &err);
	sqlite3_free(sql);
	if (ret != SQLITE_OK)
	{
		fputs(err, stderr);
		fputs("\n",stderr);
		sqlite3_close(db);
		exit(1);
	}
}

void delete_table(int id)
{
	char *sql = sqlite3_mprintf("delete from MAIL where ID = %d;",id);
	ret = sqlite3_exec(db, sql, NULL, &empty, &err);
	sqlite3_free(sql);
	if (ret != SQLITE_OK)
	{
		fputs(err, stderr);
		fputs("\n", stderr);
		sqlite3_close(db);
		exit(1);
	}
}

void update_table(int id, char * mail)
{	
	char *sql = sqlite3_mprintf("update MAIL set MAIL = '%s' where ID = %d;", mail, id);
	ret = sqlite3_exec(db, sql, NULL, &empty, &err);
	sqlite3_free(sql);
	if (ret != SQLITE_OK)
	{
		fputs(err, stderr);
		fputs("\n", stderr);
		sqlite3_close(db);
		exit(1);
	}	
}

void select_table(void)
{	
	ret = sqlite3_exec(db, "select * from MAIL;", rscallback, &empty, &err);
	if (ret != SQLITE_OK)
	{
		fputs(err, stderr);
		fputs("\n", stderr);
		sqlite3_close(db);
		exit(1);
	}
	printf("\n");
}

int rscallback(void *p, int argc, char **argv, char **argvv)
{
	int i;
	*(int *)p = 0;
	for (i = 0; i < argc; i++)
	{
		printf(" %s = %s ", argvv[i], argv[i]? argv[i]: "NULL");
	}
	putchar('\n');

	return 0;
}
