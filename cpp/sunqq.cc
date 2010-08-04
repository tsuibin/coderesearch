#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 代码段 .text
void func()
{
		return;
}

// 代码段 .text
const int a = 10;
const int * const b = &a; 
//const int * b = a;
// 全局数据段 .data
static int c = 20;
char d[] = "abc"; // "abc" 存放在d开始的全局数据段
char *e = "abc";  // e 自身放置在全局数据段，e 指向的是 “abc”，而这个 “abc” 放置在 .text

// .bss 段
static int f;
int g;
const int *h;

int main()
{
		static int i = 30; // .data
		static int j; // .bss

		// 以下放置在栈 .stack
		const int k = 40;
		const int *l;
		const int * const m = &k; 
		//const int * m = &k; 
		int n = 10;
		int o[2];
		char p[] = "abc"; // 类似 d，不过放置在 .stack

		// 特殊情况
		char *q = "abc"; // q 自身放置在 .stack, q 指向 “abc”，而这个 “abc” 放置在 .text，
		// 编译器会优化,所以 q 和 e 指向同一个地址

		// malloc分配的放置在堆中
		
		printf("func() address is 0x%x\n", func); 
		printf("main() address is 0x%x\n", main); 
		printf("a address is 0x%x\n", &a);
		printf("b address is 0x%x\n", &b);
		printf("b point address is 0x%x\n", b); // b 指向的地址，等同 a 的地址
		printf("c address is 0x%x\n", &c);
		printf("d address is 0x%x\n", &d);
		printf("d address is 0x%x\n", d); // 等同于上一行
		printf("e address is 0x%x\n", &e);
		printf("e point address is 0x%x\n", e); // e 指向的地址
		printf("f address is 0x%x\n", &f);
		printf("g address is 0x%x\n", &g);
		printf("h address is 0x%x\n", &h);
		printf("h point address is 0x%x\n", h); // h 指向 NULL
		printf("i address is 0x%x\n", &i);
		printf("j address is 0x%x\n", &j);
		printf("k address is 0x%x\n", &k);
		printf("l address is 0x%x\n", &l);
		printf("l point address is 0x%x\n", l); // l 指向不确定,未被正确初始化前不能使用,也就是不能 *l 这样使用，否则会报段错误
		printf("m address is 0x%x\n", &m);
		printf("m address is 0x%x\n", m); // m 指向的地址，等同 k 的地址
		printf("n address is 0x%x\n", &n);
		printf("o address is 0x%x\n", &o);
		printf("o address is 0x%x\n", o);  // 等同于上一行
		printf("p address is 0x%x\n", &p); // 类似于 o，不过 p 被初始化了, "abc" 存放在 p 开始的栈中
		printf("p address is 0x%x\n", p);  // 等同于上一行
		printf("q address is 0x%x\n", &q);
		printf("q point address is 0x%x\n", q);

		printf("\n");

		// p 和 q 中的 “abc” 都以 ‘\0’ 结尾，
		// sizeof 计算包括结尾的 '\0'，并且在编译是计算长度
		// strlen 不包括结尾的 '\0', 它是在运行时计算长度，效率不如 sizeof 高.
		// char p[3] = "abc", 这情况没有结尾的 ‘\0’, 不能对 p 使用 str* 一类的字符串函数，只能当数组用下标访问
		printf("p sizeof length is %d\n", sizeof(p));
		printf("p strlen length is %d\n", strlen(p));
		printf("q sizeof length is %d\n", sizeof(q));
		printf("q strlen length is %d\n", strlen(q));

		return 0;
}

/*
 * 内存分布图
 *
 * 高地址  
 *          .stack  k, l, m, n, o, p, q
 *          .堆
 *          .bss    f, j, h, g
 *          .data   c, d, e, i
 *          .text   func(), main(), a, b, "abc"
 * 低地址          
 *
 *
 * 注意：
 *      在bss段中放置顺序为 static, const, 普通变量，
 *      关注 .bss 段中各变量的位置关系。
 *
 *      关注 e 和 q 所指向的 “abc” 和 b 的位置关系。
 *
 *      e 和 q 指向的是同一个位置，且在.text中，
 *      代码段为只读，所以不能用 *e = 'a' 之类的语句改变其值，
 *      但e和q本身可以改变，也就是可以指向别的对象例如 e = d 。
 *
 *      关注 p 和 q 的不同，p代表数组的首地址无法改变，不能用 p = q 之类语句，
 *      但 p 数组的内容可以改变，例如使用 *p='a' 或 *(p+0)='a' 或 p[0]='a' 之类的语句修改其值 。
 * 
 *
 *
 */

