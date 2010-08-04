#include <iostream>
using namespace std;

class A{
	const int data;
	public:
	A(int d=0):data(d){}
	virtual void show() const{
		cout << "data=" << data <<endl;
	}
	void set(int d){
		const_cast<int&>(data) =d;
	}
};
class B : public A{
	public:
		void sayhello(){
			cout << "welcome to beijing!" << endl;
		}
};
int main(int argc,char* argv[]){
	static_cast<A>(100).show();
	A obj(200);
	obj.show();
	obj.set(300);
	obj.show();
	int n=1;
	typedef unsigned int UI;
	typedef unsigned char UC;
	UC* p=NULL;
	//在任意的两个类型之间转换,这个操作比较危险!!
	p=reinterpret_cast<UC*>(&n);//可以查看一个整形变量在内存中每一个字节放的内容
	for(int i = 0;i<4;i++){
		cout << (int)*p++ << ' ';

	}
	cout << endl;
	
	A oa;
	B ob;
	A* pa=&oa;
	B* pb=NULL;
	//把父类地址转换为子类地址
	pb = dynamic_cast<B*>(pa);
	cout << "pb =" << pb <<endl;//pb是0 说明pa不是一个B类对象，通过转化成功与否来判断这个对象是否是这个类型的
	pa = &ob;//这里的pa 始终是一个 A*
	pb = dynamic_cast<B*>(pa);//pa 有可能指向A类对象，也有可能指向B类对象,就是为了区分这种情况
	//pb = (B*)pa;//这样也可以转换为B类型，但是这是不安全的，如果pa不是B类型的，则会出错
	//动态类型转换会先判断是不是B类型，如果是则转换，如果不是则返回NULL
	//强制类型转换是不安全的
	//动态类型转换是安全的，一旦成功，你就可以使用
	cout << "pb =" << pb <<endl;
}
