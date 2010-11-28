#include <iostream> 

using namespace std; 
#include <time.h>

int main(int argc ,char *argv[]) 
{
	time_t t = time(NULL);
	tm* p = localtime(&t);
	char buf[100];

	strftime(buf,100,"%F 星期%w  %T",p);

	cout << buf <<endl;

}
