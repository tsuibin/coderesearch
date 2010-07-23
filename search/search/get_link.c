/* get link address infomation from html file.
 * About html format
 * see http://www.dreamdu.com/xhtml/tag_a/
 * Athor: AKAE athena project
 */


#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc
#include "common.h"

static int count=0;

 /* get the  address,
 * and malloc the space to save the link.
 */

 char * get_link_address (char * data)
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
		
	newdata = malloc (i+1);
	if (newdata == NULL)
	{
		printf ("malloc %d bytes to save link ,no space?\n",i);
		return NULL;
	}
	
	memcpy(newdata,data,i);
	newdata[i] = '\0';
	
	return newdata;
}
struct parse_result *  get_one_link (char *data)
{
	char c;
	struct parse_result *one_link;
	
	
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
	      one_link->data = get_link_address(data);

	one_link->ret = 1;

	data = is_string (one_link->data,"mailto:");

	if (data != NULL)	
	{	one_link->ret = 2;
		one_link->data = data;
	}

	return one_link;
}


int  get_link (char *data)
{

	struct parse_result * one_link;

	count = 0;

	one_link = get_one_link(data);	
	
	if (one_link == NULL)
		return ;
		
	if (one_link->ret == 1)
	{
		if(use_db)
		{
			if (one_link->data[0] == '#')
				return ;
			insert_link(one_link->data);
		}
		else 
		{
			printf ("The link address is: %s\n",one_link->data);
		}
	} 
	else if (one_link->ret == 2)
	{
			
		printf ("The email address is: %s\n",one_link->data);
	}
	

	return count;
}

