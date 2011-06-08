#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#define MAX 80

char * is_string (char *data,char * dst)
{
	int i,len;

	if (data == NULL)
		return NULL;
	while (*data == ' ')
	{
		data++;
	}

	len =strlen(dst);

	for (i = 0;i < len; i++)
	{
		if (*data == '\0')
			return NULL;

		if (*data != *dst)
			return NULL;

		data ++;
		dst ++;
	}

	return data;
}

char get_char (char *data)
{
	return *data;
}

void get_link_address (char * data)
{
	char c;
	int i;
	char url[1024];
	c = get_char(data);
	while (c == ' ' || c == '\"' || c == '\'')
	{   
		data++;
		c = get_char(data);
	}   

	for (i = 0; data[i] !='\0'; i++)
	{   
		if (data[i] == ' ' || data[i] == '\'' || data[i] == '\"' || data[i] == '>')
			break;
	}   

	memcpy(url,data,i);
	url[i] = '\0';
	printf("url:%s\n",url); 
	return;
}

void *get_one_link (char *data)
{
	char c;
	data = is_string(data,"href");
	
	if (data == NULL)
		return NULL;
	
	data = is_string (data,"="); 
	if (data != NULL)
		get_link_address(data);
	
	return NULL;
}


int main(int argc ,char *argv[]) 
{
	char *url[] = {"www.msn.com","www.baidu.com"};
	char tmp[1024];
	int i = 0;
	FILE *fp;
	char buf[1024];

	for( ; i < 2; i++){
		memset(tmp, 0, sizeof(tmp));
		strcpy(tmp, "wget -O temp ");
		strcat(tmp, url[i]);
		system(tmp);

		fp = fopen("temp","r");
		while(!feof(fp)){
			memset(buf, 0, sizeof(buf));
			fread(buf, sizeof(buf), 1, fp);
			get_one_link(buf);
		}
		fclose(fp);
	}

	return 0; 
}
