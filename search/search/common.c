/* get link address infomation from html file.
 * About html format
 * see http://www.dreamdu.com/xhtml/tag_a/
 * Athor: AKAE athena project
 */


#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //malloc


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
	
	if (data == NULL)
		return NULL;
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
 * href =   "http://www.akaedu.org";
 * 
 * src = "flower.jpg ";
 * 
 * We need skip ' ' and '"'
 */

char * get_start(char *data)
{
	char c;

	//cut ' ' , '"'
        c = get_char(data);
        while (c == ' ' || c == '\"')
        {
                data++;
                c = get_char(data);
        }

	return data;
}

/*
 * get end flag,and return data length 
 */

int get_end(char *data)
{
	int i;
	
	for (i = 0 ; data[i] !='\0' ; i++  )
	{
		if (data[i] == ' ' || data[i] == '\"' 
			|| data[i] == '>')

			break;
	}

	return i;
}

