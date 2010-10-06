#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


void show(char str[])
{
	printf("size is : %d \n",strlen(str)); 
}
int main(int argc , char *argv[]) 
{
	char * str = "hello world!";
	char str1[10] = "hello";
	char str2[20] = "hello world!";
	
	show(str2);

	return 0;

}
