#include <stdio.h>
#include <iostream.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
 int i =100;
 while(0<(--i)){
	srand( (unsigned)time( NULL ) ); 
	cout << rand() << endl;
 } 
return 0;
}
