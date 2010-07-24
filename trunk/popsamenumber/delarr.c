#include <stdio.h>
#include <stdlib.h>

int find_array(int *a,int i)
{
	int tmp;

	tmp = a[i];
	i--;

	for(;i >= 0;i--)
	{
		if(a[i] == tmp)
		{
			return 1;
		}
	}

	return 0;
}

void delete_array(int *a,int i,int len)
{
	if (i == (len-1))
	{
		return;
	}

	for (;i < len;i++)
	{
		a[i] = a[i + 1];
	}
}

int main(int argc , char *argv[])
{
	int a[] = {0,6,7,8,6,1,5,7,8,2};
	int i;
	int len;
	int ret = 0;

	len = sizeof(a)/sizeof(int); // a表示占用的内存空间
	
	for (i = 0; i < len;i++)
	{
		ret = find_array(a,i); //遇到了一个 返回1 没有0
		if (ret == 1)
		{
			delete_array(a,i,len);//a 数组 i 位置 len 长度
			len--;
			i--; //这里要讲清楚 这个是为了检查刚刚赋值过来的数值 与前面的数值是否有重复
		}
	}

	for (i = 0;i < len;i++)
	{
		printf("%d\n",a[i]); 
	}

	return 0;

}
