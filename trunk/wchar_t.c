#include <stdio.h> 
#include <stdlib.h> 
#include <wchar.h>

int main(int argc , char *argv[]) 
{
	double angel_alpha = 90.0/3;
	wprintf( L"Angel \u03b1 measures %1f degress. \n", angel_alpha);

	return 0;
}
