#include <iostream>
using namespace std;

class A{
	int data;
public:
	A():data(0){
		cout << "A()" << endl;
	}
	A(int d):data(d){
		cout << "A(" << d << ")" << endl;
	}
	~A(){
		cout << "~A()" << data << endl;
	}
	void show(){
		cout << "data=" << data << endl;
	}
};

int main()
{
	A a1(1);
	A(2);
	A(3).show();
	cout << "===" << endl;
	A a4;
	a4 = A(4);//int(2.5) 强制类型转换
	(A)5;//依赖于构造函数
	a4=40;//创建并且释放了一个无名对象 a4 = (A)40; or a4 = A(40);
	// double d = 10; d = (double)10.0;
}
