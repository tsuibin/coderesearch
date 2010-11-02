#include <stdio.h>

int a, b = 1;

extern void push(char);
extern char pop(void);
extern int is_empty(void);
/*
函数声明中的extern也可以省略不写，不写extern的函数声明也表示这个函数具有External Linkage。
*/

int main(void)
{
	push('a');
	push('b');
	push('c');

	while(!is_empty())
		putchar(pop());
	putchar('\n');

	return 0;
}
