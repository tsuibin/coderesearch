#include <iostream>
#include <string.h>
using namespace std;

class Animal{
	char name[20];
	int age;
public:
	void setName(char *name) {
		strcpy(this->name, name);
	}
	void setAge(int age) {
		this->age = age;
	}
	char* getName() {
		return name;
	}
	int getAge() {
		return age;
	}
};

int main()
{
	Animal a1,a2;
	a1.setName("团团");
	a1.setAge(300);
	a2.setName("圆圆");
	a2.setAge(400);
	cout << a1.getName() << ':' << a1.getAge() <<endl;
	cout << a2.getName() << ':' << a2.getAge() <<endl;
}
