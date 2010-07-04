#include <iostream>
using namespace std;

class Parent{
	int mp;
public:
	Parent():mp(0){
		cout << "Parent()" << endl;
	}
	Parent(int d):mp(d){
		cout << "Parent(" << d << ")" << endl;
	}
	~Parent(){
		cout << "~Parent()" << endl;
	}
};
class Child : public Parent{
	double mc;
public:
	Child():mc(0.0){
		cout << "Child()" << endl;
	}
	Child(double d):mc(d),Parent(50){
		cout << "Child(" << d << ")" << endl;
	}
	~Child(){
		cout << "~Child()" << endl;
	}
};

int main()
{
	//Parent pa(1);
	Child c1;
	Child c2(100);
}
