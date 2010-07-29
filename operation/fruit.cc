#include <iostream>

using namespace std;

class Fruit{
	public:
	Fruit()
	{
		cout << "create!" << endl;
	}


	private:
	int weight;
};

int Fruit::operator+(Fruit &f)
{
	return weight+f.weight;
}

int main(int argc , char *argv[])	
{
	Fruit aaa;
	aaa.weight = 10;

	(aaa + bbb) 
	cout << aaa.weight << endl;
	return 0;
}

