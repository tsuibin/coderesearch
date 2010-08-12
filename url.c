#include <stdio.h>
#include <string.h>

int parse_url(char *data)
{
	char *test1 = "<a";
	char *test2 = "href";
	char *test3 = "=";
	char *test4 = "\'";
	char *test5 = ">";
	char *p1,*p;
	int flag = 0;
	int len = 0;
	char buf[1024] = {0};

	if ( (len = strlen(data)) < 4 )
	{
		return -1;
	}
	memmove(buf,data,strlen(data));

	p = buf;
	p1 = NULL;
	
	if((p = strstr(buf,test1)) == NULL)
	{
		flag = 1;
	}

	if((p = strstr(p,test2)) == NULL && flag != 1)
	{
	}
	
	if((p = strstr(p,test3)) == NULL && flag != 1)
	{
	}
	
	if((p = strstr(p,test4)) != NULL && flag != 1)
	{
		p1 = ++p;
	}
	
	if((p = strstr(p,test4)) != NULL && flag != 1)
	{
		*p = '\0';
	}

	if (p1 != NULL)
	{
		printf("The result out is:\n%s\n", p1);
	}

	if (  p != NULL )
	{
		parse_url(++p);
	}

	return 0;
}

int main(int argc,char *argv[])
{
	char str1[] = " <a href a b c<a  href = 'www.baidu.com ' > <a  href = 'www.google.com ' > <a  href = 'www.baidu.com ' > <a  href = 'www.baidu.com ' > <a  href = 'www.baidu.com ' > ";
	char *str2 =  "www.google.cn";
	while ( parse_url(str1)  != 0 )
	{
		printf("error!\n"); 
	}
	return 0;
}
