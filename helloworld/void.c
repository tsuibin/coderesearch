#include <stdio.h>
void main(void)
{
 char *message[]={"Hello","World"};
 int i;
 for (i=0;i<2;++i)
 printf("%s",message[i]);
 printf("\n"); 
}
