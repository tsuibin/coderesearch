/* get link address information from html file.
 * About html format
 * see http://www.dreamdu.com/xhtml/tag_a/
 * Athor: AKAE athena project
 */


#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc

char * test1="<a href=\"www.akaedu.org\">";
char * test2="<a href = \"http://www.sina.com.cn\">";
char * test3="< a    href = \" ftp://www.kernel.org \"  >";

struct parse_result
{
	int ret;     //ret = 1,is a link; = 0 isn't a link
	char * data; //if ret =1,data = the link;
};

char get_char (char *data)
{
	return *data;
}

/*
 *  skip ' ',and compare  data,dst
 *  if data != dst return NULL;
 *  else return new data point 
 */

char * is_string (char *data,char * dst)
{
	int i,len;

	while (*data == ' ')
	{
		data++;
	}
	
	len =strlen(dst);
	
	for (i = 0;i < len; i++) 	
	{
		//data length < dst
		if (*data == '\0')
			return NULL;
	
		if (*data != *dst)
			return NULL;
	
		data ++;
		dst ++;
	}
	
	return data;
}

/*
 * get the  address,
 * and malloc the space to save the link.
 */

char * get_address (char * data)
{
	char c,*newdata;
	int i;

	//get start address
	c = get_char(data);
	while (c == ' ' || c == '\"')
	{
		data++;
		c = get_char(data);
	}
	
	//set end address 
	for (i = 0; data[i] !='\0'; i++)
	{
		if (data[i] == ' ' || data[i] == '\"' || data[i] == '>')
			break;
	}
		
	newdata = malloc (i);
	if (newdata == NULL)
	{
		printf ("malloc %d bytes to save link ,no space?\n",i);
		return NULL;
	}
	
	memcpy(newdata,data,i);
	
	return newdata;
}
struct parse_result *  get_one_link (char *data)
{
	char c;
	struct parse_result *one_link;
	
	c = get_char(data);

	if (c != '<')
		return NULL;
	data = is_string (data,"<a");
	
	if (data == NULL)
		return NULL;

	data = is_string(data,"href");
	
	if (data == NULL)
		return NULL;
	
	data = is_string (data,"="); 

	one_link = malloc (sizeof(struct parse_result));
	if (one_link ==NULL)
	{
		printf ("malloc %d bytes error!\n",sizeof(struct parse_result));
		return NULL;
	}	

	if (data != NULL)
	      one_link->data = get_address(data);

	one_link->ret = 1;
	

	return one_link;
}


void test (char *test)
{

	struct parse_result * one_link;
	one_link = get_one_link(test);	
	
	if (one_link == NULL)
		return ;
		
	if (one_link->ret)
	{
		
		printf ("The link address is: %s\n",one_link->data);
	}
	else
	{
		printf ("I'm sorry,Not found any link\n");
	}

}

int main (char argc,char **argv)
{

	printf ("Welcome use get link program! \n");

	test(test1);
	test(test2);
	test(test3);

	return 0;
}
