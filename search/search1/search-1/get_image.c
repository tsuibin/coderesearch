/* get image file information from html file.
 * About html format
 * see http://www.dreamdu.com/xhtml/tag_a/
 * Athor: AKAE athena project
 */


#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc

char * test1="<img src=\"flower.jpg\" atl=\"akae.jpg\" title=\"This is a logo\" >";
char * test2="<img src = \" athena.jpeg\" />";
char * test3="<img src = athena.jpeg  />";

struct parse_result
{
	int ret;     //ret = 1,is a image; = 0 isn't a image
	char * data; //if ret =1,data = image file name;
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
struct parse_result *  get_one_image (char *data)
{
	char c;
	struct parse_result *one_image;

	data = is_string (data,"<img");	
	if (data == NULL)
		return NULL;
	
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
	      one_image->data = get_address(data);

	one_image->ret = 1;
	

	return one_image;
}


void test (char *test)
{

	struct parse_result * one_image;
	one_image = get_one_image(test);	
	
	if (one_image == NULL)
		return ;
		
	if (one_image->ret)
	{
		
		printf ("The image filename is: %s\n",one_image->data);
	}
	else
	{
		printf ("I'm sorry,Not found any image\n");
	}

}

int main (char argc,char **argv)
{

	printf ("Welcome use get image program! \n");

	test(test1);
	test(test2);
	test(test3);

	return 0;
}
