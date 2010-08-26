#include <stdio.h> 
#include <stdlib.h> 

float getValue(float a, float b, int op)
{
	float tmp;
	switch(op)
	{
	case 0: tmp = a + b; break;
	case 1: tmp = a - b; break;
	case 2: tmp = a * b; break;
	case 3: tmp = a / b; break;
	default:break;
	}
	return tmp;
}

int main(int argc , char *argv[])
{
	float a[4] = {4,2,3,1};
	float value;
	int i = 2,opi = 4;
	for(;i;--i)
	{	
		for (;opi;--opi)
		{
			value = getValue(a[i],a[i+2],opi);
			printf("%d \n",value); 
		}
	}
	return 0;
}
