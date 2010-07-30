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

int rscallback(void *p,int argc, char **argv, char**argvv)
{
	int i;
	*(int *)p = 0;
	for ( i = 0; i < argc; i++ )
	{
		printf(" %s = %s ", argvv[i], argv[i] ? argv[i] : "NULL" ); 
	}
	putchar('\n');
	
	return 0;
}

int main(int argc, char *argv[])
{
	sqlite3 *db;
	char *err = 0;
	int ret = 0;
	int empty = 1;

	ret = sqlite3_open("./test.db", &db);
	if (ret != SQLITE_OK)
	{
		fputs("\n",stderr);
		exit(1);
	}
	ret = sqlite3_exec(db, "select * from student;", rscallback, &empty,&err);
	if (ret != SQLITE_OK)
	{
		fputs(err,stderr);
		fputs("\n",stderr);
		sqlite3_close(db);
		exit(1);
	}
	if (empty)
	{
		fputs("table student is empty\n",stderr);
		exit(1);
	}
	sqlite3_close(db);

	return 0;
}


