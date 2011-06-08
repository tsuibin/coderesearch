#include <stdio.h> 
#include <stdlib.h> 

enum myT
{
	lily,
	lucy,
	jim
};

int main(int argc , char *argv[]) 
{
	//enum color{ red =1, blue=2,green=3};

	//enum color a = 3;
	enum myT m = 0;
	switch(m){
		case lily:
			printf("color lily \n");
			break;
		case lucy:
			printf("color lucy \n");
			break;
		case jim:
			printf("color jim\n");
			break; 
		default:
			break;
	}

	return 0; 
}
