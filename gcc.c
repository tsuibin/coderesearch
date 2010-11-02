#include <stdio.h>

#define len 1000000000L

unsigned long f(unsigned long a, unsigned long b) __attribute__((noinline));

int main()
{
	printf("%lu\n", f(0, 2*len));
	return 0;
}

unsigned long f(unsigned long a, unsigned long b)
{
	unsigned long sum = 0;
	for (; a < b; a++)
		sum += a;
	return sum;
}
