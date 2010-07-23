#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"


int use_db = 0;
char *use_domain = NULL;
char *use_page = NULL;

void loop(char *data)
{
	char c;

	c = get_char(data);
	
	while ( c != '\0')
	{
		data++;
	
		//html format flag "<"	
		if (c =='<')
		{
			//"<a" link flag 
			if (!strncmp(data,"a ",2))
			{	
				data += 2;
				get_link(data);
			}
			else if (!strncmp(data,"img ",4))
			{
				//"<img" image flag 
				data += 4;
				get_image(data);
			}
		}
		// search next "<"
		c = get_char(data);
	}


}

void usage(char *name)
{
	printf ("%s -f *.html file\n",name);
	printf ("%s -w http://www.akaedu.com/\n",name);
	printf ("%s -db \n",name);
        printf ("\t read data from database\n");	
	exit(1);
}

void data_from_file(char *file )
{
	char * buf;
	char *filename ="1.html"; //default filename

	if (file != NULL)
		filename = file;

	init_file(filename);

	buf = get_line();

	while(buf != 0)
	{	
		loop(buf);
		search_email (buf);
		buf = get_line();
	}
}

void data_from_web(char * webaddress,char *page)
{
	char * data = NULL;
	int ret ;

	ret = init_http_get(webaddress,page);
	if (ret || timeout)
		return ;
	data = get_web_buf( );

	while(data != 0)
	{	
		loop(data);
		search_email (data);
		data = get_web_buf( );
	}
}

int data_one_from_db (char *dataname)
{

	struct weblink * link;

	init_sqlite(dataname);
	
	link = get_a_record();
	if (link == NULL)
        {
		db_close ();
		return 0;
	}
	use_domain = link->domain;	
        use_page   = link->page;
	data_from_web (link->domain,link->page);
	update_db(link->id,2);

	free(link->page);
	
	db_close ();
	
	return 1;
}

int data_from_db(char *dataname)
{
	int ret ;

	use_db = 1;

	
	ret = data_one_from_db (dataname);
	while (ret)
	{
		ret = data_one_from_db (dataname);
	}

}


int main (char argc,char **argv)
{
	

	if (argc < 3)
		usage(argv[0]);
	
	if (!strncmp(argv[1],"-f",2))
	{
		data_from_file(argv[2]);
	}
	else if (!strncmp(argv[1],"-w",2))
	{
		data_from_web(argv[2],"/");
	}
	else if (!strncmp(argv[1],"-db",3))
	{
		data_from_db(argv[2]);
	}
	else
		usage(argv[0]);

	return 0;
}


