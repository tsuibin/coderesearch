#include <iostream>

using namespace std;

class Fruit{
	public:
	Fruit()
	{
		cout << "create!" << endl;
	}

	int operator+(Fruit &f);
	int weight;
};

int Fruit::operator+(Fruit &f)
{
	return this->weight+f.weight;
}

int main(int argc , char *argv[])	
{
	Fruit aaa;
	Fruit bbb;
	aaa.weight = 10;

	aaa.weight = (aaa + bbb); 
	cout << aaa.weight << endl;
	return 0;
}

