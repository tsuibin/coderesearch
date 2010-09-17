#include <iostream>
using namespace std;
class A{
public:
	A():t(10)
	{

	}
	~A(){ }

	const int t;
};

int main(int argc,char* argv[]){
	
	
	
	const int n=100;
	const_cast<int&>(n) = 200;
	cout << "n=" << n << endl;
	cout << "n=" << n << endl;
	cout << "n=" << n << endl;
	cout << "n=" << n << endl;
	const int* p=&n;
	cout << "*p=" << *p << endl;
}
