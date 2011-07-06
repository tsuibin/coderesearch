#include <stdio.h> 
#include <stdlib.h> 

const  int  max = 1024; 
int main (int argc , char *argv[]) 
{ 
	FILE *fp1,*fp2; 
	char buf[max]; 
	int n; 
	
	if (argc < 3)
	{
		printf("%s missing file operand\n", argv[0]); 
		return 0; 
	}


	if((fp1 = fopen(argv[1],"r")) ==  NULL) 
	{ 
		printf("erro open file\n"); 
		exit(1); 
	} 

	if((fp2 = fopen(argv[2],"w")) == NULL) 
	{ 
		printf("erro open new file\n"); 
	} 

	while(( n= fread(buf,1,max,fp1)) != 0) 
	{ 

		fwrite(buf,1,n,fp2); 
	} 

	fclose(fp1); 
	fclose(fp2);     

	return 0; 

}  
