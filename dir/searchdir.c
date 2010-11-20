#include <stdio.h> 
#include <sys/types.h>
#include <dirent.h>
#include <string.h> 
#include <stdlib.h> 

#define DIRPATH "../"
void search_dir()
{
	char infile[50];
	struct dirent *ptr;   
	DIR *dir;
	char * pic_buf;

	dir=opendir(DIRPATH);

	while((ptr=readdir(dir))!=NULL)
	{   
		//skip '.'and '..'
		if(ptr->d_name[0] == '.')
			continue;

		sprintf(infile,DIRPATH"%s",ptr->d_name);

		pic_buf = malloc(strlen(infile) +1);

		strncpy(pic_buf,infile,strlen(infile) +1); 

		printf("path: %s\n",pic_buf); 
		//img_tmp =ins_img( pic_buf ,img_tmp);
	}   
	closedir(dir);
}

int main(int argc , char *argv[]) 
{
	search_dir();

	return 0; 
}
