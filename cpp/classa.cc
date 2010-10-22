#include <iostream>

using namespace std;
class A
{
public:
	const int t;
	A():t(10){}
	~A(){}
};


int main(int argc, char *argv[])
{
	A first;
	cout << first.t << endl;
	const_cast<int&>(first.t) = 200;
	
	cout << first.t << endl;
	
	return 0;
}

