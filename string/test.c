#include <stdio.h> 
#include <stdlib.h> 

char sss[ ] = "helloworld!";

int main(int argc , char *argv[]) 
{
	char *p;
	char world[ ] = "helloworld!";

	printf(" world address %x \n",world); 
	printf(" sss address %x \n",sss); 
	
	return 0;
}
