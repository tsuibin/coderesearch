#include <iostream>
using namespace std;
#include <string>
/*
   class Animal{
   string name;
   public:
   virtual void eat(){
   cout<<"动物吃食物 " << endl;
   }
   virtual void sleep(){
   cout<<"动物休息" << endl;
   }
   virtual void shout(){
   cout<<"动物叫" << endl;
   }
   };
 */

//有纯虚函数的类叫做抽象类
//抽象类不允许直接创建对象
//只能用它来指向子类对象或者引用子类对象
//要向识别类型一定要有虚函数
//强制类型转换
//(类型)数据
//类型(数据)
//static_cast 静态类型转换 数值类型之间
//有类型的指针与void * 之间
//xxxx_cast 所有的类型转换格式
//xxxx_cast <要转换的类型>(要转换的数据) 不会改变原来的数据
//几乎所有的运算符都不会改变原来的数据 除了++ -- =
//const_cast<class&>(data) 把这个常量转换成变量 然后修改
//const_cast<class&>(data) = 1; 把常量当成变量用一次;
//volatile 不稳定的变量 不知道谁就会把它去改了 可以转换成普通变量来用用
// auto 自动
//register 寄存器 cpu随身携带的小存储空间
//register int n;长度有限
//reinterpret_cast 重新解释内存的转换 整数 浮点数 最危险的转换 一般用在不同类型指针之间转换(高手的游戏)
// Y* p;
//reinterpret_cast(A*)(p);
//动态类型转换 父类<->子类 人->司机? 司机->人
//dynamic_cast (向下转换时 把关！) 父类转换为子类的时候把关用的
//父类对象或父类指针 
//dynamic_cast<子类*>(父类地址或指针)//要求父类至少有一个虚函数 如果是子类对象返回一个地址 如果转换失败 返回NULL


class Animal{
		string name;
		public:
		virtual void eat()=0;//纯虚函数
		virtual void sleep()=0;//等于0 告诉编译器保证这个函数一定不会被调用
		virtual void shout()=0;//
};


class Cat : public Animal{
		public:
				void eat(){
						cout<<"猫吃猫粮" << endl;
				}
				void sleep(){
						cout << "猫在床上睡觉"<<endl;
				}
				void shout(){
						cout << "猫喵喵叫" << endl;
				}
};
class Dog: public Animal{
		public:
				void eat(){
						cout << "狗啃骨头" << endl;
				}
				void sleep(){
						cout << "狗在狗窝睡觉" << endl;
				}
				void shout(){
						cout << "旺财旺财" << endl;
				}
};
class JiaFei : public Cat{
		public:
				void eat(){
						cout<<"加肥爱吃意大利面"<<endl;
				}
				void sleep(){
						cout<<"加肥在沙发上睡觉"<<endl;
				}
				void shout(){
						cout<<"加肥说下午好" << endl;
				}
};
class Player{
		string name;
		public:
		Player(string n):name(n){}
		void play(Animal* p){
				cout << name << ':' << endl;
				p->eat();
				p->sleep();
				p->shout();
		}
		void play(Animal& p){
				cout << name << ':' << endl;
				p.eat();
				p.sleep();
				p.shout();
		}
};
int main()
{
		//cout << sizeof(Animal) << endl;
		Cat c;
		Dog d;
		JiaFei j;
		Player p1("Dooby");
		Player p2("Rooby");
		p1.play(&c);
		p2.play(&d);
		p2.play(j);
		system("pause");
}
