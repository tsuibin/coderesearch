#include <stdio.h>	
#include <stdlib.h>	

int main(int argc,char* argv[])	
{
	char *str = {"this is a string"};
	float f = 3.1415926;
	int slen;
	printf(" ------- string ------ \n");
	printf(" p =  %p]\n",str);
	printf("s = %s]\n",str);
	printf("c = %c]\n",'a');
	printf(" ------- float ------ \n");
	printf("f = %f]\n",f);	
	printf(" f5.2f = %5.2f]\n",f);
	printf(" f-5.2 = %-5.2f] \n",f);
	printf(" ------- *s ------ \n");
	printf("%*s\n",30,str);
	printf("hello world%n",&slen);
	printf("len = %d \n",slen);
	printf(" ------- '.2f ------ \n");
	printf("%'.2f\n", 1234567.8901);
	
	
	return	0;
}
