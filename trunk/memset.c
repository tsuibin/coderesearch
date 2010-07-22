#include <string.h>
#include <stdio.h>
#include <memory.h>
int main(void)
{
	char buffer[] = "Hello world\n";
	printf("Buffer before memset: %s\n", buffer);
	memset(buffer, '*', strlen(buffer) );
	printf("Buffer after memset: %s\n", buffer);
	return 0;
}
