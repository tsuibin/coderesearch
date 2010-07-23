#include <stdio.h>	
#include <stdlib.h>	//头文件与函数分开

void my_printf(unsigned char * string)
{
	unsigned char buf[1024]; //声明与逻辑断码段分开

	sprintf(buf,"espeak -v zh %s",string);
	printf("espeak %s\n",string);
	system(buf);

	return; //返回与逻辑代码段分开
}
