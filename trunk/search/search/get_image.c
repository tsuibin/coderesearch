/* get image file infomation from html file.
 * About html format
 * see http://www.dreamdu.com/xhtml/tag_a/
 * Athor: AKAE athena project
 */


#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc
#include "common.h"

static int count = 0 ;

/*
 * get the  address,
 * and malloc the space to save the image name.
 */

char * get_image_name (char * data)
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
struct parse_result *  get_one_image (char *data)
{
	char c;
	struct parse_result *one_image;
	
	data = is_string(data,"src");
	
	if (data == NULL)
		return NULL;
	
	data = is_string (data,"="); 

	one_image = malloc (sizeof(struct parse_result));
	if (one_image ==NULL)
	{
		printf ("malloc %d bytes error!\n",sizeof(struct parse_result));
		return NULL;
	}	

	if (data != NULL)
	      one_image->data = get_image_name(data);

	one_image->ret = 1;
	

	return one_image;
}


int get_image (char *data)
{

	struct parse_result * one_image;
	
	count = 0;
	one_image = get_one_image(data);	
	
	if (one_image == NULL)
		return count;
		
	if (one_image->ret)
	{
		
		printf ("The image filename is: %s\n",one_image->data);
	}

	return count;
}
