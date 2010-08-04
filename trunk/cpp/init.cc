#include <iostream>
using namespace std;

class A{
	int i;
	int j;
	int k;
	public:
	//A(int t):k(t),j(k),i(j){}
	A(int t):k(j),j(i),i(t){}
	A(){}
	void show()
	{
		cout << "i=" << i << endl;
		cout << "j=" << j << endl;
		cout << "k=" << k << endl;
	}
};
int main(int argc,char* argv[]){
	A a(1);
	a.show();

}
