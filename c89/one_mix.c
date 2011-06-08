#include <stdio.h>
#define PI 3.1415926

int main(int argc, char* argv[])
{
	int k;
	printf("Hello World\n");
	printf("%d\t%x\t%f\n",7,7,7.0);
	printf("%d\t%x\t%f\n",100,100,100.0);
	printf("%d\t%x\t%f\n",27,27,27.0);
	printf("%f\n",17.2365);
	printf("%s\n","%d");
	printf("\'\'\n");
	printf("\"\"\n");
	printf("%d\n",sizeof(int));
	printf("%d\n",sizeof(char));
	printf("%d\n",sizeof(float));
	printf("%d\n",sizeof(short));
	printf("%d\n",sizeof(long));
	printf("%d\n",sizeof(long long));
	printf("%d\n",k*k);
	printf("%d\n",25/2);
	printf("%f\n",(float)25/2);

	if(15%4 == 15/4)
		printf("equal\n");
	else
		printf("not equal\n");//15%4的值为3，15/4的值为3.75，默认为整形数据即为3  两者相等 所以输出equal

	int j,count1,count2;//判断数组里的奇偶数个数
	count1 = count2 =0;
	int str[10]={0,1,2,3,4,5,6,7,8,9};
	for(j = 0;j < 10;j++)
	{
		if(str[j]%2 == 0)
			count1++;
		else
			count2++;
	}
	printf("str数组中的偶数有%d个\n",count1);
	printf("str数组中的奇数有%d个\n",count2);

	printf("%f\n",PI);//使用预定义 #define PI 3.1415926 使用 %f 打印
	int r = 10;
	printf("半径为10的圆的周长为%f\n",2*PI*r);
	printf("半径为10的圆的面积为%f\n",PI*r*r);//计算r=10的圆的周长和面积

	char c ='k';//4.字符型变量练习
	printf("%c\n",c);
	printf("c的相应大写字符为%c\n",c-32);
	int i = 49;
	printf("%c\t%d\n",i,i);
	int l;
	int net[]={119,97,110,103,0,108,101,105,46,49,57,56,50,64,97,98,99,46,99,111,109};
	for(l = 0;l<21;l++)
		printf("%c",net[l]);
	printf("\n");

	return 0;
}
