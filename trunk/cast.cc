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
	p=reinterpret_cast<UC*>(&n);//可以查看一个整形变量在内存中每一个字节放的内容
	for(int i = 0;i<4;i++){
		cout << (int)*p++ << ' ';

	}
	cout << endl;
	
	A oa;
	B ob;
	A* pa=&oa;
	B* pb=NULL;
	pb = dynamic_cast<B*>(pa);
	cout << "pb =" << pb <<endl;
}
