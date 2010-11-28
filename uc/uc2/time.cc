#include <iostream> 
using namespace std; 
#include <time.h>

int main(int argc ,char *argv[]) 
{
	time_t t1,t2;

	t1 = time(&t2);

	cout << "t1" << t1 <<endl;

	cout << "t2" << t2 <<endl;

	int s=t1%60;
	int m=(t1/60)%60;
	int tz=8;
	int h=(t1/3600+tz)%24;

	cout <<"time :" << h <<':'<< m <<":"<< s <<endl;
}
