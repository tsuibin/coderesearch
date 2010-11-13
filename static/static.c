#include <stdio.h>

static int a;
void data()
{
	printf("%d\n",a); 
}
int main(int argc , char *argv[]){
	a = 10;
	data();

	return 0;
}
