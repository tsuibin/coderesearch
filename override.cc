#include <iostream>
#include <string.h>
using namespace std;

class Animal{
private:
	char name[20];
protected:
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
	void show() {
		cout << "父类的Show" << endl;
	}
};
//
//public 继承方式 公开继承 原来是什么样 现在还是
//private 私有继承 继承过来的东西对外不开放

//class Bird : private Animal{
class Bird : public Animal{
	double weight;
public:
	void setWeight(double weight) {
		this->weight = weight;
	}
	double getWeight() {
		return weight;
	}
	void fly() {
		cout << "我终于翱翔用心凝望不害怕" << endl;
	}
	void visit_parent() {
		//cout << "name=" << name << endl;//ERROR
		cout << getName() <<endl;
		cout << age <<endl;
	}
	void show() {
		cout << getName() << ':'<< getAge() << ',' << weight << endl;
	}

};

int main()
{
	Animal a1;
	Bird b1;
	b1.setName((char*)("鸽子"));
	b1.setAge(33);
	b1.setWeight(100);
	b1.show();//子类一旦用同名函数，则会覆盖父类函数
	b1.Animal::show();
}
