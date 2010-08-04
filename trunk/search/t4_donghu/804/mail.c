#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "mail.h"

int main(int argc, char * argv[])
{
	FILE *fp;
	char buf[MAX], mail[SIZE];
	char *ptr, *start, *end;
	int id = 1;
	
	system("wget http://192.168.0.114/ -O mail.html");

	if((fp = fopen("mail.html", "r")) == NULL)
	{
		printf("Can't open %s\n", "mail.html");
		exit(1);
	}
	
	create_table();

	while(fgets(buf, MAX, fp) != NULL) 
	{
		ptr = buf;
		while ((ptr = str_searc(ptr, '@')) != NULL)	// 循环查找一行中的＠
		{	
			start = sear_start(ptr);  //danieldong2010@gmail.com  *start == 'd' 查找＠前的字符
			if ((end = sear_end(ptr)) != NULL) //*end == 'm' 查找＠后的字符
			{
				putstr(start, end);
				ptr++;
				collect_mail(start, end, mail);
				insert_table(id, mail);
				id++;
			}			//指针加一，利于循环查找下一个＠
			else 			//danieldong2010@gmailcom  end == NULL 表示没找到end，即没有找到合法邮箱。 
			{
				ptr++;		//指针加一，利于循环查找下一个＠
			}
		}

		ptr = buf;
		while ((ptr = strstr(ptr, "[at]")) != NULL) //循环查找一行中的[at @ [at]] [#]
		{	
			start = sear_start(ptr);
			if ((end = sear_end(ptr + 3)) != NULL)
			{
				putstr(start, end);
				ptr += 4;
				collect_mail(start, end, mail);
				insert_table(id, mail);
				id++;
			}
			else
			{
				ptr += 4;
			}
		}
		
		
		ptr = buf;
		while ((ptr = strstr(ptr, "[#]")) != NULL) //循环查找一行中的[#]
		{	
			start = sear_start(ptr);
			if ((end = sear_end(ptr + 2)) != NULL)
			{
				putstr(start, end);
				ptr += 3;
				collect_mail(start, end, mail);
				insert_table(id, mail);
				id++;
			}
			else 
			{
				ptr += 3;
			}
		}
		
		memset(buf, 0, MAX);
	}
	fclose(fp);
	sqlite3_close(db);
	printf("bye!\n");

	return 0;
}
 

char *  sear_end(const char *str)
{
	str++;
	int i = 0;
	while (str)
	{
		if (*str >= 'a'&& *str <= 'z')
		{
			str++;
			continue;
		}
		else if (*str >= 'A' && *str <= 'Z')
		{
			str++;
			continue;
		}
		else if (*str >= '0' && *str <= '9')
		{
			str++;
			continue;
		}
		else if (*str == '-' || *str == '_')
		{
			str++;
			continue;
		}
		else if (*str == '.')
		{
			str++;
			i = 1;
			continue;
		}
		else 
		{
			break;
		}
	}
	str--;

	if (i)
	{
		return (char *) str;
	}
	else 
	{
		return NULL;
	}
}

char * sear_start(const char *str)
{
	str--;
	/*while ( (*str >='a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') || (*str >= '0' && *str <= '9') || *str == '.' || *str == '_' || *str == '-')
		str--;*/
	while (str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			str--;
			continue;
		}
		else if (*str >= 'A' && *str <= 'Z')
		{
			str--;
			continue;
		}
		else if (*str >= '0' && *str <= '9')
		{
			str--;
			continue;
		}
		else if (*str == '.' || *str == '_' || *str == '-')
		{
			str--;
			continue;
		}
		else 
		{
			break;
		}
	}
	str++;

	return (char *) str;
}

char * str_searc(const char * str, char ch)
{
	while (*str != ch && *str != '\0')
	{
		str++;
	}

	if (*str == '\0')
	{
		return NULL;
	}
	else 
	{	
		return (char *) str;
	}
}

void putstr( const char * start, const char * end)
{
	const char * str;

	for (str = start; str <= end; str++)
	{
		putc(*str, stdout);
	}
	printf("\n");
}

void collect_mail(const char * start, const char *end, char * mail)
{
	const char *str;
	int i;

	for (str = start, i = 0; str <= end; str++, i++)
	{
		mail[i] = *str;
	}
	mail[i] = '\0';
}



			/*start = strseac2(ptr, buf, ' ');
			
			if (start == NULL)
			{
				start = strseac2(ptr, buf, '\t');
			}
			if (start == NULL)
			{
				start = strseac3(ptr, buf, );
			}
			
			end = strseac1(ptr, ' ');
			
			if ( end == NULL )
			{
				end = strseac1(ptr,'\r');
			}
			if ( end == NULL )
			{
				end = strseac1(ptr, 26 );
			}
			if ( end == NULL )
			{
				end = strseac1(ptr, '\t' );
			}
			
			if ( end == NULL )
			{
				printf("can't find end of mail");
				return 1;
			}
			
			if (start != NULL && end != NULL)
			{
				putstr(start, end);
			}
		}
		memset(buf, 0, MAX);

	}
	fclose(fp);
	printf ("bye!\n");

	return 0;
}

char * strseac2(const char * str1, const char * str2, char ch)
{
	while (*str1 != ch && str1 >= str2)
	{
		str1--;
	}
	
	if (*str1 == ch)
	{
		return (char *) str1;
	}
	else
	{
		return NULL;
	}
}

char * strseasp(const char * str)
{
	
*/
