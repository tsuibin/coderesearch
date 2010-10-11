#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void send_integer (int a) 
{
	int  i , k ;
	char j = 0 ;
	char b[100] ;    //define the array b[100]
	
	while (a)        //exchange a  to char
	{
		i = a % 10;
		a = a / 10 ;
		b[j++] = i + '0' ;
	}
	for (k = 0 ; k<j ; k++)
	{
		printf("%c",b[k]) ;  //print  in opposite way
	}
	 

}

int main (int argc,char *argv[])
{	
	int a ;

	printf("please input a num!\n") ;
	scanf("%d",&a) ;
	send_integer (a) ;   //send a to function 
 	
	printf ("\n") ;
	return 0 ;

}
