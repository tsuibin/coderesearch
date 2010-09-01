/* netorder.c */
#include <stdio.h>
#include <netinet/in.h>
int main(void)
{
    int i;
    union {
	int s;
	char c[4];
    } un;

    un.s = htonl(0x01020304);

    for (i = 0; i < 4; i++)
	printf("c[%d] = %d\t", i, un.c[i]);

    printf("\n&s = %p, &c[0] = %p\n", &un.s, &un.c[0]);

    if (un.c[0] == 1)
	printf("big-endian\n");
    else if (un.c[0] == 4)
	printf("little-endian\n");
    else
	printf("unknown\n");

    return 0;
}
