#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main(int argc , char *argv[]) 
{
	char *p;
	char ch[] = "中华人民共和国,中文字符搜索测试";
	char *key = "共和国";

	p = strstr(ch,key);

	printf("%s\n",p);

	return 0;
}
