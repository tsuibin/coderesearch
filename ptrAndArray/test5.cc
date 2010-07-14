#include <iostream>
#include <stdio.h>
using namespace std;

void func(int (*p)[3])
{
		printf("%d",p[0][0]);
}
int main()
{
		int arr[3][3]={0};
		func(arr);
		return 0;
}
