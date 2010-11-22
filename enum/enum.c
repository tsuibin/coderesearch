#include <stdio.h> 
#include <stdlib.h> 
int main(int argc , char *argv[]) 
{
	enum color{ red =1, blue=2,green=3};

	enum color a = 3;
	switch(a){
		case red:
			printf("color red \n");
			break;
		case blue:
			printf("color blue \n");
			break;
		case green:
			printf("color green\n");
			break; 
		default:
			break;
	}

	return 0; 

}
