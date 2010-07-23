#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include "common.h"

#define DBNAME "./web.db" 
static sqlite3 *db;

struct weblink alink;

static int email_callback(void *p, int argc, char **argv, char **argvv)
{
	*(int *)p = 0;
	
        //must = 0;
	return 0;

}
static int search_callback(void *p, int argc, char **argv, char **argvv)
{
	*(int *)p = 0;
	
        //must = 0;
	return 0;

}
static int record_callback(void *p, int argc, char **argv, char **argvv)
{

	//the p = &empty;
	*(int *) p = 0;
	

	alink.id = atoi(argv[0]);
	strcpy(&alink.domain[0],argv[1]);
	alink.page_len = strlen(argv[2]);
	alink.page = malloc (alink.page_len+1);
	if (alink.page == NULL)
	{
		printf ("malloc page_len %d\n",alink.page_len);
		return 0;	
	}
	strcpy(alink.page,argv[2]);

        printf ("\n");
	return 0;    
}

int search_record(char *domain,char *page)
{
    char *sql = NULL;
    int empty = 1;   
    int ret;

    sql = sqlite3_mprintf("select * from weblink where page = %Q and domain=%Q",page,domain);    

    ret = sqlite3_exec(db, sql, search_callback, &empty, NULL);
    sqlite3_free(sql);    
    if(ret != SQLITE_OK) {
        fputs("search select error\n",stderr);
    }    
    if (!empty)
	return 1;

    return 0;

}

int search_email_record(char *name)
{
    char *sql = NULL;
    int empty = 1;   
    int ret;

    sql = sqlite3_mprintf("select * from email where name = %Q ",name);    

    ret = sqlite3_exec(db, sql, email_callback, &empty, NULL);
    sqlite3_free(sql);    
    if(ret != SQLITE_OK) {
        fputs("search select error\n",stderr);
    }    
    if (!empty)
	return 1;

    return 0;

}

int insert_email(char *name,char *page,char *fromdomain)
{
    char *sql = NULL;
    int ret;

    ret = search_email_record(name);

    if (ret)
 	return 0;

    sql = sqlite3_mprintf("insert into email(name,fromdomain,page)"
			  " values(%Q,%Q,%Q)", 
                          name,fromdomain,page);    

    ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
    sqlite3_free(sql);    
    if(ret != SQLITE_OK) {
        fputs("insert error\n",stderr);
    }    
    return ret;
}    



int insert_db(char *domain,char *page,char *fromdomain,int status)
{
    char *sql = NULL;
    int ret;

    ret = search_record(domain,page);

    if (ret)
 	return 0;

    sql = sqlite3_mprintf("insert into weblink(domain,page,fromdomain,status)"
			  " values(%Q,%Q,%Q,%d)", 
                          domain,page,fromdomain,status);    

    ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
    sqlite3_free(sql);    
    if(ret != SQLITE_OK) {
        fputs("insert error\n",stderr);
    }    
    return ret;
}    

int insert_link(char *link)
{
	char domain2[64];
	char * page;

	if (!strncmp(link,"http://",7))
	{
		memset(domain2,0,64);
		page = strstr(link + 7,"/");
		if (page == NULL)
		{
		    page="/";
		    strcpy(domain2,link+7);
		} 
		else
		{
			strncpy(domain2,link+7,page-link-7);
		}

		insert_db(domain2,page,use_domain,1);
		return 0;
	}

	insert_db(use_domain,link,use_domain,1);
	return 0;
}

int update_db(int id,int status)
{
    char *sql = NULL;
    int ret;
   
    sql = sqlite3_mprintf("update weblink set status=%d where id=%d", 
                          status,id);    

    ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
    sqlite3_free(sql);    
    if(ret != SQLITE_OK) {
        fputs("update error\n",stderr);
    }    
    return ret;
}
    
struct weblink *get_a_record(void)
{
    char *sql = NULL;
    int empty = 1;   
    int ret;

    sql = sqlite3_mprintf("select * from weblink where status=1 order by id asc limit 0,1 ");    

    ret = sqlite3_exec(db, sql, record_callback, &empty, NULL);
    sqlite3_free(sql);    
    if(ret != SQLITE_OK) {
        fputs("select error\n",stderr);
    }    
    if (!empty)
	return &alink;

    return NULL;

}
void db_close (void)
{
    sqlite3_close(db);
}

int init_sqlite(char *dataname)
{
    int ret;

    ret = sqlite3_open(dataname, &db);
     
    if(ret != SQLITE_OK) {
        fputs(sqlite3_errmsg(db), stderr);
        fputs("\n", stderr);
        exit(1);
    }
#if 0    
    insert_db ("www.gnu.org","/","www.akaedu.com",1);
    get_a_record ();
    update_db (1,2);

    db_close ();
#endif
    return 0;
}


