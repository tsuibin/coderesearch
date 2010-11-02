/*
   如果用static关键字修饰一个函数声明，则表示该标识符具有Internal Linkage，例如有以下两个程序文件：
 */

/* foo.c */
static void foo(void) {}
/* main.c */
void foo(void);
int main(void) { foo(); return 0; }

/*
   编译链接在一起会出错

   虽然在foo.c中定义了函数foo，但这个函数只具有Internal Linkage，只有在foo.c中多次声明才表示同一个函数，而在main.c中声明就不表示它了。如果把foo.c编译成目标文件，函数名foo在其中是一个LOCAL的符号，不参与链接过程，所以在链接时，main.c中用到一个External Linkage的foo函数，链接器却找不到它的定义在哪儿，无法确定它的地址，也就无法做符号解析，只好报错。凡是被多次声明的变量或函数，必须有且只有一个声明是定义，如果有多个定义，或者一个定义都没有，链接器就无法完成链接。


以上讲了用static和extern修饰函数声明的情况。现在来看用它们修饰变量声明的情况。仍然用stack.c和main.c的例子，如果我想在main.c中直接访问stack.c中定义的变量top，则可以用extern声明它：
*/

/* main.c */
#include <stdio.h>

void push(char);
char pop(void);
int is_empty(void);
extern int top;

int main(void)
{
	push('a');
	push('b');
	push('c');
	printf("%d\n", top);

	while(!is_empty())
		putchar(pop());
	putchar('\n');
	printf("%d\n", top);

	return 0;
}
/*
变量top具有External Linkage，它的存储空间是在stack.c中分配的，所以main.c中的变量声明extern int top;不是变量定义，因为它不分配存储空间。以上函数和变量声明也可以写在main函数体里面，使所声明的标识符具有块作用域：
*/
int main(void)
{
	void push(char);
	char pop(void);
	int is_empty(void);
	extern int top;

	push('a');
	push('b');
	push('c');
	printf("%d\n", top);

	while(!is_empty())
		putchar(pop());
	putchar('\n');
	printf("%d\n", top);

	return 0;
}
/*
注意，变量声明和函数声明有一点不同，函数声明的extern可写可不写，而变量声明如果不写extern意思就完全变了，如果上面的例子不写extern就表示在main函数中定义一个局部变量top。另外要注意，stack.c中的定义是int top = -1;，而main.c中的声明不能加Initializer，如果上面的例子写成extern int top = -1;则编译器会报错。

在main.c中可以通过变量声明来访问stack.c中的变量top，但是从实现stack.c这个模块的角度来看，top这个变量是不希望被外界访问到的，变量top和stack都属于这个模块的内部状态，外界应该只允许通过push和pop函数来改变模块的内部状态，这样才能保证堆栈的LIFO特性，如果外界可以随机访问stack或者随便修改top，那么堆栈的状态就乱了。那怎么才能阻止外界访问top和stack呢？答案就是用static关键字把它们声明为Internal Linkage的：
*/
/* stack.c */
static char stack[512];
static int top = -1;

void push(char c)
{
	stack[++top] = c;
}

char pop(void)
{
	return stack[top--];
}

int is_empty(void)
{
	return top == -1;
}
/*
这样，即使在main.c中用extern声明也访问不到stack.c的变量top和stack。从而保护了stack.c模块的内部状态，这也是一种封装（Encapsulation）的思想。

用static关键字声明具有Internal Linkage的函数也是出于这个目的。在一个模块中，有些函数是提供给外界使用的，也称为导出（Export）给外界使用，这些函数声明为External Linkage的。有些函数只在模块内部使用而不希望被外界访问到，则声明为Internal Linkage的。
*/
