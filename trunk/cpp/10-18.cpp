#include <iostream.h>
#include <string.h>
class boy;      //��Ϊ��Ԫ����prt()����girl��boy������Ķ��󣬶�boy
//Ҫ�ں����������������ǰ���������Ա�ʹ�ø���Ķ���
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
	friend  girl;               //������girlΪ��boy����Ԫ��
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
