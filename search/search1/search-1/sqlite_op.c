#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define DBNAME "./web.db" 
static sqlite3 *db;

struct weblink{
	char domain[64];
	char *page;
	char page_len;
	int id;
};

struct weblink alink;

static int search_callback(void *p, int argc, char **argv, char **argvv)
{
	*(int *)p = 0;
	
        //must = 0;
	return 0;

}
static int record_callback(void *p, int argc, char **argv, char **argvv)
{
//    	int i;

	//the p = &empty;
	*(int *) p = 0;
	
//	for (i = 0;i < argc;i++)
//		printf ("%s=%s ",argvv[i],argv[i]?argv[i]:"NULL");

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
    
struct weblink *get_a_record()
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

int main(void)
{
    int ret;

    ret = sqlite3_open("./web.db", &db);
     
    if(ret != SQLITE_OK) {
        fputs(sqlite3_errmsg(db), stderr);
        fputs("\n", stderr);
        exit(1);
    }
    
    insert_db ("www.gnu.org","/","www.akaedu.com",1);
    get_a_record ();
    update_db (1,2);

    db_close ();
    return 0;
}


