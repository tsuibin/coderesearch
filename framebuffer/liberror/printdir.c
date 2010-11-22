/*  We start with the appropriate headers and then a function, printdir,
    which prints out the current directory.
    It will recurse for subdirectories, using the depth parameter is used for indentation.  */

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "comm.h"
#include <stdlib.h>

link_img l_img_head;
link_img new_pic(char *newpic)
{
	link_img p;
	p = (link_img)malloc(sizeof(struct link_img));
	if(p == NULL)	
	return NULL;
	else 
	{
		strcpy(p->img_name, newpic);
		p->next = NULL;
	}

	return p;

}

link_img  insert_pic(char *newpic)
{
	link_img p, q;
	p = new_pic(newpic);
	if(p == NULL)
	return NULL;	
	if(l_img_head == NULL)
	l_img_head = p;
	else
	{
		for(q = l_img_head; q->next != NULL; q = q->next);
		q->next = p;
	}
	return l_img_head;

}

void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
	char infile[100];

    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)) {
            if(strcmp(".",entry->d_name) == 0 || 
                strcmp("..",entry->d_name) == 0)
                continue;
            printdir(entry->d_name,depth+4);
        }
        else
		{
	
		strcpy(infile, DIRPATH);
		strcat(infile, dir);
		strcat(infile, "/");
		strcat(infile, entry->d_name);
		insert_pic(infile);
		}
    }
    chdir("..");
    closedir(dp);
}




