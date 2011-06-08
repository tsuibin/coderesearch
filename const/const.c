#include <stdio.h> 

int main(int argc ,char *argv[]) 
{
	const int x = 1;
	int b = 10;
	int c = 20;

	const int * a1 = &b;/*指向的东西不能改 指向常量的指针,指针可以改，数据不能改 */
	int * const a2 = &b;/*指针不能被修改 指针指向的数据可以被修改*/
	const int * const a3 = &b;/*指针不能修改 指针指向的数据不能改*/

//	x = 2;/* x 定义的是 =1 这里不能赋值 郝卓*/

	a1 = &c; 
//	*a1 = 1; /* a1的内容不能修改 张伟*/

//	a2 = &c; /* a2的指针不能修改 张伟*/
	*a2 = 1;

//	a3 = &c;/* a3的指针不能修改 张伟*/
//	*a3 =1; /* a3的内容不能修改 张伟*/

	return 0; 
}
