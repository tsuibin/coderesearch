/*
DDL(Data Definition Language)
create table student(id integer primary key,name text,grade integer,note text);

alter table student add info text;
alter table student rename to info;
alter table info rename to student;

drop table student;

.tables

.schema student
DML(Data Manipulation Language)
select * from student;
delete from student where id =1 or name='abc';
update student set age=22,name='susan' where name='abc';
insert into student values(0,'sam',4,'wuhan');
insert into student (id,name,age) values(1,'susan',18);

typedef int (*sqlite_callback)(void *pArg, int argc, char **argv, char **argvv);

int sqlite3_exec(sqlite3 *db,const char *zSql,sqlite_callback xCallback,void *pArg, char **pzErrMsg);

if zSql is not select ,not call callback function

gcc testsqlite3.c -lsqlite3

*/

#include <stdio.h> 
#include <stdlib.h> 
#include <sqlite3.h>

#define DB_NAME "./student.db"

sqlite3 *db;

typedef int (*sqlite_callback)(void *pArg, int argc, char **argv, char **argvv);

int rscallback(void *p,int argc, char **argv, char**argvv)
{
	int i;
	*(int *)p = 0; //this p poniter == &empty
	printf("here!\n"); 
	for ( i = 0; i < argc; i++ )
	{
		printf(" %s = %s ", argvv[i], argv[i] ? argv[i] : "NULL" ); 
	}
	putchar('\n');
	
	return 0;
}

void open_db()
{
	int ret = 0;
	ret = sqlite3_open(DB_NAME, &db);
	if (ret != SQLITE_OK)
	{
		fputs("\n",stderr);
		exit(1);
	}
}


void db_exec(char * sql, sqlite_callback xCallback, void *pArg, char **pzErrMsg)
{
	int ret;
	ret = sqlite3_exec(db, sql, xCallback, &pArg, pzErrMsg);
	if (ret != SQLITE_OK)
	{
		fputs(*pzErrMsg,stderr);
		fputs("\n",stderr);
		sqlite3_close(db);
		exit(1);
	}
	if (pArg)
	{
		fputs("table student is empty\n",stderr);
		exit(1);
	}
}

void operation_router(int c)
{
	char *err = 0;
	int empty = 1;

	printf("You chose : %c\n", c); 
	switch (c)
	{
		case 49: // 1
			printf("insert\n"); 
			break;
		case 50: //2
			printf("delete\n"); 
			break;
		case 51: //3
			printf("update\n");
			break;
		case 52: //4
			printf("select\n");
			db_exec("select * from student;", rscallback, &empty,&err);
			break;
		default:
			break;
	}
	printf("operation over !!! success!\n");
	printf("input 'c' to continue:\n"); 
}

void show_massage()
{
	int i = 0;
	printf("select a number\n"); 
	printf("[1] insert a student information\n"); 
	printf("[2] delete a student information\n"); 
	printf("[3] update a student information\n"); 
	printf("[3] show student information\n");
	printf("please input a number [1-4]:\n");
	i = fgetc(stdin);
	while( !(i > 48 && i < 53) )
	{
		i = fgetc(stdin);
	}
	operation_router(i) ;
}

int main(int argc, char *argv[])
{

	open_db();
	
	for (;;)
	{
		show_massage();
		while( !(99 == fgetc(stdin)) );
	}


	sqlite3_close(db);

	return 0;
}
