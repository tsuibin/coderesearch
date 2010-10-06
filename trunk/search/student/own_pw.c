#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#define DBNAME "web.db" //数据库名字

int status = 1 ;
int m = 1;
char domain[128] = {"file:///home/tsuibin/index.html"};
char page[256] = {"/"};
sqlite3 *db;

void insert_db (void);

int str_cmp ( char *m, char*n )
{
	int j;
	for(j= 0; n[j]!= '\0'; j ++)
	{	
		if (m[j]!=n[j])
			return -1;
		else
			continue;
	}

	return 0;

}

void  s_page( char *w )     //PAGE获取
{	
	char *key="http://";
	int i,j = 0,ret;

	memset(page, 0, 256);
	ret = str_cmp(w, key);	
	if( ret != 0 )
	{
		printf("%d\n",ret);
		for(i = 0 ; w[i] != '\0' ; i ++)
			page[j++] = w[i]; 
	}
	else 
	{	
		//printf("%d\n",ret);
		for(i = 7; w[i] != '/'; i++);
		for(i ; w[i] != '\0' ; i++)
			page[j++] = w[i];
	}		
	page[j] = '\0';
	//printf("%s\n",page);

	return ;
}

int re_web (char *p)
{
	char a[200];        
	char *key1 = "<a";
	char *key2 = "href";
	char *key3 = "=";
	int len1,len2,len3;
	len1 = strlen(key1);
	len2 = strlen(key2);
	len3 = strlen(key3);
	int i = 0;
	int j, ret ;
	int flag = 0;

	for(i;i<=1024;)
	{
		memset(a , 0 , 200);
		j = 0 ;
		for(i= i; p[i] !='\0';i++)
		{
			ret = str_cmp(&p[i],key1);
			if(ret == 0)
			{
				flag = 0;
				break;
			}
				flag = 1;
				printf("can't find\n"); 
				continue;
		}
		printf("%d here 1\n",i); 
//		if (flag) break;

		for(i= i + strlen(key1); p[i] !='\0';i++)
		{
			ret = str_cmp(&p[i],key2);
			if(ret == 0 ) 
				break;
			else
				continue;

		}

		for(i = i + strlen(key2); p[i] !='\0';i++)
		{
			ret = str_cmp(&p[i],key3);
			if(ret == 0)
				break;
			else
				continue;
		}
		
		for(i = i+strlen(key3); p[i]!='\0'; i++)
		{
			if(p[i] == '\"' || p[i] == '/' || p[i]==' ' || p[i]=='\'' )
				continue;
			else
				while	(	p[i] != '\"' && p[i]!=' ' && p[i] !='\'' 
						&& p[i] != '\0'&& p[i]!='<' && p[i]!='>'
						&& p[i]!='{' && p[i]!='}' && p[i]!='#' )
				{
					a[j]=p[i];
					printf("a[%d] %c\n",j,a[j]); 
					i++;
					j++;
				}

				printf("jumped\n"); 
			//s_page(a);
			break;

		}
		printf("jumped key3\n"); 
	}
	return 0 ;
}

int web_fenxi (void)
{
	int ret;
	char buf[1024];
	FILE *fp;

	fp=fopen("webinfo","r");
	if(fp==NULL)
	{
		printf("open file %s error!\n","webinfo");
		return -1;
	}

	while(1)
	{
		memset(buf,0,1024);
		ret = fread(buf,1,1024,fp);
		if(ret == 0)
			break;
		re_web(buf);
	}

	fclose(fp);

	return 0;
}

void create(void)
{
	char *str = "create table web(id integer primary key,status integer,domain text ,page text)";
	int ret ;
	ret = sqlite3_exec(db,str,NULL ,NULL,NULL);
	if(ret !=SQLITE_OK )
	{
		printf("create table error\n");
		return ;
	}
	return ;
}
void insert_db (void)
{
	char *sql = NULL;
	int ret;

	sql = sqlite3_mprintf("insert into web(status,domain,page)"
			" values(%d,%Q,%Q)", 
			status, domain, page);    

	ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
	sqlite3_free(sql);    
	if(ret != SQLITE_OK) 
	{
		printf("insert error\n");
		return ;
	}    
	return ;
}   

int record_callback(void *p, int argc, char **argv, char **argvv)
{
	int i ;
	for(i = 0 ; argv[2][i] != '\0' ; i++)
		domain[i] = argv[2][i];
	for(i = 0 ; argv[3][i] != '\0' ; i++)
		page[i] = argv[3][i];

	//	domain = argv[2];		//printf ("page = %s",argv[2]);
	//	page = argv[3];			//printf ("domain = %s\n",argv[3]);

	return 0;    
}

void get_a_record (void)
{
	char *sql = NULL;
	int ret;

	sql = sqlite3_mprintf("select * from web where status=1 order by id asc limit 0,1");    
	ret = sqlite3_exec(db, sql, record_callback, NULL, NULL);
	//    sqlite3_free(sql);    
	if(ret != SQLITE_OK) 
		printf("select information error !\n");

	return ;
}

void  wget(char *b )
{
	char s[100];
	char *a="wget -O webinfo ";
	sprintf(s,"%s%s",a,b);
	//	printf("%s",s);
	system(s);

	return ;

}
/*
   int my_printf_callback(void *p, int argc, char **argv, char **argvv)
   {

   printf ("id = %s",argv[0]);
   printf ("status = %s",argv[1]);
   printf ("domain = %s",argv[2]);
   printf ("page = %s\n",argv[3]);

   return 0;    
   }

   void my_printf_record (void)
   {
   char *sql = NULL;
   int ret;

   sql = sqlite3_mprintf("select * from web ");    
   ret = sqlite3_exec(db, sql, my_printf_callback, NULL, NULL);
   sqlite3_free(sql);    
   if(ret != SQLITE_OK) 
   printf("search select error !\n");   

   return ;

   }

   void update_db(int a)
   {
   char *sql = NULL;
   int ret;

   sql = sqlite3_mprintf("update web set status=%d where id=%d", 
   a,m++);    
   ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
   sqlite3_free(sql);    
   if(ret != SQLITE_OK) 
   printf("update error\n");

   return ;
   }
 */
int main (void)
{	int i=1;
	int ret;
	char weblink[385];

	ret = sqlite3_open(DBNAME, &db);


	if(ret != SQLITE_OK)
		printf("open %s error !",DBNAME);    	

//	create();		

//	insert_db ();

	while(i == 1)
	{
		memset(weblink, 0 ,385);
		//sprintf(weblink,"%s%s",domain,page);	
	//	wget(weblink);	//得到 webinfo文件	
		web_fenxi();
	i--;

	}

	return 0;
}


