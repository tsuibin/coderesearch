#include <stdio.h>
//1 C语言的入口函数是什么?
//2 int argc 和 char * argv[]分别代表什么?
//3 strcmp的作用是什么?
//4 if语句有什么作用?
//5 如何用printf打印一个字符串
//6 如何用printf打印一个整形数字?
//7 return 语句是干吗用的?
//8 如何在c语言代码里面写注释? 注释有什么作用?
//9 如何将c语言源代码编译为一个可执行程序?
//10 argv[0]和argv[1]分别表示什么?
//11 如何创建一个文件夹?
//12 如何创建一个文件?
//13 如何使用vim编辑一个文件?
//14 如何不保存退出vim ?
//15 gcc pun.c -o pun 这条命令有什么作用?

int main(int argc, char *argv[]) 
{
	int ret = -1;

	printf("To C, or not to C: that is the question.\n"); 

	printf("argc: %d \n", argc);

	if ( argc == 2 )
	{
		ret = strcmp(argv[1], "baishucheng");
		if (ret == 0)
		{
			printf("白书诚\n"); 
		}

		ret = strcmp(argv[1], "chenglang");
		if (ret == 0)
		{
			printf("程浪\n"); 
		}

	}

	return 0;
}
