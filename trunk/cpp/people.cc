#include <iostream> 
#include <string.h>

using namespace std;

class People {

public:
	People(){};
	~People(){};

	void setName(string _name)
	{
		this->m_name = _name;
	}

	void setAge(int _age)
	{
		this->m_age = _age;
	}

	void setSchool(string _school)
	{
		this->m_school = _school;
	}

	string getName()
	{
		return this->m_name;
	}

	int getAge()
	{
		return ++this->m_age;
	}

	string getSchool()
	{
		return this->m_school;
	}

private:
	string m_name;
	int m_age;
	string m_school;

};

int main(int argc , char *argv[]) 
{
	People *p1;
	p1 = new People;
	p1->setName("Tsuibin");
	p1->setAge(26);
	p1->setSchool("江西理工大学应用科学学院");

	cout	<<	p1->getName()  
		<<	p1->getAge()
		<<	p1->getSchool()
		<<	endl;

	return 0; 

}
