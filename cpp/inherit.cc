#include <iostream> 
#include <string.h> 

using namespace std;

class Parent{

	public:
		Parent(){
			cout << "爸爸诞生了!" <<endl;
		}
		~Parent(){
			cout << "爸爸消失了!"<<endl;
		}
		string name;
		int age;
		void eat()
		{
			cout << "我在吃鱼!" << endl;		
		}
		void walk()
		{
			cout << "我在公园散步！" <<endl;
		}
};
class B
{
	public:
		B(){
			cout << "我是B类" << endl;
		}

		~B(){}

		void show()
		{
			cout << "B" <<endl;
		}

};
class Son : public Parent , public B {

	public:
		Son(){
			cout << "儿子华丽丽的出生了"<<endl;
		}
		~Son(){
			cout <<"儿子跑丢了！"<<endl;
		}
		void play(){
			cout <<"儿子在玩加肥猫！"<<endl;
		}

};


int main(int argc , char *argv[]) 
{
	Son huangbing;
	return 0; 
}
