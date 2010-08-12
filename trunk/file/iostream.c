#include<stdio.h>
#include<string.h>

FILE *fp;

FILE * file_open(char *filename)
{
	fp = fopen(filename,"r+");
	if(fp == NULL)
	{	
		printf("can't open file\n");
		return NULL;
	}
	return fp;
	 
}



void file_close(FILE *fpfile)
{
	fclose(fpfile);
}


int main(int argc,char *argv[])
{
	char ch;
	char *ch1;
	
	fp = file_open("test");
	if (fp == NULL)
	{
		return 1;
	}
//	printf("2,1\n");
//	fseek(fp,2,1);
	printf("4,2\n");
	fseek(fp,4,2);
	
//	fgetpos(fp,ch1);
	
//	ch = fgetc(fp);
	printf("ch = %c\n",ch);
//	printf("ch1 = %s\n",ch1);

	file_close(fp);
	

	return 0;
}
