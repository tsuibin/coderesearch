#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#define DBNAME "web.db" //数据库名字

int status = 0 ;
int m = 1;
char domain[100] = {"http://style.sina.com.cn"};
char domain_1[100];
char page[200] = {"/"};
sqlite3 *db;
void my_printf_record (void);
int  insert_db (void);



int str_cmp ( char *m, char*n )
{
	int j;
	for(j= 0; n[j]!= '\0'; j ++)
	{	
		if (m[j]!=n[j])
			return 1;
		else
			continue;
	}

	return 0;

}

void  s_page( char *w )     //PAGE获取
{
//	printf("a= %s\n",w); 
	char key[8]="http://";
	char key0[2]="/";
	int i , j , flag;
	char idomain[91];
	char page_1[200];
	memset(domain, 0, 100);
	memset(page, 0, 200);
	memset(idomain, 0, 91);
	memset(page_1,0,200);
	flag = str_cmp(w , key);

	if(flag)
	{	
		j = 0;
//		page[j++] = '/';
		for(i = 0 ; w[i] != '\0'; i++)
			page_1[j++] = w[i] ;
			if(page_1[0] != '/')
			sprintf(page,"%s%s",key0,page_1);
		strcpy(domain , domain_1);
//		printf("domain1= %s\npage1= %s\n",domain,page);
			return ;
	}

	else

	{	j = 0;
		for(i = 7 ; w[i] != '/' && w[i] != '\0' ; i++)
			idomain[j++] = w[i];
		sprintf(domain, "%s%s", key,idomain);
		if(strlen(domain)<13)
		{
			memset(domain,0,100);
			strcpy(domain,domain_1);
		}
		
		j = 0;
		for(i ; w[i] != '\0'; i++)
			page[j++] = w[i];
//		printf("domain0=%s\npage0=%s\n",domain,page); 
		return ;
	}

	return ; 
}

int re_web (char *p)
{
	char a[300];        
	char *key1="<a";
	char *key2="href";
	char *key3="=";
	int len1,len2,len3;
	len1=strlen(key1);
	len2=strlen(key2);
	len3=strlen(key3);
	int i = 0;
	int j, ret,flag ;

	for(i ;i <= 1024;)
	{

		memset(a , 0 , 300);
		j = 0;
		for(i ; p[i] !='\0';i++)
		{
			ret = str_cmp(&p[i],key1);
			if(ret == 0)
			{	flag = 0 ;
				break;
			}
			else
			{	flag = 1 ;
				continue;
			}
			
		}
		if( flag ) 
			break;

		for(i= i+strlen(key1); p[i] !='\0';i++)
		{
			ret = str_cmp(&p[i],key2);
			if(ret == 0 ) 
				break;
	                else
				continue;

	        }
		for(i= i+strlen(key2); p[i] !='\0';i++)
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
			while(p[i] != '\"' && p[i]!=' ' && p[i] !='\'' && p[i] != '\0'&& p[i]!='<' && p[i]!='>'&&p[i]!='{'&&p[i]!='}'&&p[i]!='#')
			{
				a[j++]=p[i];
				i ++;
			}
//		printf("%s\n",a);
//单个网址分析
		s_page(a);
//		printf("domain= %s\n",domain);
//		printf("page= %s\n",page); 
		ret = insert_db ();
		if(ret == 0)
		printf ("%s\n",a); 
//		my_printf_record();
			break;
                
          	 }
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
//		printf("%s\n",buf); 
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

static int search_callback(void *p, int argc, char **argv, char **argvv)
	{
			*(int *)p = 0;
		
		        //must = 0;
				return 0;
	}

int search_record(void)
{
	char *sql = NULL;
	int empty = 1 ;   
    	int ret;

	sql = sqlite3_mprintf("select * from web where domain = %Q and page=%Q",domain,page);    
	ret = sqlite3_exec(db, sql, search_callback, &empty, NULL);
	sqlite3_free(sql);    
	if(ret != SQLITE_OK) 
		printf("search select error\n");
				    
	if (!empty)
		return 1;

	return 0;
 }

int insert_db (void)
{
	char *sql = NULL;
	int ret;
	 ret = search_record();

	     if (ret)
	      	return ;

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
	return ret ;
}   

int record_callback(void *p, int argc, char **argv, char **argvv)
{

//	*(int *)p = 0 ;
	strcpy(&domain[0],argv[2]);
	strcpy(&page[0] , argv[3]);
//	domain = argv[2];	
//	page = argv[3];			

	return 0;    
}
 
void get_a_record (void)
{
	char *sql = NULL;
	int ret;

	sql = sqlite3_mprintf("select * from web where status = 0 order by id asc limit 0,1");    
	ret = sqlite3_exec(db, sql, record_callback, NULL, NULL);
//    sqlite3_free(sql);    
	if(ret != SQLITE_OK) 
		printf("select information error !\n");
	    
	return ;
}

void  wget(char *b )
{
	char s[300];
	memset(s,0,300);
	char *a="wget -O webinfo ";
	sprintf(s,"%s%s",a,b);
//	printf("%s",s);
	system(s);

	return ;

}

int my_printf_callback(void *p, int argc, char **argv, char **argvv)
{

	printf ("id = %s ",argv[0]);
	printf ("status = %s ",argv[1]);
	printf ("domain = %s ",argv[2]);
	printf ("page = %s\n",argv[3]);

	return 0;    
}

void my_printf_record (void)
{
	char *sql = NULL;
	int ret;

	sql = sqlite3_mprintf("select * from web where status = 0 order by id desc limit 0,1 ");    
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

int main (void)
{	int i=1;
	int ret;
	char weblink[300];

	ret = sqlite3_open(DBNAME, &db);

     
	if(ret != SQLITE_OK)
		printf("open %s error !",DBNAME);    	

	create();		

	insert_db ();
//	my_printf_record();

	while(1)

	{
		memset(domain,0,100);
		memset(domain_1,0,100);
		memset(page , 0 ,200);
		get_a_record ();
		strcpy(domain_1,domain);
		memset(weblink, 0 ,300);
		sprintf(weblink,"%s%s",domain,page);
		printf("weblink= %s\n",weblink); 
		wget(weblink);	//得到 webinfo文件	
		web_fenxi();
		update_db( 1 ); //执行后的为1 ，未执行的为0
//		my_printf_record();	


		


	}


	return 0;
}


