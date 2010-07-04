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
	//const 表示他不会修改当前对象的数据成员
	//这时候编译器就放心了
	void show() const{
		//data++;//ERROR
		cout << "DATA=" << data << endl;
	}
	void show(){
		cout << "data=" << data << endl;
	}
};

int main()
{
	A a1(1);
	const A a2(2);
	a1.show();//优先调用普通函数
	a2.show();//常量对象不能调用普通成员函数
	//因为普通成员函数有可能修改当前对象的数据成员
	
}
