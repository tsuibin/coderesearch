#include <iostream> 
using namespace std; 
#include <unistd.h>

int main(int argc ,char *argv[]) 
{
	char name[256];
	int res=gethostname(name,256);
	if(res < 0)
		cout << "Error!" << endl;
	else
		cout << name << endl;
}
