#include <stdio.h> 
#include <stdlib.h> 
#define N 6

int main(int argc , char *argv[]) 
{
	int a[N]={1,2,0,1,3};
	int i,j,reallen = N;
	int k;
	
	for(i = 0;i < reallen;i++)
	{
		printf("%d ",a[i]); 
	}
	printf("\n"); 

	for (i = 0;i < reallen;i++)
	{
		for (j = k = i+1 ; j < reallen;j++)
		{
			if (a[i] != a[j])
			{
				//a[j] = 0;
				printf("a[%d] != a[%d]\n",i,j); 
				printf("a[%d] = a[%d] \n",k,j); 
				printf("\n"); 
				a[k++] = a[j];
			}
		}
	}
	reallen = k;

	for (i = 0;i < reallen;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n"); 

	return 0;
}
