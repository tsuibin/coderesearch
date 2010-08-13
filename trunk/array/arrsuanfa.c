#include <stdio.h> 
#include <stdlib.h> 


int main(int argc , char *argv[]) 
{
	int arr[3][3][3] = 
	{
		{
			{1,2,3},
			{4,5,6},
			{7,8,9}
		},

		{
			{10,11,12},
			{13,14,15},
			{16,17,18}
		},

		{
			{19,20,21},
			{22,23,24},
			{25,26,27}
		},
	};
	int *p;
	p = (int *)&arr;
	printf("sizeof %d \n",sizeof(arr)); 
	/*
	printf("arr+1 = %d \n",*(p+1));
	printf("&arr = %d \n",arr);
	printf("&arr001 = %d \n",&arr[0][0][1]);
	printf("arr001 = %d \n",arr[0][0][1]);
	*/
/*
	printf("arr010 = %d \n",*(arr + 0 + 0 + 1*3));
	printf("arr100 = %d \n",*(arr + 0 + 0 + 1*3*3));
	printf("arr110 = %d \n",*(arr + 1*3*3 + 1*3 + 0));
*/
	printf("arr010 = %d \n",*(p + 0 + 1*3 + 0));
	printf("arr100 = %d \n",*(p + 1*3*3 + 0 + 0));
	printf("arr110 = %d \n",*(p + 1*3*3 + 1*3 + 0));
	printf("arr210 = %d \n",*(p + 2*3*3 + 1*3 + 0));
	printf("arr001 = %d \n",*(p + 0*3*3 + 0*3 + 1));


	return 0;
}
