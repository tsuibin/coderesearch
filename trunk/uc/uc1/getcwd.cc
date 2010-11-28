#include <iostream> 
#include <stdlib.h> 
#include <unistd.h>
using namespace std; 

int main(int argc ,char *argv[]) 
{
	char buf[256] ="(unkonw)";

	cout << getcwd(buf, 256) << endl;

	cout << buf << endl;

}
