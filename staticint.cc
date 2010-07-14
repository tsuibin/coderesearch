#include <iostream>
using namespace std;
#include "static.h"
void func1()
{
	static int i =0;
	i++;
	cout << "i = " << i << endl;
}

void func2()
{
	static int z;
	z++;
	cout << "z = " << z << endl;
}

void func3()
{
	j++;
	cout << "j = " << j << endl;
}
int main()
{
		int *p=NULL;
		func1();
		func1();
		func1();
		func2();
		func2();
		func3();
		func3();
		

}

