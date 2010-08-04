#include <iostream>
using namespace std;
#include <ctime>
class Clock{
	int h;
	int m;
	int s;
public:
	void set(int hour, int min, int sec);
	void tick();
	void show();
	void run();
};

void Clock::set(int ho, int mi,int se)
{
	h = ho;
	m = mi;
	s = se;
}

void Clock::tick()
{
	//long == time_t
	time_t t=time(NULL);
	while(time(NULL)==t);
	if(--s<0){
		s = 59;
		if(--m<0){
			m = 59;
			--h;
		}
	}
}

void Clock::show()
{
	cout << '\r' ;
	if(h<10) cout << 0;
	cout << h << ':';
	if(m<10) cout << 0;
	cout << m << ':';
	if(s<10) cout << 0;
	cout << s << flush;
}

void Clock::run()
{
	//while(h|m|s)
	//while(h||m||s)
	while(h!=0||m!=0||s!=0){
		tick();
		show();
	}
	cout << "time out" << endl;
}

int main()
{
	Clock c;
	c.set(0,1,0);
	c.run();
}

