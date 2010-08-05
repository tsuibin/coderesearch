#include <stdio.h>	
#include <stdlib.h>	
#include <string.h>
#include <sqlite3.h>

unsigned long seq = 0;

int  AddtoSql(char *record, sqlite3 *db, int seq)
{
	int ifok;
	char *stmt = NULL;
	char *stmt_insert = "INSERT INTO links VALUES (,'');";

	stmt = (char *)malloc(sizeof(record) + sizeof(seq) + sizeof(stmt_insert));

	sprintf(stmt, "INSERT INTO links(link) VALUES ('%s');", record);	
	printf("%s\n", stmt);
	ifok = sqlite3_exec(db, stmt, NULL, NULL, NULL);
	//free(stmt);
	printf("%d \n",ifok); 
	return ifok;
	
}

void  SearchthenAdd(char *Line, sqlite3 *db)	
{
	char *record;
	char *tag1 = "<a";
	char *tag2 = "href";
	char *tag3 = "=";
	char *tag4 = "\"";
	char *head, *end;
	
	head = Line;
	while((head = strstr(head, tag1)) != NULL)
 	{
		if((head = strstr(head , tag2)) == NULL)
		{
			break;
		}
		while (*head != *tag3 && *head != '\0')
		{	
			head++;
		}

		if (*head == '\0')	
		{
			break;
		}

		while(*head != *tag4 && *head != '\0')
		{
			head++;
		}
		
		if (*head == '\0' || head == NULL)
		{
			break;
		}
		else
		{
			++head;
			if ((end = strstr(head, tag4)) == NULL)
			{
				break;
			}
			*end = '\0';
			if (*head != '\0' && strstr(head, "javascript") == NULL && *head != '{')
			{
				//puts(head);
				end++;
				record = (char *)malloc(sizeof(head));	
				seq++;
				sprintf(record, "%s", head);
				/*
				if (AddtoSql(record, db, seq) == SQLITE_OK)
				{
					printf("Successfully add record to database: %s\n", record);
				}
					return;*/
				free(record);
				
				head = end;
			}
		}

 	}
}

int main(int argc ,char *argv[])	
{
	int i = 0;
	char ch;
	char Line[10000];
	FILE *fp;
	sqlite3 *db;	

	if ((fp = fopen("./qq" ,"r")) == NULL)
	{
		puts("Source file not exsist,exit.");
		exit(EXIT_FAILURE);
	}
	
	if (sqlite3_open("./http_link.db" ,&db) != SQLITE_OK)
	{
		puts("Can't access the database,Failed.");
		exit(EXIT_FAILURE);
	}
	
	sqlite3_exec(db, "CREATE TABLE links (id integer primary key, link text);", NULL, NULL, NULL);


	while ((ch = fgetc(fp)) != EOF && ch != '\0')
	{
		Line[i] = ch;
		i++;	
		while ((Line[i] = (char)fgetc(fp)) != '\n' && Line[i] != EOF)
		{
			i++;	
		}

		Line[i] = '\0';
		SearchthenAdd(Line, db);
		i = 0;
	}
	fclose(fp);	
}

