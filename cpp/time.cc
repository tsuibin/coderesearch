#include <iostream>
using namespace std;
#include <ctime>

int main()
{
	time_t t;
	t=time(NULL);
	while(time(NULL)==t) cout << '\r'<<t << flush;
}
