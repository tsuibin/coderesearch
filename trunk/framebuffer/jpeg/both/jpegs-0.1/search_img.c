#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "common.h"
#include <string.h>

	
Link_img ins_img( char * img_name,Link_img tmp)
{

	Link_img  new_img ;
	new_img = malloc(sizeof(Link_img));
	
	new_img ->img_name =  img_name;
	new_img ->next = tmp ->next;
	tmp ->next = new_img;
	tmp = tmp ->next;
	
	return tmp;
}

Link_img get_img(Link_img  tmp )
{
		tmp = tmp ->next;
		return tmp;
}

void search_img()
{
    char infile[50];
    struct dirent *ptr;   
     DIR *dir;
     char * pic_buf;
	
	l_img = malloc(sizeof(Link_img));
	l_img ->next = NULL;	
	
	l_img_head = l_img;


    dir=opendir("./jpegs");
	img_tmp = l_img;

    while((ptr=readdir(dir))!=NULL)
    {
    //skip '.'and '..'
        if(ptr->d_name[0] == '.')
            continue;

        sprintf(infile,"./jpegs/%s",ptr->d_name);
	
	pic_buf = malloc(strlen(infile) +1);

	 strncpy(pic_buf,infile,strlen(infile) +1); 
	
	img_tmp =ins_img( pic_buf ,img_tmp);
    }
    closedir(dir);
}

void free_img_buf()
{
	
	Link_img  free_img ;
	img_tmp = l_img_head->next;
	while(img_tmp != NULL)
	{
		free_img = img_tmp;
		free(img_tmp->img_name);
		img_tmp = get_img(img_tmp);
		free(free_img);
		
	}
		free(l_img);
}


