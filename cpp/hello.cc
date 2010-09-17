#include <iostream>

using namespace std;

class A
{
	public:
	A()
	{
		cout << "hello world!" << endl;		
	}
	void hello();
	~A()
	{
	
	}

};
void A::hello()
{
	cout << "hello world 21" << endl;
}

int main(int argc, char *argv[])
{
	A c;
	c.hello();

	return 0;
}
