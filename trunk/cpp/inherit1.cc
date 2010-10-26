#include <iostream> 

using namespace std;

class Base{
	public:
		Base(){
			cout << "我是基础类" <<endl;
		}
		~Base(){
			cout << "基础类析构"<<endl;
		}
		string m_name;
		int age;
		void run()
		{
			cout << "我在跑步" << endl;
		}

		void wear(string str)
		{
			cout <<"我穿"<< str <<endl;
		}

		void setName(string _name)
		{
			this->m_name = _name;
		}

		void showName()
		{
			cout <<  this->m_name <<endl;
		}
};

class Boy : protected Base{
	public:
		Boy(){
			cout <<"男孩出生了"<<endl;
		}
		~Boy(){
			cout<<"男孩消失了"<<endl;
		}
		void showInfo(){

			this->setName("wzk");
			this->showName();
			this->run();
			this->wear("裤子");
		}
};

class Girl : public Base{
	public:
		Girl(){
			cout << "女孩出生了"<<endl;
		}
		~Girl(){
			cout << "女孩不见了"<<endl;
		}
};


int main(int argc , char *argv[]) 
{
	Boy wzk;
	wzk.showInfo();
	/*wzk.setName("wzk");
	wzk.showName();
	wzk.run();
	wzk.wear("裤子");*/




	Girl lyx;
	lyx.setName("lyx");
	lyx.showName();
	lyx.run();
	lyx.wear("裙子");


	return 0; 
}
