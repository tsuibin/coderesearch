#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool int_cmp(int a, int b)
{
	return (a == b)? true: false;
}

int * searchArray(int arr[],int size)
{
	int i,j;
	for (i = 0;i < size;i++){
		if (arr[i] == 0 )
		{
			continue;
		}
		for(j =0; j < size;j++)
		{
			if (int_cmp(arr[i],arr[j]))
			{
				arr[j]=0;
			}
		}
	}
}

int main(int argc , char *argv[])
{
	int numList[25] = {12,34,435,5,4,6,0,8,8,5,4,2,43,4,6,7,3,8,9,5,43,3,2,487,45};
	int len = sizeof(numList)/sizeof(int);
	


	
	return 0;
}
