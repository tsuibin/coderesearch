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

void Clock::set(int hour, int min, int sec)
{
	h=hour;
	m=min;
	s=sec;
}
void Clock::tick()
{
	time_t t = time(NULL);
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
	cout << '\r';
	if(h<10) cout << 0;
	cout << h << ':';
	if(m<10) cout << 0;
	cout << m << ':';
	if(s<10) cout << 0;
	cout << s <<flush;
}
void Clock::run()
{
	while(h|m|s){
		tick();
		show();
	}
	cout << '\r';
	cout << "time out!"<<endl;
}

int main()
{
	Clock c;
	c.set(0,2,0);
	c.run();
}
