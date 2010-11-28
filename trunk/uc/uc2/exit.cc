#include <iostream> 
using namespace std; 
#include <stdlib.h> 
void func();
void show()
{
	cout <<"exiting..."<<endl;
	atexit(func);
}
void func(){
	cout <<"do something~" <<endl;
}
class A{
	public:
	A(){cout << "A()"<<endl;};
	~A(){cout << "~A()"<<endl;};
};
A gobj;

int main(int argc ,char *argv[])
{
	A gobj;
	int res = atexit(show);
	atexit(func);
//	exit(0); //不会析构局部对象！！！
	//_exit(-1);//不会析构
	cout << res <<endl;
	//abort(); //不会析构
	//terminate();//不会析构 
}
