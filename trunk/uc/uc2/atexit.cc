#include <iostream> 
using namespace std; 
#include <stdlib.h> 

void show()
{
	cout <<"exiting..."<<endl;
}
void func(){
	cout <<"do something~" <<endl;
}

int main(int argc ,char *argv[])
{
	int res = atexit(show);
	atexit(func);
	exit(0);
	//_exit(-1);
	cout << res <<endl;
}
