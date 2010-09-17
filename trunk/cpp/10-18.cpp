#include <iostream.h>
#include <string.h>
class boy;      //因为友元函数prt()带了girl和boy两个类的对象，而boy
//要在后面才声明，所以提前声明它，以便使用该类的对象
class girl
{
	char *name;
	int age;
                       
public:
    girl(char *n,int a)
    {
		name=new char[strlen(n)+1];
		strcpy(name,n);
		age=a;
    } 
    void prt(boy &);   //
	~girl()
	{  
		delete name; 
	}
};
class boy
{
	char *name;
	int age;    
	friend  girl;               //声明类girl为类boy的友元类
public:
    boy(char *n,int a)
    {
		name=new char[strlen(n)+1];
		strcpy(name,n);
		age=a;
    } 
	~boy()
	{ 
		delete name; 
	}
};
void girl::prt (boy &b)
{
	cout<<"girl\'s name:"<<name<<"      age:"<<age<<"\n";
	cout<<"boy\'s name:"<<b.name<<"      age:"<<b.age<<"\n";
}
int main()
{
	girl g("Stacy",15);
	boy b1("Jim",16);
	g.prt(b1);  
	
	return 0;         
}
