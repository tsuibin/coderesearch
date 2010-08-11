#include <stdio.h> 

void show()
{
	extern const int a;
	printf("show %d\n",a);
}

void showtmp()
{
	extern int tmp;
	show();
	tmp++;
	printf("showtmp = %d\n",tmp); 
}
