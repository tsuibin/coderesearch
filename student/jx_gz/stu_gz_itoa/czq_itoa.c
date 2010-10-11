#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

char * itoa (int a)
{
	int i = 0 , j = 0 ;
	char str[10] ;
	char *dst = malloc (10);
	while (a != 0)
	{
		str[i] = (a%10) + '0' ;
		i ++ ;
		a = a/10 ;
	}
	
	str[i] = '\0' ;
	i -- ;
	while (i >= 0)
	{
		dst[j++] = str[i--] ;
	}
	dst[j] = '\0' ;


	return dst ;
}


int main ( int argc , char *argv)
{
	int a = 201006 ;
	char *p = NULL ;
	
	p = itoa (a);

	printf ("%s\n",p); 	
				//atoi is a system function and itoa is not.
	printf ("%d\n",atoi(p)); 

	return 0 ; 
}

